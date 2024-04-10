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
ll a[100007];
ll t[8*100007];
ll push1[8*100007];

void build(int v, int vl, int vr){
	if (vl == vr){
		t[v] = a[vl];
	} else {
		int vm = (vl + vr) / 2;
		build(v * 2 + 1, vl, vm);
		build(v * 2 + 2, vm + 1, vr);
		t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
	}
}

void push(int v){
	if (push1[v] != 0){
		t[v] = push1[v];
		push1[v * 2 + 1] = push1[v];
		push1[v * 2 + 2] = push1[v];
		push1[v] = 0;
	}
}

ll get(int v, int vl, int vr, int l, int r){
	push(v);
	if (vr < l || vl > r)
		re -LINF;
	if (vl >= l && vr <= r)
		re t[v];
	int vm = (vl + vr) / 2;
	ll q1 = get(v * 2 + 1, vl, vm, l, r);
	ll q2 = get(v * 2 + 2, vm + 1, vr, l, r);
	re max(q1, q2);

}

void up(int v, int vl, int vr, int l, int r, ll x){
	push(v);
	if (vr < l || vl > r)
		re;
	if (vl >= l && vr <= r){
		push1[v] = x;
		push(v);
	} else {
		int vm = (vl + vr) / 2;
		up(v * 2 + 1, vl, vm, l, r, x);
		up(v * 2 + 2, vm + 1, vr, l, r, x);
		t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
	}
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
	forn(i, n)
		cin >> a[i];
	build(0, 0, n - 1);
	int q;
	cin >> q;
	forn(sadfasdf, q){
		ll w, h;
		cin >> w >> h;
		w--;
		ll ma = get(0, 0, n - 1, 0, w);
		cout << ma << LN;
		up(0, 0, n - 1, 0, w, h + ma);
	}
}