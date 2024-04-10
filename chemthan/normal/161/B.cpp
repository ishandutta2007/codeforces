#ifndef ONLINE_JUDGE
	#include <iostream>
#else
	#include <bits/stdc++.h>
#endif
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define sz(a) int((a).size())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int const nmax = 1010;
int k, n;
vii st, pe;
vi ans[nmax];
bool dc[nmax];
ld p[nmax];

void solve() {
	ms(dc, 0);
	cin>>k>>n;
	FOR(i, 0, k) {
		int c, t; cin>>c>>t;
		p[i] = c;
		if (t == 1) st.push_back(ii(c, i));
		else pe.push_back(ii(c, i));
	}
	sort(st.begin(), st.end());
	sort(pe.begin(), pe.end());
	int k = 0;
	while (!st.empty()) {
		if (k >= n) k = n - 1;
		dc[k] = 1;
		ans[k].push_back(st.back().second); st.pop_back();
		k++;
	}
	FORd(i, n, 0) {
		if (sz(ans[i]) > 0) break;
		ans[i].push_back(pe.front().second); pe.erase(pe.begin());
	}
	while (!pe.empty()) {
		if (k >= n) k = n - 1;
		ans[k].push_back(pe.back().second); pe.pop_back();
		k++;
	}
	ld sum = 0;
	FOR(i, 0, n) {
		ld m = INT_MAX;
		FOR(j, 0, sz(ans[i])) {
			int k = ans[i][j];
			sum += p[k];
			m = MIN(m, p[k]);
		}
		if (dc[i]) sum -= m / 2;
	}
	cout<<fixed<<setprecision(1)<<sum<<"\n";
	FOR(i, 0, n) {cout<<sz(ans[i])<<" "; FOR(j, 0, sz(ans[i])) cout<<ans[i][j] + 1<<" "; cout<<"\n";}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}