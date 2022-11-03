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
const int P1 = 239017;
const int P2 = 353251;
const ll MOD = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

int n, m;
int a[100007];
int t[22][8*100007];
bool push1[22][8*100007];

void build(int v, int vl, int vr, int bit){
	if (vl == vr){
		t[bit][v] = (a[vl] >> bit) & 1;
	} else {
		int vm = (vl + vr) / 2;
		build(v * 2 + 1, vl, vm, bit);
		build(v * 2 + 2, vm + 1, vr, bit);
		t[bit][v] = t[bit][v * 2 + 1] + t[bit][v * 2 + 2];
	}
}

void push(int v, int vl, int vr, int bit){
	if (push1[bit][v]){
		t[bit][v] = (vr - vl + 1) - t[bit][v];
		push1[bit][v * 2 + 1] = !push1[bit][v * 2 + 1];
		push1[bit][v * 2 + 2] = !push1[bit][v * 2 + 2];
		push1[bit][v] = 0;
	}
}

int get(int v, int vl, int vr, int l, int r, int bit){
	push(v, vl, vr, bit);
	if (vr < l || vl > r)
		re 0;
	if (vl >= l && vr <= r){
		re t[bit][v];
	} else {
		int vm = (vl + vr) / 2;
		re get(v * 2 + 1, vl, vm, l, r, bit) + get(v * 2 + 2, vm + 1, vr, l, r, bit);
	}
}

void up(int v, int vl, int vr, int l, int r, int bit){
	push(v, vl, vr, bit);
	if (vr < l || vl > r)
		re;
	if (vl >= l && vr <= r){
		push1[bit][v] = 1;
		push(v, vl, vr, bit);
	} else {
		int vm = (vl + vr) / 2;
		up(v * 2 + 1, vl, vm, l, r, bit);
		up(v * 2 + 2, vm + 1, vr, l, r, bit);
		t[bit][v] = t[bit][v * 2 + 1] + t[bit][v * 2 + 2];
	}
}

ll myget(int l, int r){
	ll ans = 0;
	forn(bit, 21)
		ans += (ll)(1 << bit) * get(0, 0, n - 1, l, r, bit);
	re ans;
}

const bool is_testing = 0;
int main()
{
	srand(time(NULL));
	if (is_testing)
	{
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout);
	}
	cin >> n;
	forn(i, n)
		cin >> a[i];
	cin >> m;
	forn(bit, 21)
		build(0, 0, n - 1, bit);
	forn(i, m){
		int type;
		read(type);
		if (type == 1){
			int l, r;
			scanf("%d%d", &l, &r);
			l--; r--;
			cout << myget(l, r) << LN;
		} else {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			l--; r--;
			forn(bit, 21)
				if ((x >> bit) & 1)
					up(0, 0, n - 1, l, r, bit);
		}
	}
}