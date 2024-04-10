#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, f[MAXN], g[MAXN], h[MAXN], mp[MAXN];
bool mark[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> f[i], f[i]--, mark[f[i]] = 1;
	int cnt = 0;
	for (int i = 0; i < n; i++) if (mark[i]) cnt++;
	int cnt2 = 0;
	for (int i = 0; i < n; i++) if (i == f[i]) cnt2++;
	if (cnt ^ cnt2){
		cout << "-1\n";
		return 0;
	}
	cout << cnt << "\n";

	
	int cur = 0;
	for (int i = 0; i < n; i++)
		if (i == f[i]) mp[i] = cur, h[cur] = i, cur++;


	for (int i = 0; i < n; i++)
		g[i] = mp[f[i]];

	for (int i = 0; i < n; i++) cout << g[i]+1 << " ";
	cout << "\n";
	for (int i = 0; i < cnt; i++) cout << h[i]+1 << " ";
	cout << "\n";
	return 0;
}