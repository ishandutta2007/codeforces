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
bool a[100][100];
int b[100][100];

void update(int x, int y) {
	int d;
	if (a[x][y]) d = -1 - b[x][y]; else d = 1 - b[x][y];
	FOR(i, x + 1) FOR(j, y + 1) b[i][j] += d;
}

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	ms(b, 0);
	cin>>n>>m; char buf[101];
	FOR(i, n) {cin>>buf; FOR(j, m) a[i][j] = (buf[j] == 'B' ? 1 : 0);}
	int ans = 0;
	FORd(i, n) FORd(j, m) if ((a[i][j] && b[i][j] != -1) || (!a[i][j] && b[i][j] != 1)) {update(i, j); ans++;}
	cout<<ans;
}

int main() {
	solve();
	return 0;
}