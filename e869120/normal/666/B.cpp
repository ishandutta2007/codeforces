#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
int dist[3004], n, m, a, b, c[3003][3003]; vector<int>x[3003]; vector<pair<int, int>>p[3003], q[3003];
int main() {
	cin >> n >> m; for (int i = 0; i < m; i++) { cin >> a >> b; x[a].push_back(b); }
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)dist[j] = 499999999;
		queue<int>Q; Q.push(i); dist[i] = 0;
		while (!Q.empty()) {
			int a1 = Q.front(); Q.pop();
			for (int j = 0; j < x[a1].size(); j++) {
				if (dist[x[a1][j]] > dist[a1] + 1) {
					Q.push(x[a1][j]); dist[x[a1][j]] = dist[a1] + 1;
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			if (dist[j] == 499999999)dist[j] *= -1;
			if (i != j) {
				p[i].push_back(make_pair(-dist[j], j));
				q[j].push_back(make_pair(-dist[j], i));
			}
			c[i][j] = dist[j];
		}
	}
	for (int i = 1; i <= n; i++) {
		sort(p[i].begin(), p[i].end());
		sort(q[i].begin(), q[i].end());
		for (int j = 0; j < p[i].size(); j++)p[i][j].first *= -1;
		for (int j = 0; j < q[i].size(); j++)q[i][j].first *= -1;
	}
	int maxn = 0; vector<int>maxid = { 0,0,0,0 };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || c[i][j] == 499999999)continue;
			vector<pair<int, int>>r, s; int T1 = 0, T2 = 0;
			for (int k = 0; k < n; k++) {
				if (q[i][k].second != j) { r.push_back(q[i][k]); T1++; }
				if (T1 == 2)break;
			}
			for (int k = 0; k < n; k++) {
				if (p[j][k].second != i) { s.push_back(p[j][k]); T2++; }
				if (T2 == 2)break;
			}
			if (r[0].second != s[0].second) {
				int sum = c[i][j] + r[0].first + s[0].first;
				if (maxn < sum) {
					maxid = vector<int>{ r[0].second,i,j,s[0].second }; maxn = sum; 
				}
			}
			else if ((r[0].first - r[1].first) < (s[0].first - s[1].first)) {
				int sum = c[i][j] + r[1].first + s[0].first;
				if (maxn < sum) {
					maxid = vector<int>{ r[1].second,i,j,s[0].second }; maxn = sum;
				}
			}
			else {
				int sum = c[i][j] + r[0].first + s[1].first;
				if (maxn < sum) {
					maxid = vector<int>{ r[0].second,i,j,s[1].second }; maxn = sum;
				}
			}
		}
	}
	cout << maxid[0] << ' ' << maxid[1] << ' ' << maxid[2] << ' ' << maxid[3] << endl;
	return 0;
}