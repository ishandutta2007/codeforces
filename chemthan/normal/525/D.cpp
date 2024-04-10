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
bool a[2000][2000];

bool ipm(int x, int y) {
	if (x > 0 && y > 0 && a[x][y] + a[x - 1][y] + a[x][y - 1] + a[x - 1][y - 1] == 3) return true;
	if (x < n - 1 && y < m - 1 && a[x][y] + a[x + 1][y] + a[x][y + 1] + a[x + 1][y + 1] == 3) return true;
	if (x > 0 && y < m - 1 && a[x][y] + a[x - 1][y] + a[x][y + 1] + a[x - 1][y + 1] == 3) return true;
	if (x < n - 1 && y > 0 && a[x][y] + a[x + 1][y] + a[x][y - 1] + a[x + 1][y - 1] == 3) return true;
	return false;
}

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>n>>m;
	char buf[2001];
	FOR(i, n) {cin>>buf; FOR(j, m) a[i][j] = (buf[j] == '.' ? 1 : 0);}
	queue<ii> q;
	FOR(i, n) FOR(j, m) if (!a[i][j]) q.push(ii(i, j));
	while (!q.empty()) {
		int x = q.front().first; int y = q.front().second; q.pop();
		if (!a[x][y] && ipm(x, y)) {
			a[x][y] = 1;
			FOR2(z, x - 1, x + 2) FOR2(t, y - 1, y + 2) if (z >= 0 && z < n && t >= 0 && t < m && !a[z][t]) q.push(ii(z, t));
		}
	}
	FOR(i, n) {FOR(j, m) cout<<(a[i][j] == 1 ? "." : "*"); cout<<"\n";}
}

int main() {
	solve();
	return 0;
}