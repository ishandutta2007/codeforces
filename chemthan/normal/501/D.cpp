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
int p[maxn];
int q[maxn];
int a[maxn];
int b[maxn];
int c[maxn];
//set<int> st;

int fen[maxn];
void add(int p, int val) {
	for (p++; p < maxn; p += p & -p) fen[p] += val;
}
int get(int p)
{
	int res = 0;
	for (; p > 0; p -= p & -p) res += fen[p];
	return res;
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", p + i);
	FOR(i, 0, n) scanf("%d", q + i);
	FORd(i, n, 0) {a[i] = get(p[i]); add(p[i], 1);}
	ms(fen, 0);
	FORd(i, n, 0) {b[i] = get(q[i]); add(q[i], 1);}
	int m = 0;
	FORd(i, n, 0) {
		//st.insert(i);
		int k = a[i] + b[i] + m;
		m = k / (n - i);
		c[i] = k % (n - i);
	}
	ms(fen, 0);
	FOR(i, 0, n) {
		//cout<<c[i]<<endl;
		//printf("%d ", c[i] + get(c[i] + 1));
		int l = 0, r = n - 1;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (mid - get(mid + 1) < c[i]) l = mid + 1; else r = mid;
		}
		printf("%d ", l);
		add(l, 1);
		//set<int>::iterator it = st.begin();
		//advance(it, c[i]);
		//printf("%d ", *it);
		//st.erase(*it);
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