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
int a[3*100007];
int lg[1000007];
pair<int, int> t[22][3*100007];

int gcd(int a, int b){
	if (b == 0)
		re a;
	re gcd(b, a % b);
}

void build(){
	for (int i = 2; i < 1e6 + 1; i++)
		lg[i] = lg[i / 2] + 1;
	for (int p = 0; (1 << p) <= n; p++)
		for (int l = 0; l + (1 << p) <= n; l++)
			if (p == 0)
				t[p][l].XX = a[l];
			else
				t[p][l].XX = min(t[p-1][l].XX, t[p-1][l + (1 << (p - 1))].XX);
	for (int p = 0; (1 << p) <= n; p++)
		for (int l = 0; l + (1 << p) <= n; l++)
			if (p == 0)
				t[p][l].YY = a[l];
			else
				t[p][l].YY =  gcd(t[p-1][l].YY, t[p-1][l + (1 << (p-1))].YY);
}

int get_min(int l, int r){
	int p = lg[r - l + 1];
	re min(t[p][l].XX, t[p][r - (1 << p) + 1].XX);
}

int get_gcd(int l, int r){
	int p = lg[r - l + 1];
	re gcd(t[p][l].YY, t[p][r - (1 << p) + 1].YY);
}

bool ok(int l, int r){
	re (get_gcd(l, r) == get_min(l, r));
}

int check(int len){
	int ans = 0;
	for (int l = 0; l + len - 1 < n; l++)
		if (ok(l, l + len - 1))
			ans++;
	re ans;
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
	forn(i, n)
		cin >> a[i];
	build();
	int l = 0, r = n + 1;
	while (l + 1 < r){
		int m = (l + r) / 2;
		if (check(m) > 0)
			l = m;
		else
			r = m;
	}
	int ans = l;
	cout << check(ans) << ' ' << ans - 1 << LN;
	for (int l = 0; l + ans - 1 < n; l++)
		if (ok(l, l + ans - 1))
			cout << l + 1 << ' ';
}