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

const int maxn = 100010;
const int mod = 1000000007;
int n;
char s[maxn];
int cnt[255];

ll ex(ll n, ll k) {
   if (k == 0) return 1;
   if (k & 1) return n * ex(n, k - 1) % mod;
   ll t = ex(n, k >> 1);
   return t * t % mod;
}

void solve() {
     ms(cnt, 0);
     scanf("%d%s", &n, s);
     FOR(i, 0, n) cnt[s[i]]++;
     ll ans = 1;
     int cntmax = INT_MIN, c = 0;
     FOR(i, 0, 255) if (cnt[i]) cntmax = max(cntmax, cnt[i]);
     FOR(i, 0, 255) if (cnt[i] == cntmax) c++;
     printf("%I64d", ex(c, n));
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