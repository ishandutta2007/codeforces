#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,k; cin >> n >> k;	
	ll par[100000][34], mn[100000][34], sum[100000][34];
	F0R(i,n) cin >> par[i][0];
	F0R(i,n) {
		cin >> mn[i][0];
		sum[i][0] = mn[i][0];
	}
	FOR(i,1,34) F0R(j,n) {
		par[j][i] = par[par[j][i-1]][i-1];
		mn[j][i] = min(mn[j][i-1],mn[par[j][i-1]][i-1]);
		sum[j][i] = sum[j][i-1]+sum[par[j][i-1]][i-1];
	}
	F0R(i,n) {
		ll sa = 0, ma = 1000000007, cur = i,k1 = k;
		F0R(j,34) {
			if (k1 & (ll)1) {
				ma = min(ma,mn[cur][j]);
				sa += sum[cur][j];
				cur = par[cur][j];
			}
			k1 /= 2;
		}
		cout << sa << " " << ma << "\n";
	}
}