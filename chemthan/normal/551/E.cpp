#ifndef ONLINE_JUDGE
	#include <iostream>
#else
	#include <bits/stdc++.h>
#endif
#include <cmath>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define sz(a) int((a).size())
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int const nmax = 510000;
int n, q;
ii a[nmax];
ll f[nmax];
int d;
set<int> st;

void increase(int l, int r, int x) {
     int u = (d + l - 1) / d;
     int v = (r + 1) / d;
     if (u > v) u = v;
     FOR(i, u, v) f[i] += x;
     if (u) FOR(i, (u - 1) * d, u * d) if (a[i].second >= l && a[i].second <= r) a[i].first += x;
     FOR(i, v * d, (v + 1) * d) if (a[i].second >= l && a[i].second <= r) a[i].first += x;
     if (u) sort(a + (u - 1) * d, a + u * d);
     sort(a + v * d, a + (v + 1) * d);
}

int query(int y) {
    st.clear();
    FOR(i, 0, d) {
           int p = lower_bound(a + i * d, a + (i + 1) * d, ii(y - f[i], 0)) - a;
           int q = lower_bound(a + i * d, a + (i + 1) * d, ii(y - f[i] + 1, 0)) - a - 1;
           if (p <= q) {st.insert(p); st.insert(q);}
    }
    if (sz(st) == 0) return -1;
    else {
         set<int>::iterator it = st.begin();
         set<int>::iterator it2 = st.end(); it2--;
         return (a[*it2].second - a[*it].second);
    }
}

void solve() {
     ms(f, 0);
     scanf("%d%d", &n, &q);
     FOR(i, 0, n) {int k; scanf("%d", &k); a[i].first = k; a[i].second = i;}
     d = 1 + sqrt(n);
     FOR(i, n, d * d) a[i].first = INT_MAX;
     FOR(i, 0, d) sort(a + i * d, a + (i + 1) * d);
     while (q--) {
           int t; scanf("%d", &t);
           if (t == 1) {
                 int l, r, x;
                 scanf("%d%d%d", &l, &r, &x); l--; r--;
                 increase(l, r, x);
           } else {
                  int y;
                  scanf("%d", &y);
                  printf("%d\n", query(y));
           }
     }
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}