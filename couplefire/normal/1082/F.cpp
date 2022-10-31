#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 500 + 7;
const int M = 11;
const int INF = 1e9;

struct node{
	int nxt[10];
	int cnt;
	node(){
		memset(nxt, -1, sizeof(nxt));
		cnt = 0;
	}
};

node trie[N];
int cnt;
int h[N];

void add(string s, int m){
	int cur = 0;
	forn(i, s.size()){
		int c = s[i] - '0';
		if (trie[cur].nxt[c] == -1){
			trie[cur].nxt[c] = cnt;
			h[cnt] = h[cur] + 1;
			++cnt;
		}
		cur = trie[cur].nxt[c];
	}
	trie[cur].cnt += m;
}

int n, k;

int dp[N][M][N];
int dp2[N][M][N][M];

int calc(int x, int rem, int k){
	if (dp[x][rem][k] != -1)
		return dp[x][rem][k];
	
	vector<int> ch;
	forn(i, 10) if (trie[x].nxt[i] != -1)
		ch.push_back(trie[x].nxt[i]);
	
	dp[x][rem][k] = INF;
	if (rem > 0)
		dp[x][rem][k] = min(dp[x][rem][k], calc(x, rem - 1, x));
	
	dp2[x][rem][k][ch.size()] = 0;
	for (int i = int(ch.size()) - 1; i >= 0; --i) forn(z, rem + 1)
		dp2[x][rem][k][i] = min(dp2[x][rem][k][i], calc(ch[i], z, k) + dp2[x][rem - z][k][i + 1]);
	
	dp[x][rem][k] = min(dp[x][rem][k], dp2[x][rem][k][0] + (h[x] - h[k]) * trie[x].cnt);
	
	return dp[x][rem][k];
}

int main() {
	trie[0] = node();
	cnt = 1;
	
	cin >> n >> k;
	forn(i, n){
		string s;
		int m;
		cin >> s >> m;
		add(s, m);
	}
	
	memset(dp, -1, sizeof(dp));
	
	forn(i, N) forn(j, M) forn(l, N) forn(t, M)
		dp2[i][j][l][t] = INF;
	
	int ans = calc(0, k, 0);
	
	cout << ans << endl;
	return 0;
}