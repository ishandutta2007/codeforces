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

const int maxn = 1000010;
int n;
int flag1[maxn];
int flag2[maxn];
int next[maxn];
int first, second;
vi odd, even;

void solve() {
	ms(flag1, 0); ms(flag2, 0); ms(next, 0);
	scanf("%d", &n);
	FOR(i, 0, n) {
		int a, b; scanf("%d%d", &a, &b);
		next[a] = b;
		flag1[b] = flag2[a] = flag2[b] = 1;
	}
	FOR(i, 1, maxn) if (!flag1[i] && flag2[i]) {first = i; break;}
	second = next[0];
	int tmp = first; while (tmp) {odd.push_back(tmp); tmp = next[tmp];}
	tmp = second; while (tmp) {even.push_back(tmp); tmp = next[tmp];}
	reverse(odd.begin(), odd.end());
	reverse(even.begin(), even.end());
	while (!odd.empty() || !even.empty()) {
		if (!odd.empty()) {printf("%d ", odd.back()); odd.pop_back();}
		if (!even.empty()) {printf("%d ", even.back()); even.pop_back();}
	}
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