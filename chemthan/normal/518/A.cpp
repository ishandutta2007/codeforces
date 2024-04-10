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

int const nmax = 110;
char s[nmax], t[nmax];

void solve() {
	cin>>s>>t;
	int len = strlen(s);
	char ans[nmax]; ms(ans, 0); strcpy(ans, s);
	FOR(i, 0, len) {
		if (s[i] + 1 < t[i]) {ans[i] = s[i] + 1; cout<<ans; return;}
		if (s[i] + 1 == t[i]) {
			ans[i] = t[i];
			bool ck = false;
			FOR(j, i + 1, len) {ans[j] = 'a'; if (t[j] > 'a') ck = true;}
			if (ck) {cout<<ans; return;}
			ans[i] = s[i];
			ck = false;
			FOR(j, i + 1, len) {ans[j] = 'z'; if (s[j] < 'z') ck = true;}
			if (ck) cout<<ans; else cout<<"No such string";
			return;
		}
	}
	cout<<"No such string";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}