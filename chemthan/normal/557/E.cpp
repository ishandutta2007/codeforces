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

const int maxn = 5010;
char s[maxn];
int k;
bool ck[maxn][maxn];

int n = 1;
int node[maxn * maxn][2];
int value[maxn * maxn];
int sum[maxn * maxn];
void add(char s[], bool ck[]) {
	int k = 0;
	FOR(i, 0, maxn) {
		if (!s[i]) break;
		if (!node[k][s[i] - 'a']) node[k][s[i] - 'a'] = n++;
		k = node[k][s[i] - 'a'];
		value[k] += ck[i];
	}
}
void cal() {
	FORd(i, n, 1) sum[i] = value[i] + sum[node[i][0]] + sum[node[i][1]];
}
string query(int l) {
	string res;
	int k = 0;
	while (1) {
		if (l <= value[k]) return res;
		l -= value[k];
		if (l <= sum[node[k][0]]) {res += 'a'; k = node[k][0];}
		else {res += 'b'; l -= sum[node[k][0]]; k = node[k][1];}
	}
	return res;
}

void solve() {
	ms(ck, 0); ms(node, 0); ms(value, 0); ms(sum, 0);
	scanf("%s%d", s, &k);
	int nlen = strlen(s);
	FORd(i, nlen, 0) FOR(j, i, nlen) ck[i][j] = s[i] == s[j] && (i + 2 > j - 2 || ck[i + 2][j - 2]);
	FOR(i, 0, nlen) add(s + i, ck[i] + i); cal();
	printf("%s", query(k).data());
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}