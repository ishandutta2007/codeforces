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

int n, m, b, g;
bool s[110], t[110];

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	ms(s, 0); ms(t, 0);
	cin>>n>>m;
	cin>>b; FOR(i, b) {int k; cin>>k; s[k] = 1;}
	cin>>g; FOR(i, g) {int k; cin>>k; t[k] = 1;}
	FOR(i, 2 * n * m) {
		if (s[i % n]) t[i % m] = 1;
		else if (t[i % m]) s[i % n] = 1;
	}
	FOR(i, n) if (!s[i]) {cout<<"No"; return;}
	FOR(i, m) if (!t[i]) {cout<<"No"; return;}
	cout<<"Yes";
}

int main() {
	solve();
	return 0;
}