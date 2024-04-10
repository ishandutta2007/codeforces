#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
typedef double T;
const int nax = 1005;
int dist[nax][nax];
vector<int> w[nax];
T p_later[nax]; // p[v] - probability for city v in the second day
T p_dist_max[nax];
bool vis[nax];

void max_self(T & a, T b) {
	a = max(a, b);
}

T consider_tomorrow(int n, int g1, int dist1) {
	T best_tomorrow = 0;
	// we need complexity O(n * x)
	// where x denotes the number of v that |dist1-dist[g1][v]| <= 1
	for(int i = 1; i <= n; ++i) {
		p_later[i] = 0;
		vis[i] = false;
	}
	vector<int> interesting;
	for(int v = 1; v <= n; ++v) if(dist[g1][v] == dist1)
		for(int b : w[v]) {
			// Limak started in v with prob. 1/n
			// he then moved to b with prob. 1/degree[v]
			p_later[b] += (T) 1 / n / w[v].size();
			if(!vis[b]) {
				vis[b] = true;
				interesting.push_back(b);
			}
		}
	
	// interesting.size() <= x, where x is defined above (needed for complexity)
	for(int g2 = 1; g2 <= n; ++g2) {
		T local_sum = 0; // over situations with fixed g1, dist1, g2
		
		for(int b : interesting)
			max_self(p_dist_max[dist[g2][b]], p_later[b]);
		for(int b : interesting) {
			local_sum += p_dist_max[dist[g2][b]];
			p_dist_max[dist[g2][b]] = 0; // so it won't be calculated twice
		}
		max_self(best_tomorrow, local_sum);
	}
	return best_tomorrow;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i,1,n) FOR(j, 1, n) if(i != j)
		dist[i][j] = n + 1; // infinity
	FOR(i,1,m) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].push_back(b);
		w[b].push_back(a);
		dist[a][b] = dist[b][a] = 1;
	}
	// Floyd-Warshall
	FOR(b,1,n)FOR(a,1,n)FOR(c,1,n)
		dist[a][c] = min(dist[a][c], dist[a][b] + dist[b][c]);
	
	// g1 is the first guess
	T answer = 0;
	FOR(g1, 1, n) {
		T sum_over_dist1 = 0;
		FOR(dist1, 0, n) {
			int cnt_cities = 0;
			FOR(i, 1, n) if(dist[g1][i] == dist1)
				++cnt_cities;
			if(cnt_cities == 0) continue; // there are no cities within distance dist1
			
			// 1) consider guessing immediately
			T immediately = (T) 1 / n; // how much it counts towards the answer
			// 2) consider waiting for tomorrow
			T second_day = consider_tomorrow(n, g1, dist1);
			sum_over_dist1 += max(immediately, second_day);
		}
		max_self(answer, sum_over_dist1);
	}
	printf("%.12lf", (double) answer);
	return 0;
}