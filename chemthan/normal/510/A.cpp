#ifndef ONLINE_JUDGE
	#include <iostream>
#else
	#include <bits/stdc++.h>
#endif
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define sz(a) int((a).size())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int n, m;
int a[50][50];

void solve() {
	ms(a, 0);
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) FOR(j, 0, m) if (i % 2 == 0) a[i][j] = 1;
	FOR(i, 0, n) if (i % 4 == 1) a[i][m - 1] = 1; else if (i % 4 == 3) a[i][0] = 1;
	FOR(i, 0, n) {FOR(j, 0, m) if (a[i][j] == 1) cout<<"#"; else cout<<"."; cout<<"\n";}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}