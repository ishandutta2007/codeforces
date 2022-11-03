#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

typedef long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
//
#define read(x) scanf("%d", &x)
#define write(x) printf("%d", &x)
#define wp(x) cout << x.first << ' ' << x.second << '\n';
#define read2(x, y) scanf("%d %d", &x, &y)
//
#define sqr(x) x*x
#define clr(a, x) memset(a, x, sizeof(a));
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const int MAXN = 60007;
const ll MOD = 1e9 + 7;

ll n, m, k;
ll cost[307][307];
ll dp[307][307];

const bool is_testing = 0;
int main()
{
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> n >> m >> k;
	forn(i, 305)
		forn(j, 305)
			cost[i][j] = LINF, dp[i][j] = LINF;
	forn(i, m){
		ll l, r, x;
		cin >> l >> r >> x;
		cost[l][r] = min(cost[l][r], x); 
	}	
	/*form(i, 1, n)
		form(j, i, n)
			form(k, i, j){
				cost[i][k] = min(cost[i][k], cost[i][j]);
				cost[k][j] = min(cost[k][j], cost[i][j]);	
			}*/
	form(i, 1, n)
		form(j, i, n)
			cost[i][j] = min(cost[i][j], cost[i - 1][j]);
	dp[0][0] = 0;
	form(i, 1, n){
		dp[i][0] = 0;
		form(want, 1, i){
			for (int k = i - 1; k >= 1; k--)
				dp[i][want] = min(dp[i][want], dp[k][want]);
			for (int k = i; k >= 1; k--)
				if (dp[k - 1][want - (i - k + 1)] != LINF && cost[k][i] != LINF && want - (i - k + 1) >= 0)
					dp[i][want] = min(dp[i][want], dp[k - 1][want - (i - k + 1)] + cost[k][i]);
		}
	}
	ll ans = LINF;

	form(i, 1, n)
		form(kk, k, n)
			ans = min(ans, dp[i][kk]);

	if (ans == LINF)
		cout << -1;
	else
		cout << ans;
}