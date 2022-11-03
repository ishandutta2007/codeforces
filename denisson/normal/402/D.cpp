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

int gcd(int a, int b){
	if (b == 0)
		re a;
	re gcd(b, a % b);
}

int n, m;
int a[5007];
set <int> bad;

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
	forn(i, n)
		cin >> a[i];
	forn(i, m){
		int x;
		cin >> x;
		bad.insert(x);
	}
	for (int i = n - 1; i >= 0; i--){
		int g = a[0];
		for (int j = 1; j <= i; j++)
			g = gcd(g, a[j]);
		if (g != 1){
			int cop = g;
			int d = 2;
			int bal = 0;
			while(d * d <= cop){
				while(cop % d == 0){
					cop /= d;
					if (bad.count(d))
						bal--;
					else
						bal++;
				}
				d++;
			}
			if (cop > 1){
				if (bad.count(cop))
					bal--;
				else
					bal++;
			}
			if (bal < 0){
				for (int j = 0; j <= i; j++)
					a[j] /= g;
			}
		}
	}
	ll ans = 0;
	forn(i, n){
		if (a[i] != 1){
			int d = 2;
			while (d * d <= a[i]){
				while (a[i] % d == 0){
					a[i] /= d;
					if (bad.count(d))
						ans--;
					else
						ans++;
				}
				d++;
			}
			if (a[i] > 1){
				if (bad.count(a[i]) )
					ans--;
				else
					ans++;
			}
		}
	}
	cout << ans;
}