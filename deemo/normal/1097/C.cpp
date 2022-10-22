#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e6 + 10;

int n, sm[MAXN];
set<pii> st[2][MAXN*2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		string s; cin >> s;
		int mn = 1e9, mx = -1e9;
		for (char c:s) {
			if (c == '(')
				sm[i]++;
			else
				sm[i]--;

			mn = min(mn, sm[i]);
			mx = max(mx, sm[i]);
		}
		if (mn < 0)
			st[0][sm[i] + MAXN].insert({mn, i});
		else
			st[1][sm[i] + MAXN].insert({sm[i], i});
	}

	int ans = 0;
	for (int i = 0; i <= MAXN; i++)
		while (st[0][i].size()){
			int x = st[0][i].begin()->F;
			st[0][i].erase(st[0][i].begin());
			int y = i - MAXN;
			y = -y;
			y += MAXN;
			if (st[1][y].size() && st[1][y].rbegin()->F >= -x){
				ans++;
				st[1][y].erase(*st[1][y].rbegin());
			}
		}
	ans += st[1][MAXN].size()/2;

	cout << ans << "\n";
	return 0;
}