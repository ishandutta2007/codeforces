#ifndef ONLINE_JUDGE
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pi> vii;
typedef vector<pl> vll;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 200010;
int n, q;
int p[maxn];
int r[maxn];

void init() {
    FOR(i, 0, maxn) {p[i] = r[i] = i;}
}
int find(int u) {
    return p[u] == u ? u : p[u] = find(p[u]);
}
int findr(int u) {
    return r[u] == u ? u : r[u] = findr(r[u]);
}
void join(int u, int v) {
    p[find(u)] = p[find(v)];
}

void solve() {
    scanf("%d%d", &n, &q);
    init();
    while (q--) {
        int t, x, y; scanf("%d%d%d", &t, &x, &y); x--; y--;
        if (t == 1) join(x, y);
        else if (t == 2) {
            FOR(i, x, y) {
                i = findr(i); if (i >= y) break;
                join(i, y);
                r[i] = r[y];
            }
        }
        else find(x) == find(y) ? printf("YES\n") : printf("NO\n");
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    solve();
#ifndef ONLINE_JUDGE
    printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}