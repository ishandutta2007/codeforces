#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 1e5+5;
set<int> follow[N];
int nxt[N] = {};
bool start[N] = {};

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int prev = 0;
		for(int j = 0; j < n; ++j) {
			int a;
			cin >> a;
			follow[prev].insert(a);
			prev = a;
		}
		follow[prev].insert(0);
	}
	fill(start, start+N, true);
	for(int i = 1; i <= n; ++i) {
		if(follow[i].size() == 1) {
			//int f = *follow[i].begin();
			nxt[i] = *follow[i].begin();
			start[*follow[i].begin()] = false;
		}
	}

	ll ways = 0;
	for(int i = 1; i <= n; ++i) {
		if(!start[i]) continue;
		ll l = 1;
		int j = i;
		while(nxt[j] != 0) {
			j = nxt[j];
			++l;
		}

		ways += l * (l-1) / 2 + l;
	}
	cout << ways << "\n";
}