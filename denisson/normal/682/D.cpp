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

int n, m, k;
str s1, s2;
int dp[1007][1007][11][2];

const bool is_testing = 0;
int main()
{
	srand(3252);
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> n >> m >> k >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++){
		for (int j = 0; j < s2.size(); j++){
			for (int kk = 1; kk <= k; kk++){
				if (s1[i] == s2[j]){
						dp[i+1][j+1][kk][1] = max(dp[i+1][j+1][kk][1], dp[i][j][kk][1] + 1);
						dp[i+1][j+1][kk+1][1] = max(dp[i][j][kk][0] + 1, dp[i+1][j+1][kk+1][1]);
						int q1 = max(dp[i+1][j][kk][0], dp[i][j+1][kk][0]);
						int q2 = max(dp[i+1][j][kk][1], dp[i][j+1][kk][1]);
						dp[i+1][j+1][kk][0] = max(dp[i+1][j+1][kk][0], max(q1, q2));
				} else {
					int q1 = max(dp[i+1][j][kk][0], dp[i][j+1][kk][0]);
					int q2 = max(dp[i+1][j][kk][1], dp[i][j+1][kk][1]);
					dp[i+1][j+1][kk][0] = max(dp[i+1][j+1][kk][0], max(q1, q2));
				}
			}
		}
	}
	/*for (int i = 0; i < s1.size(); i++){
		for (int j = 0; j < s2.size(); j++){
			for (int kk = 0; kk <= k; kk++){
				for (int f = 0; f <= 1; f++){
					cout << i + 1 << ' ' << j + 1 << ' ' << kk << ' ' << f << ' ' << dp[i + 1][j+ 1][kk][f] << LN;
				}
			}
		}
	}*/
	int ans = 0;
	forn(i, k + 1)
		forn(j, 2)
			ans = max(ans, dp[n][m][i][j]);
	cout << max(dp[n][m][k][0],dp[n][m][k][1]);
}