#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e3 + 10;

int n, m;
string s[MAXN], t[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> s[i];
	for (int j = 0; j < m; j++)	cin >> t[j];
	sort(s, s + n);
	sort(t, t + m);
	
	int cur = 0;
	int c1 = 0;
	for (int i = 0; i < n; i++){
		while (cur < m && t[cur] < s[i])	cur++;
		if (cur == m || t[cur] != s[i])
			c1++;
	}
	int com = n - c1;
	int c2 = m - com;

	c1 += com+1>>1;
	c2 += com>>1;
	if (c1 > c2)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}