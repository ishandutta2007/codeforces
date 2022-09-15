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

ll a, b;

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	ll ans = 1;
	cin>>a>>b;
	while (1) {
		if (a == b) break;
		ans += a / b;
		ll x = MAX(a % b, b);
		ll y = MIN(a % b, b);
		a = x; b = y;
		if (b == 0) {cout<<ans - 1; return;}
	}
	cout<<ans;
}

int main() {
	solve();
	return 0;
}