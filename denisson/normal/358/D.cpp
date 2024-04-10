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
const ll P = 239017;

int n;
int a[3007], b[3007], c[3007];
int dp[2][3007];

int ans(int uk, int k){
	if (uk == 1){
		re max(ans(uk + 1, 0) + b[uk], ans(uk + 1, 1) + a[uk]);
	} else if (uk == n){
		if (k == 1){
			re b[uk];
		} else {
			re a[uk];
		}
	} else{
		if (dp[k][uk] != -1)
			re dp[k][uk];
		if (k == 1){
			dp[k][uk] = max(ans(uk + 1, 0) + c[uk], ans(uk + 1, 1) + b[uk]);
			re dp[k][uk];
		} else {
			dp[k][uk] = max(ans(uk + 1, 0) + b[uk], ans(uk + 1, 1) + a[uk]);
			re dp[k][uk];
		}
	}

}

const bool is_testing = 0;
int main()
{
	srand(3252);
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> n;
	form(i, 1, n)
		dp[0][i] = dp[1][i] = -1;
	forn(i, n)
		cin >> a[i + 1];
	forn(i, n)
		cin >> b[i + 1];
	forn(i, n)
		cin >> c[i + 1];
	if (n == 1)
		cout << a[1], exit(0);
	cout << ans(1, 0);
}