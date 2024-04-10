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

const int maxn = 10010;
int n, k;

void solve() {
     scanf("%d%d", &n, &k);
     ll cnt = 0, cnt2 = 0;
     FOR(i, 0, k) {
            int m; scanf("%d", &m);
            int prev, cur;
            bool ck = false;
            cnt++;
            FOR(j, 0, m) {
                   scanf("%d", &cur);
                   if (!j && cur == 1) {ck = true;}
                   if (j && (!ck || cur > prev + 1)) {cnt++; cnt2++; ck = false;}
                   prev = cur;
            }
     }
     printf("%I64d", cnt + cnt2 - 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}