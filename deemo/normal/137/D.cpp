#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 500 + 5;

int n, k, mn[MAXN][MAXN], d[MAXN][MAXN];
string s;

string get(string t){
	int l = 0, r = t.size();
	while (r - l > 1){
		if (t[l] != t[r - 1])
			t[l] = t[r - 1];
		l++, r--;
	}
	return t;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> k;	n = s.size();
	for (int l = n - 1; ~l; l--)
		for (int r = l + 2; r <= n; r++)
			if (s[l] != s[r - 1])
				mn[l][r] = 1 + mn[l + 1][r - 1];
			else
				mn[l][r] = mn[l + 1][r - 1];
	
	memset(d, 63, sizeof(d));
	for (int kk = 0; kk <= k; kk++)	d[n][kk] = 0;
	for (int l = n - 1; ~l; l--)
		for (int kk = 1; kk <= k; kk++)
			for (int r = l + 1; r <= n; r++)
				d[l][kk] = min(d[l][kk], mn[l][r] + d[r][kk - 1]);

	cout << d[0][k] << "\n";
	int cur = 0, ck = k;
	while (cur < n){
		if (cur)
			cout << "+";
		
		for (int r = cur + 1; r <= n; r++)
			if (d[cur][ck] == mn[cur][r] + d[r][ck - 1]){
				cout << get(s.substr(cur, r - cur));
				cur = r;
				ck--;
				break;
			}
	}
	cout << "\n";
	return 0;
}