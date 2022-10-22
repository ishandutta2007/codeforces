#include<bits/stdc++.h>

using namespace std;

const int MAXN = 50 + 2;

int n, m;
string s[MAXN];
int mp[300], d[300][300];

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> s[i];

	for (int i = 'a'; i <= 'z'; i++)	mp[i] = 1;
	for (int i = '0'; i <= '9'; i++)	mp[i] = 2;

	memset(d, 10, sizeof(d));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			d[i][mp[s[i][j]]] = min(d[i][mp[s[i][j]]], min(j, m-j));
	int ans = 1e9;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int w = 0; w < n; w++)
				if (i != j && j != w && i != w)
					ans = min(ans, d[i][0] + d[j][1] + d[w][2]);
	
	cout << ans << endl;
	return 0;
}