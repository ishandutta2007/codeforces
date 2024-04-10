//#include <bits/stdc++.h>
#include <iostream>
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
ll gcd(ll a, ll b){ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int m;
int H1, A1, X1, Y1, H2, A2, X2, Y2;

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>m>>H1>>A1>>X1>>Y1>>H2>>A2>>X2>>Y2;
	int u1 = 0;
	FOR(i, m) {H1 = (1LL * X1 * H1 + Y1) % m; H2 = (1LL * X2 * H2 + Y2) % m; if (H1 == A1) {u1 = i + 1; break;}}
	if (u1 == 0) {cout<<-1; return;} if (H2 == A2) {cout<<u1; return;}
	int c1 = 0; int X3 = 1, Y3 = 0;
	FOR(i, m) {H1 = (1LL * X1 * H1 + Y1) % m; X3 = 1LL * X3 * X2 % m; Y3 = (1LL * Y3 * X2 + Y2) % m; if (H1 == A1) {c1 = i + 1; break;}}
	if (c1 == 0) {cout<<-1; return;}
	FOR(i, m) {if (H2 == A2) {cout<<u1 + 1LL * c1 * i; return;} H2 = (1LL * X3 * H2 + Y3) % m;}
	cout<<-1;
}

int main() {
	solve();
	return 0;
}