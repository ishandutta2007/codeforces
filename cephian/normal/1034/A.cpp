#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;

map<int, vector<int>> seen;
const int N = 1.5 * 1e7 + 5;
int f[N];

int main() {
	fio;
	for(int i = 1; i < N; ++i)
		f[i] = i;
	for(int i = 2; i < N; ++i) {
		if(f[i] != i) continue;
		for(ll j = 1LL * i * i; j < N; j += i)
			f[j] = i;
	}
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		map<int, int> m;
		while(a != 1) {
			++m[f[a]];
			a = a/f[a];
		}
		for(auto x : m) {
			seen[x.first].resize(max((int)seen[x.first].size(), x.second+1));
			++seen[x.first][x.second];
		}
	}

	int best = n;

	for(auto x : seen) {
		int sm = n;
		for(int y : x.second)
			sm -= y;
		x.second[0] = sm;

		int lo = 0;
		while(x.second[lo] == 0)
			++lo;
		if((int)x.second.size() > lo+1)
			best = min(best, x.second[lo]);
	}
	if(best == n) cout << "-1\n";
	else cout << best << "\n";
}