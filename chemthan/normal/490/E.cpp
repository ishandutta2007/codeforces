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
int n;
string s[maxn];

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) cin>>s[i];
	FOR(i, 0, n) {
		if (!i || s[i].length() > s[i - 1].length()) {
			FOR(j, 0, s[i].length()) if (s[i][j] == '?') {if (j) s[i][j] = '0'; else s[i][j] = '1';}
		}
		else {
			if (s[i].length() < s[i - 1].length()) {printf("NO"); return;}
			if (s[i] < s[i - 1]) {printf("NO"); return;}
			vi v;
			FOR(j, 0, s[i].length()) if (s[i][j] == '?') {v.push_back(j); s[i][j] = '0';}
			if (s[i] > s[i - 1]) {FOR(j, 0, s[i].length()) if (s[i][j] == '.') {if (j) s[i][j] = '0'; else s[i][j] = '1';}}
			else {
				FOR(j, 0, sz(v)) s[i][v[j]] = '9';
				FOR(j, 0, sz(v)) {
					s[i][v[j]] = '0'; if (s[i] > s[i - 1]) continue;
					s[i][v[j]] = s[i - 1][v[j]]; if (s[i] > s[i - 1]) continue;
					if (s[i - 1][v[j]] < '9') {
						s[i][v[j]] = s[i - 1][v[j]] + 1;
						FOR(k, j + 1, sz(v)) s[i][v[k]] = '0';
						break;
					}
				}
			}
			if (s[i] <= s[i - 1]) {printf("NO"); return;}
		}
	}
	printf("YES\n"); FOR(i, 0, n) cout<<s[i]<<endl;
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