//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip> 
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
typedef long double ld;

ld a, b, c, d;

ld f2(ld a, ld b, ld c){
	if (a == 0 && b == 0) return 10000000000000000007;
	if (a == 0) return abs(c / b);
	ld del = b * b - 4 * a * c;
	if (del < 0) return 10000000000000000007;
	del = sqrt(del);
	return MIN(abs((b + del) / (2 * a)), abs((b - del) / (2 * a)));
}

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>a>>b>>c>>d;
	if (a == 0 && b == 0 && c == 0 && d == 0) {cout<<fixed<<std::setprecision(10)<<0.0; return;}
	ld ans = 10000000000000000007;
	int u[4];
	for (int i = 0; i < (1<<4); i++) {
		FOR(i, 4) u[i] = -1;
		FOR(j, 4) if (i & (1<<j)) u[j] = 1;
		ans = MIN(ans, f2(u[0] * u[3] - u[1] * u[2], a * u[3] + d * u[0] - b * u[2] - c * u[1], a * d - b * c));
	}
	cout<<fixed<<std::setprecision(10)<<ans;
}

int main() {
	solve();
	return 0;
}