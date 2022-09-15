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

const int maxn = 500010;
char s[maxn];
bool v[255];
ld f[maxn];
ld g[maxn];

void solve() {
     ms(f, 0); ms(g, 0);
     ms(v, 0); v['I'] = v['E'] = v['A'] = v['O'] = v['U'] = v['Y'] = 1;
     scanf("%s", s);
     int n = strlen(s);
     ld ans = 0;
     if (n % 2 == 1) {
        s[n++] = 'Z';
        ld temp = 0;
        FOR(i, 0, n) {
               temp += 1.0 / (n - i);
               ans -= 1.0 * v[s[i]] * temp;
        }
     }
     FOR(i, 0, n) f[0] += 1.0 / (i + 1);
     FOR(i, 1, n / 2) f[i] = f[i - 1] - 1.0 / (i) - 1.0 / (n - i + 1);
     FOR(i, 0, n) g[i] = g[(i + n) % (n + 1)] + f[i];
     FOR(i, 0, n / 2) ans += 1.0 * (v[s[i]] + v[s[n - i - 1]]) * g[i];
     cout<<fixed<<setprecision(9)<<ans;
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