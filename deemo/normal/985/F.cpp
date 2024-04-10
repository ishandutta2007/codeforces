#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;
const int C = 26;
const int BASE[2] = {701, 721};
const int MOD[2] = {(int)1e9 + 7, (int)1e9 + 9};

int n, a[MAXN];
string s;
int nxt[MAXN][C];
int hs[C][2][MAXN], ss[2][MAXN];

int getHash(int l, int r, int w, int t){
	return (hs[w][t][r] - 1ll*hs[w][t][l]*ss[t][r-l]%MOD[t]+MOD[t])%MOD[t];}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> n >> q;
	cin >> s;
	for (int i = 0; i < n; i++) a[i] = s[i] - 'a';
	memset(nxt, 63, sizeof(nxt));
	for (int i = n-1; ~i; i--){
		for (int w = 0; w < 26; w++)
			nxt[i][w] = nxt[i+1][w];
		nxt[i][a[i]] = i;
	}

	for (int w = 0; w < 26; w++)
		for (int t = 0; t < 2; t++)
			for (int i = 0; i < n; i++)
				hs[w][t][i+1] = (1ll*BASE[t]*hs[w][t][i] + (a[i]==w? 2: 1)) % MOD[t];
	for (int t = 0; t < 2; t++){
		ss[t][0] = 1;
		for (int i = 1; i < MAXN; i++)
			ss[t][i] = 1ll*ss[t][i-1]*BASE[t]%MOD[t];
	}

	while (q--){
		int x, y, ln; cin >> x >> y >> ln, x--, y--;
		bool fail = 0;
		for (int w = 0; !fail && w < 26; w++){
			int pos = nxt[x][w];
			if (pos < x+ln){
				int other = a[y+(pos-x)];
				for (int t = 0; t < 2; t++)
					fail |= getHash(x, x+ln, w, t) ^ getHash(y, y+ln, other, t);
			}
		}
		if (!fail)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}