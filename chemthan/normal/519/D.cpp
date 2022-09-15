//#include <bits/stdc++.h>
#include <iostream>
#include <map>
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

int v[256];
char s[100001];
ll sum[100000];
map<ll, int> m[256];

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	FOR(i, 26) cin>>v['a' + i];
	cin>>s;
	int l = strlen(s);
	ll ans = 0;
	FOR(i, l) {
		if (!i) sum[i] = v[s[i]]; else sum[i] = sum[i - 1] + v[s[i]];
		if (i) ans += m[s[i]][sum[i - 1]];
		m[s[i]][sum[i]]++;
	}
	cout<<ans;
}

int main() {
	solve();
	return 0;
}