#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 2005;
int spend[N][N] = {};

char g[N][N];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		for(int j = 1; j <= n; ++j)
			g[i][j] = s[j-1];
	}
	for(int i = 0; i < N; ++i)
		spend[0][i] = spend[i][0] = 1e6;

	spend[0][1] = spend[1][0] = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			spend[i][j] = (g[i][j] != 'a') + min(spend[i-1][j], spend[i][j-1]);
		}
	}
	vector<pii> bests;
	int best_len = 0;
	for(int len = 1; len <= 2*n-1; ++len)  {
		bool found = false;
		////////
		for(int i = max(1, len+1-n); i <= min(len, n); ++i) {
			int j = len+1-i;
			if(spend[i][j] <= k) found = true;
		}
		if(!found) break;
		best_len = len;
	}

	set<pii> locs;
	////////
	for(int i = max(1, best_len+1-n); i <= min(best_len, n); ++i) {
		int j = best_len+1-i;
		if(spend[i][j] <= k) {
			locs.emplace(i, j);
		}
	}

	vector<char> str(best_len, 'a');
	if(best_len == 0) {
		locs.emplace(1, 1);
		str.push_back(g[1][1]);
		++best_len;
	}

	while((int)str.size() < 2*n-1) {
		best_len+=1;
		////////
		char best = 'z';
		set<pii> new_locs;
		for(int i = max(1, best_len+1-n); i <= min(best_len, n); ++i) {
			int j = best_len+1-i;
			if(g[i][j] > best) continue;
			pii p1(i-1, j);
			pii p2(i, j-1);
			if(locs.count(p1) || locs.count(p2)) {
				if(g[i][j] < best) {
					new_locs.clear();
					best = g[i][j];
				}
				new_locs.emplace(i, j);
			}
		}
		str.push_back(best);
		locs = new_locs;
	}

	for(char c : str)
		cout << c;
	cout << "\n";
}