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
char s[maxn];

void solve() {
     scanf("%s", s);
     int nlen = strlen(s);
     FOR(i, 0, nlen - 1) if (s[i] < s[nlen - 1] && (s[i] - '0') % 2 == 0) {swap(s[i], s[nlen - 1]); break;}
     if ((s[nlen - 1] - '0') % 2 != 0) {
        FORd(i, nlen - 1, 0) if ((s[i] - '0') % 2 == 0) {swap(s[i], s[nlen - 1]); break;}
     }
     if ((s[nlen - 1] - '0') % 2 != 0) {printf("-1"); return;}
     printf("%s", s);
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