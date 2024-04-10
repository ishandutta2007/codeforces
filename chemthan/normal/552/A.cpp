#ifndef ONLINE_JUDGE
        #include <iostream>
#else
        #include <bits/stdc++.h>
#endif
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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int const nmax = 110;
int n;

void solve() {
     scanf("%d", &n);
     ll ans = 0;
     FOR(i, 0, n) {
            int x, y, z, t; scanf("%d%d%d%d", &x, &y, &z, &t);
            if (x <= z && y <= t) {
                  ans += (z - x + 1) * (t - y + 1);
            }
     }
     cout<<ans;
}

int main() {
#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    solve();
    return 0;
}