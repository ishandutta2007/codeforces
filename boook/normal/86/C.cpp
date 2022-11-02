/*input
6 2
CAT
TACT
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int, int>
#define MEM(i,j)   memset(i, j, sizeof i)
#define ALL(i)     i.begin(), i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0), cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define maxn 1010
#define maxw 4
#define INF 0x3f3f3f3f
#define mod 1000000009LL
char Z[] = {'A', 'T', 'C', 'G'};
int trs(char c) {
	REP(i, 0, 4) if(Z[i] == c) return i;
}


int ch[maxn][maxn], fail[maxn], len[maxn], pos = 0;


void Insert(string &s) {
	int now = 0;
	for (auto c : s) {
		int &to = ch[now][trs(c)];
		now = to ? to : to = ++pos;
	}
	len[now] = (int)s.size();
}
void GetAC() {
	queue<int> qu;
	for (int i = 0; i < maxw; ++ i)
		if (ch[0][i]) qu.push(ch[0][i]);
	while (qu.size()) {
		int now = qu.front(); qu.pop();
		for (int i = 0; i < maxw; ++ i) {
			int &to = ch[now][i], tmp;
			if (to == 0) to = ch[fail[now]][i];
			else {
				qu.push(to), tmp = fail[now];
				while (tmp && ch[tmp][i] == 0) tmp = fail[tmp];
				fail[to] = ch[tmp][i];
				len[to] = max(len[to], len[fail[to]]);
			}
		}
	}
}


void U(int &now, int val) { now = (now + val) % mod; }
int n, m, dp[maxn][maxn][12];
int32_t main() {
	IOS;
	cin >> n >> m;
	REP(i, 1, m + 1) {
		string s;
		cin >> s;
		Insert(s);
	}
	GetAC();
	dp[0][0][0] = 1;
	REP(i, 0, n) REP(j, 0, pos + 1) REP(k, 0, 11) {
		REP(ii, 0, 4) {
			int to = ch[j][ii];
			if(len[to] >= k + 1)
				 U(dp[i + 1][to][0], dp[i][j][k]);
			else U(dp[i + 1][to][k + 1], dp[i][j][k]);
		}
	}
	int ans = 0;
	REP(i, 0, pos + 1) U(ans, dp[n][i][0]);
	cout << ans << endl;
    return 0;
}