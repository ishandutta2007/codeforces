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
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef unsigned long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
#define clr(a, n) memset(a, n, sizeof(a));
#define sqr(x) x*x
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 dsfgsdfgsdfgsdfgsdfgsdfg1
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const bool is_testing = 0;
//const int p = 997;
const int MOD = (int)1e9;
const int MOD2 = (int)1e9 + 11;
const int MAXN = (int)2e5 + 7;

int n, a, b;

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	//freopen("st2d.in", "r", stdin);
	//freopen("st2d.out", "w", stdout);
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> n >> a >> b;
	if (b == 0)
		cout << a, exit(0);
	if (b < 0)
	{
		b = -b;
		while(b > 0)
		{
			a--;
			if (a == 0)
				a = n;
			b--;
		}
		cout << a;
	}
	else
	{
		while(b > 0)
		{
			a++;
			if (a == n + 1)
				a = 1;
			b--;
		}
		cout << a;
	}
	//system("pause");			
	return 0;
}