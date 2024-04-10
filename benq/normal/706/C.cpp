#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	string k[100000], k1[100000];
	ll c[100000], mincost[100000][2];
	ll mx = 10000000000000000;
	F0R(i,n) cin >> c[i];
	F0R(i,n) {
		cin >> k[i];
		k1[i] = k[i];
		reverse(k1[i].begin(),k1[i].end());
	}
	mincost[0][0] = 0; mincost[0][1] = c[0];
	FOR(i,1,n) {
		mincost[i][0] = mx;
		mincost[i][1] = mx;
		if (k[i] >= k[i-1] && mincost[i-1][0] < mx) mincost[i][0] = mincost[i-1][0];
		if (k[i] >= k1[i-1] && mincost[i-1][1] < mx) mincost[i][0] = min(mincost[i][0],mincost[i-1][1]);
		if (k1[i] >= k[i-1] && mincost[i-1][0] < mx) mincost[i][1] = mincost[i-1][0]+c[i];
		if (k1[i] >= k1[i-1] && mincost[i-1][1] < mx) mincost[i][1] =min(mincost[i][1],mincost[i-1][1]+c[i]);
	}
	ll ans = min(mincost[n-1][0], mincost[n-1][1]);
	if (ans<mx) cout << ans;
	else cout << -1;
	return 0;
}