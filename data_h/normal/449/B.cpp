#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int N = 111111;
const long long INF = (1LL << 60);
vector<pair<int, int> > e[N];

priority_queue<pair<long long, int> > q;
int n, m, k;
bool visit[N];
long long dist[N];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[a].push_back(make_pair(b, c));
		e[b].push_back(make_pair(a, c));
	}
	q.push(make_pair(0, 1));
	
	for(int i = 1; i <= k; i++) {
		int s, y;
		scanf("%d %d", &s, &y);
		q.push(make_pair(-y, -s));
	}

	for(int i = 1; i <= n; i++) {
		visit[i] = false;
		dist[i] = INF;
	}
	
	dist[1] = 0;
	int ans = 0;
	while(!q.empty()) {
		pair<long long, int> tmp = q.top();
		q.pop();
		int x = tmp.second;
		if (x < 0) {
			x = -x;
			if (visit[x]) {
				ans++;
				continue;
			}
		}
		if (visit[x])
			continue;
		dist[x] = -tmp.first;
		visit[x] = 1;
		
		for(int i = 0; i < (int)e[x].size(); i++) {
			int y = e[x][i].first;
			int cost = e[x][i].second;
			q.push(make_pair(-(dist[x] + cost), y));
		}
	}
	cout << ans << endl;
	return 0;
}