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
char g[4000000];

int get(int i) {
	int cnt = 0, ans = -1;
	if (g[i] !=  '.') return -1;
	if ((i % m) >= 1 && g[i - 1] == '.') {ans = i - 1; cnt++;}
	if (i >= m && g[i - m] == '.') {ans = i - m; cnt++;}
	if ((i % m) < m - 1 && g[i + 1] == '.') {ans = i + 1; cnt++;}
	if (i < n * m - m && g[i + m] == '.') {ans = i + m; cnt++;}
	if (cnt > 1) return -1;
	return ans;
}

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>n>>m;
	int cnt = 0;
	char buf[2001]; FOR(i, n) {cin>>buf; FOR(j, m) { int k = i * m + j; g[k] = buf[j]; if (g[k] == '.') cnt++;}}
	queue<int> q; FOR(i, n * m) if (get(i) != -1) q.push(i);
	while (!q.empty()) {
		int i = q.front(); q.pop();
		int j = get(i);
		if (j != -1) {
			int x = MIN(i, j), y = MAX(i, j);
			if (x / m == y / m) {g[x] = '<'; g[y] = '>';} else {g[x] = '^'; g[y] = 'v';}
			if ((j % m) >= 1 && get(j - 1) != -1) q.push(j - 1);
			if (j >= m && get(j - m) != -1) q.push(j - m);
			if ((j % m) < m - 1 && get(j + 1) != -1) q.push(j + 1);
			if (j < n * m - m && get(j + m) != -1) q.push(j + m);
			cnt -= 2;
		}
	}
	if (cnt) {cout<<"Not unique"; return;}
	FOR(i, n) {FOR(j, m) cout<<g[i * m + j]; cout<<"\n";}
}

int main() {
	solve();
	return 0;
}