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

ll n;

void solve() {
     scanf("%I64d", &n);
     ll ans = 0;
     int k = 0;
     ll p = 1;
     int m = n;
     while (m > 0) {
           ans += 9 * p * (k + 1);
           p *= 10;
           m /= 10;
           k++;
     }
     ans += (n - p + 1) * k;
     printf("%I64d", ans);
}

int main() {
#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    solve();
    return 0;
}