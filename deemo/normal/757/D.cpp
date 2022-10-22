#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 20;
const int INF = 100;
const int MAXN = 75 + 2;
const int MOD = 1e9 + 7;

int n, ss[MAXN][MAXN], d[MAXN][1<<MX], nxt[MAXN];
string s;

int main(){
	cin >> n >> s;
	for (int l = 0; l < n; l++){
		int cur = 0;
		for (int r = l; r < n; r++){
			cur<<=1;
			cur += bool(s[r]=='1');
			cur = min(cur, INF);
			ss[l][r + 1] = cur;
		}
	}

	for (int i = 0; i < n; i++){
		nxt[i] = i;
		while (nxt[i] < n && s[nxt[i]] == '0')	nxt[i]++;
	}
	
	for (int i = 0; i < n; i++)	d[i][0] = 1;
	for (int i = 0; i < n; i++)
		for (int mask = 0; mask < 1<<MX; mask++)
			if (nxt[i] < n)
				for (int r = nxt[i]; r < n && ss[i][r+1] <= MX; r++){
					int &temp = d[r+1][mask|1<<ss[i][r+1]-1];
					temp = (temp + d[i][mask]) % MOD;
				}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int mask = 1; mask < 1<<MX; mask++){
			int temp = ~mask;
			if ((temp&-temp) > mask)
				ans = (ans + d[i][mask]) % MOD;
		}
	cout << ans << "\n";
	return 0;
}