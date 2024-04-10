#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int n;
string s, t;
bool mark[MAXN], mark2[MAXN];
int ans[MAXN], sz;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;	n = t.size();
	for (int i = 0; i < n && s[i] == t[i]; i++)
		mark[i] = 1;
	for (int i = n - 1; ~i && t[i] == s[i + 1]; i--)
		mark2[i] = 1;
	
	for (int i = 0; i <= n; i++)
		if ((!i || mark[i - 1]) && (i == n || mark2[i]))	ans[sz++] = i + 1;
	cout << sz << "\n";
	for (int i = 0; i < sz; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}