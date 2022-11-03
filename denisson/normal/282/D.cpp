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
#define write(x) printf("%d", x)
#define writeln(x) printf("%d\n", x)
#define wp(x) cout << x.first << ' ' << x.second << '\n';
#define wm(x) for (int i = 0; i < x.size(); i++) cout << x[i] << ' '; cout << LN;
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

int n;
int dp3[307][307][307];
int dp2[307][307];

void ans(bool f){
	if (f) 
		cout << "BitLGM";
	else
		cout << "BitAryo";
	exit(0);
}

const bool is_testing = 0;
int main()
{
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> n;
	if (n == 1){
		cin >> n;
		if (n == 0)
			ans(0);
		ans(1);
	} else if (n == 2){
		int a, b;
		cin >> a >> b;
		dp2[0][0] = 0;
		for (int i = 0; i <= a; i++)
			for (int j = 0; j <= b; j++)
				if (!dp2[i][j]){
					for (int d = 1; d + i <= a; d++)
						dp2[i + d][j] = 1;
					for (int d = 1; d + j <= b; d++)
						dp2[i][j + d] = 1;
					for (int d = 1; d + i <= a && d + j <= b; d++)
						dp2[i + d][j + d] = 1;
				}
		ans(dp2[a][b]);
	} else {
		int a, b, c;
		cin >> a >> b >> c;
		dp3[0][0][0] = 0;
		for (int i = 0; i <= a; i++)
			for (int j = 0; j <= b; j++)
				for (int k = 0; k <= c; k++)
					if (!dp3[i][j][k]){
						for (int d = 1; d + i <= a; d++)
							dp3[i + d][j][k] = 1;
						for (int d = 1; d + j <= b; d++)
							dp3[i][j + d][k] = 1;
						for (int d = 1; d + k <= c; d++)
							dp3[i][j][k + d] = 1;
						for (int d = 1; d + i <= a && d + j <= b && d + k <= c; d++)
							dp3[i + d][j + d][k + d] = 1;
					}
		ans(dp3[a][b][c]);

	}
}