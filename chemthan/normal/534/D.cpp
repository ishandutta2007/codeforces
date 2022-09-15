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
int n;
int a[maxn];
int d[maxn];
vi v[maxn];

void solve() {
     scanf("%d", &n);
     FOR(i, 0, n) {scanf("%d", a + i); d[a[i]]++;}
     int ans[maxn];
     int cnt = 0, cur = 0;
     while (1) {
           if (d[cur]) {d[cur]--; ans[cnt++] = cur++;}
           else if (cur < 3 && cnt < n) {printf("Impossible"); exit(0);}
           else cur -= 3;
           if (cnt == n) break;
     }
     printf("Possible\n");
     FOR(i, 0, n) v[a[i]].push_back(i);
     FOR(i, 0, n) {
            printf("%d ", v[ans[i]].back() + 1); v[ans[i]].pop_back();
     }
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}