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

int a[3];
int b[3];

void solve() {
     FOR(i, 0, 3) scanf("%d%d", a + i, b + i);
     if (a[1] + a[2] <= a[0] && max(b[1], b[2]) <= b[0]) {printf("YES"); return;}
     if (max(a[1], a[2]) <= a[0] && b[1] + b[2] <= b[0]) {printf("YES"); return;}
     swap(a[1], b[1]);
     if (a[1] + a[2] <= a[0] && max(b[1], b[2]) <= b[0]) {printf("YES"); return;}
     if (max(a[1], a[2]) <= a[0] && b[1] + b[2] <= b[0]) {printf("YES"); return;}
     swap(a[2], b[2]);
     if (a[1] + a[2] <= a[0] && max(b[1], b[2]) <= b[0]) {printf("YES"); return;}
     if (max(a[1], a[2]) <= a[0] && b[1] + b[2] <= b[0]) {printf("YES"); return;}
     swap(a[1], b[1]);
     if (a[1] + a[2] <= a[0] && max(b[1], b[2]) <= b[0]) {printf("YES"); return;}
     if (max(a[1], a[2]) <= a[0] && b[1] + b[2] <= b[0]) {printf("YES"); return;}
     printf("NO");
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