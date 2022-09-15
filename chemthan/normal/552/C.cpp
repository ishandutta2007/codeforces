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

ll w, m;
ll e[100];

bool run(ll p) {
     if (p == 0) return true;
     int k = 0;
     while (k <= 100) {
           if (p <= e[k]) break;
           k++;
     }
     if (MIN(p, e[k] - p) > (e[k] - 1) / (w - 1)) return false;
     if (p > e[k] - p) return run(e[k] - p);
     if (p <= e[k] - p) return run(p - e[k - 1]);
}

void solve() {
     scanf("%I64d%I64d", &w, &m);
     e[0] = 1;
     FOR(i, 0, 100) {
            e[i + 1] = e[i] * w;
            if (e[i + 1] > m) break;
     }
     if (run(m)) printf("YES"); else printf("NO");
}

int main() {
#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    solve();
    return 0;
}