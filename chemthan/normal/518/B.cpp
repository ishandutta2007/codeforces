//#include <bits/stdc++.h>
#include <iostream>
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

int const nmax = 200010;
char s[nmax], t[nmax];
int st[256];

void solve() {
	ms(st, 0);
	cin>>s>>t;
	int lens = strlen(s);
	int lent = strlen(t);
	FOR(i, 0, lent) st[t[i]]++;
	int ans1 = 0, ans2 = 0;
	FOR(i, 0, lens)
		if (st[s[i]]) {ans1++; st[s[i]]--; s[i] = 0;}
	FOR(i, 0, lens)
		if (s[i] >= 'a' && st[s[i] - 32]) {ans2++; st[s[i] - 32]--;}
		else if (s[i] <= 'Z' && st[s[i] + 32]) {ans2++; st[s[i] + 32]--;}
	cout<<ans1<<" "<<ans2;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}