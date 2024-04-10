#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
#define bignum vector <int>
 
 
using namespace std;
const int nax = 1001;
int n;
int t[nax][nax];

int main() {
	ios;
	cin >> n;
	FOR(i, 1, n)
		FOR(j, 1, n)
			cin >> t[i][j];
	
	ll xd = (ll) t[1][2] * t[1][3] / t[2][3];
	ll L = sqrt(xd) - 30;
	ll R = sqrt(xd) + 30;
	ll y = -1;
	for(ll x = L; x <= R; ++x) {
		if(x > 0 && x * x == xd) {
			y = x;
			break;
		}
	}
	
	assert(y != -1);
	
	cout << y << " ";
	FOR(i, 2, n)
		cout << t[1][i] / y << " ";
	
	
	
	return 0;
}