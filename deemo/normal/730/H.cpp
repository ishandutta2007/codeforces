#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 5;

int n, m, sec[MAXN];
string s[MAXN], ans;
bool mark[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> s[i];
	int mn = 1e9, mx = -1;
	for (int i = 0; i < m; i++)
		cin >> sec[i], sec[i]--, mn = min(mn, (int)s[sec[i]].size()), mx = max(mx, (int)s[sec[i]].size()), mark[sec[i]] = 1;
	if (mn ^ mx){
		cout << "No\n";
		return 0;
	}
	for (int i = 0; i < mn; i++)	ans += '?';
	for (int i = 0; i < mn; i++){
		int a = 1e9, b = -1e9;
		for (int j = 0; j < m; j++)
			a = min(a, (int)s[sec[j]][i]), b = max(b, (int)s[sec[j]][i]);
		if (a == b)
			ans[i] = char(a);
	}
	for (int i = 0; i < n; i++)
		if (!mark[i] && mn == (int)s[i].size()){
			bool fail = 0;
			for (int w = 0; !fail && w < mn; w++)
				if (ans[w] != '?' && ans[w] != s[i][w])
					fail = 1;
			if (!fail){
				cout << "No\n";
				return 0;
			}
		}

	cout << "Yes\n";
	cout << ans << "\n";
	return 0;
}