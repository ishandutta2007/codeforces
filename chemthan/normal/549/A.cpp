//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, n) for(int i = n - 1; i >= 0; i--)
#define FORd2(i, a, b) for(int i = a - 1; i >= b; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define sz(a) int((a).size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int n, m;
int a[50][50];
bool s[256];

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>n>>m;
	FOR(i, n) {
		char buf[51]; cin>>buf;
		FOR(j, m) a[i][j] = buf[j];
	}
	int ans = 0;
	FOR(i, n - 1) FOR(j, m - 1) {
		ms(s, 0);
		s[a[i][j]] = s[a[i + 1][j]] = s[a[i][j + 1]] = s[a[i + 1][j + 1]] = 1;
		if (s['f'] + s['a'] + s['c'] + s['e'] == 4) ans++;
	}
	cout<<ans;
}

int main() {
	solve();
	return 0;
}