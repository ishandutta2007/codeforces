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

const int maxn = 100;
char team[2][30];
int n;
int cnt[2][maxn];
int tim[2][maxn];
vector<pair<int ,pair<int, int> > > ans;

void solve() {
	ms(cnt, 0); ms(tim, -1);
	scanf("%s%s%d", &team[0], &team[1], &n);
	FOR(i, 0, n) {
		int t, np; char tmp[10], card[10]; scanf("%d%s%d%s", &t, tmp, &np, card);
		int nteam = 1; if (tmp[0] == 'h') nteam = 0;
		if (card[0] == 'r') {
			if (tim[nteam][np] == -1) tim[nteam][np] = t;
			else tim[nteam][np] = min(tim[nteam][np], t);
			cnt[nteam][np] = 0;
		}
		else if (cnt[nteam][np]) {
			if (tim[nteam][np] == -1) tim[nteam][np] = t;
			else tim[nteam][np] = min(tim[nteam][np], t);
			cnt[nteam][np] = 0;
		}
		else cnt[nteam][np] = t;
	}
	FOR(i, 0, maxn) {
		if (tim[0][i] != -1) ans.push_back(make_pair(tim[0][i], make_pair(0, i)));
		if (tim[1][i] != -1) ans.push_back(make_pair(tim[1][i], make_pair(1, i)));
	}
	sort(ans.begin(), ans.end());
	FOR(i, 0, sz(ans)) {
		printf("%s %d %d\n", team[ans[i].second.first], ans[i].second.second, ans[i].first);
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