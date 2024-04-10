/*
Author: Dynamic JQ

Problem: Codeforces 86C - Genetic engineering

Time & Date(start): Apr/5/2018 21:28

Verdict: 

Tags: AC Automaton
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 9;
const int MAXN = 100, MAXL = 1000, MAXP = 10, ALPH = 26;
string S[MAXN + 5];
int cnt, G[MAXN + 5][ALPH + 5], fail[MAXN + 5], dep[MAXN + 5], ter[MAXN + 5];

void bfs(int v)
{
	queue<int> que;
	que.push(v);
	fail[0] = -1;
	dep[0] = 0;
	while(!que.empty()) {
		int u = que.front();
		que.pop();
		ter[u] = max(ter[u], ter[fail[u]]);
		rep(i, ALPH) {
			int to = G[u][i];
			if(to == -1) continue;
			dep[to] = dep[u] + 1;
			fail[to] = u;
			do fail[to] = fail[fail[to]];
			while(fail[to] != -1 && G[fail[to]][i] == -1);
			fail[to] = fail[to] == -1 ? 0 : G[fail[to]][i];
			que.push(to);
		}
	}
}

int getnxt(int v, int ch)
{
	while(v != 0 && G[v][ch] == -1) v = fail[v];
	return G[v][ch] == -1 ? 0 : G[v][ch];
}

string gen = "ACGT";
int dp[MAXL + 5][MAXN + 5][MAXP + 5];

bool occur(string S, string T)
{
	rep(i, S.length() - T.length() + 1)
	if(S.substr(i, T.length()) == T) return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int l, n;
	cin >> l >> n;
	rep(i, n) cin >> S[i];
	sort(S, S + n);
	n = unique(S, S + n) - S;
	memset(G, -1, sizeof(G));
	memset(ter, -1, sizeof(ter));
	cnt = 1;
	rep(i, n) {
		int v = 0;
		rep(j, S[i].length()) {
			int ch = lower_bound(gen.begin(), gen.end(), S[i][j]) - gen.begin();
			if(G[v][ch] == -1) G[v][ch] = cnt ++;
			v = G[v][ch];
		}
		ter[v] = max(ter[v], (int)S[i].length());
	}
	bfs(0);
	dp[0][0][0] = 1;
	rep(i, l) rep(j, cnt) for(int k = 0; k <= MAXP; k ++) rep(c, ALPH) {
		int nj = getnxt(j, c);
		if(nj == 0) continue;
		int nd = ter[j] >= k ? 1 : k + 1;
		dp[i + 1][nj][nd] = (dp[i + 1][nj][nd] + dp[i][j][k]) % MOD;
	}
	int ans = 0;
	rep(i, cnt) if(ter[i] > 0)
	for(int j = 0; j <= ter[i]; j ++) ans = (ans + dp[l][i][j]) % MOD;
	cout << ans << '\n';
	return 0;
}