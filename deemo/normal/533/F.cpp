#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 2e5 + 100;

int n, m, sz, ans[MAXN], mk[MAXN], ss[MAXN], f[MAXN];
string s, t;

void ff(int a, int b, int type = 0){
	if (type == 0)	memset(mk, 0, sizeof(mk));
	int k = 0;
	for (int i = 1; i < m; i++){
		while (k && (t[i] != t[k] && (t[i] - 'a' == b || t[k] - 'a' == b)))	k = f[k];
		if (t[i] == t[k] || (t[i] - 'a' != b && t[k] - 'a' != b))	k++;
		f[i + 1] = k;
	}
	k = 0;
	for (int i = 0; i < n; i++){
		while (k && (s[i] - 'a' == a ^ t[k] - 'a' == b))	k = f[k];
		if (!(s[i] - 'a' == a ^ t[k] - 'a' == b))	k++;
		if (k == m)	mk[i - m + 1]++, k = f[k];
	}
	if (type == 1)	return;
	ff(b, a, 1);
	for (int i = 0; i < n; i++)
		if (mk[i] == 2)	ss[i] |= (1<<a) | (1<<b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> s >> t;
	
	ff(1, 2);
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)	ff(i, j);
	for (int i = 0; i < n; i++)
		if ((ss[i] | ((1<<26) - 1)) == ss[i])	ans[sz++] = i + 1;
	cout << sz << "\n";
	for (int i = 0; i < sz; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return	0;
}