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

int n, l, r, x;
int a[15];

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>n>>l>>r>>x;
	FOR(i, n) cin>>a[i];
	int ans = 0;
	FOR2(i, 1, 1<<n) {
		int mi = 1000000007, ma = 0, sum = 0;
		FOR(j, n) {
			if (i & (1<<j)) {
				mi = MIN(mi, a[j]);
				ma = MAX(ma, a[j]);
				sum += a[j];
			}
		}
		if (ma - mi >= x && sum >= l && sum <= r) ans++;
	}
	cout<<ans;
}

int main() {
	solve();
	return 0;
}