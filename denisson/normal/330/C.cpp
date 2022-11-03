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

int n;
char a[107][107];
bool was[107];

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
	forn(i, n)
		forn(j, n)
			cin >> a[i][j];
	forn(i, n)
		forn(j, n)
			if (a[i][j] == '.')
				was[j] = 1;
	bool f = 1;
	forn(i, n)
		if (was[i] == 0)
			f = false;

	forn(i, n)
		was[i] = 0;

	if (f){
		forn(i, n)
			forn(j, n)
				if (a[i][j] == '.' && !was[j]){
					was[j] = 1;
					cout << i + 1 << ' ' << j + 1 << LN;
				}
	} else {
		forn(j, n)
			forn(i, n)
				if (a[i][j] == '.')
					was[i] = 1;
		bool f1 = 1;
		forn(i, n)
			if (was[i] == 0)
				f1 = 0;
		forn(i, n)
			was[i] = 0;
		if (f1){
			forn(j, n)
				forn(i, n)
					if (a[i][j] == '.' && !was[i]){
						was[i] = 1;
						cout << i + 1 << ' ' << j + 1 << LN;
					}
		} else cout << -1;
	}
}