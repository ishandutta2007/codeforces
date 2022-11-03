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

int n, m;
int a[(1 << 18) + 1], q[18][(1 << 18) + 1];

const bool is_testing = 0;
int main()
{
	srand(3252);
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> n >> m;
	forn(i, 1 << n)
		cin >> a[i], q[n][i] = a[i];
	bool f = 1;
	for (int t = n - 1; t >= 0; t--){
		for (int i = 0; i < (1 << t); i++){
			if (f){
				q[t][i] = q[t + 1][2 * i] | q[t + 1][2 * i + 1];
			} else {
				q[t][i] = q[t + 1][2 * i] ^ q[t + 1][2 * i + 1];
			}
		}
		f = !f;
	}
	forn(asdfasdf, m){
		int d, b;
		cin >> d >> b;
		d--;
		q[n][d] = b;
		int uk = d / 2;
		bool f = 1;
		for (int t = n - 1; t >= 0; t--){
			if (f){
				q[t][uk] = q[t + 1][2 * uk] | q[t + 1][2 * uk + 1];
			} else {
				q[t][uk] = q[t + 1][2 * uk] ^ q[t + 1][2 * uk + 1];
			}
			uk /= 2;
			f = !f;
		}
		cout << q[0][0] << LN;
	}
}