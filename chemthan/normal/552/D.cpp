#ifndef ONLINE_JUDGE
        #include <iostream>
#else
        #include <bits/stdc++.h>
#endif
#include <iomanip>
#include <cmath>
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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int const nmax = 2010;
int n;
int x[nmax];
int y[nmax];
int cnt[410][410];

void solve() {
     scanf("%d", &n);
     FOR(i, 0, n) scanf("%d%d", x + i, y + i);
     ll ans = 1LL * n * (n - 1) * (n - 2) / 6;
     FOR(i, 0, n) {
            ms(cnt, 0);
            FOR(j, i + 1, n) {
                int a = x[j] - x[i];
                int b = y[j] - y[i];
                if (a < 0 || (a == 0 && b < 0)) {a = -a; b = -b;}
                int d = gcd(a, abs(b));
                a /= d; b /= d; b += 210;
                ans -= cnt[a][b];
                cnt[a][b]++;
            }
     }
     printf("%I64d", ans);
}

int main() {
#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    solve();
    return 0;
}