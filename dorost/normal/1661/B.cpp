/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 32769;
int a[N], dis[N];
vector <int> g[N];

void bfs(int s) {
	for (int i = 0; i < N; i++)
		dis[i] = -1;
	queue <int> q;
	dis[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto y : g[x]) {
			if (dis[y] == -1) {
				dis[y] = dis[x] + 1;
				q.push(y);
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	for (int i = 0; i < 32768; i++) {
		g[i * 2 % 32768].push_back(i);
		g[(i + 1) % 32768].push_back(i);
	}
	bfs(0);
	int ans = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cout << dis[x] << ' ';
	}
}