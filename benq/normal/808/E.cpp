#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

vector<ll> k[4], cum[4];
ll ans = 0;
int s;

ll get(int a, int b) {
	return cum[1][a]+cum[2][b];	
}

ll solve(int w) {
	int lo = max(0,(w-(int)k[1].size()+1)/2), hi = min((int)k[2].size(),w/2);
	while (hi-lo>2) {
		int l1 = (2*lo+hi)/3, h1 = (lo+2*hi)/3;
		if (get(w-2*l1,l1) <= get(w-2*h1,h1)) lo = l1;
		else hi = h1;
	}
	if (lo>hi) return 0;
	return max(max(get(w-2*lo,lo),get(w-2*hi,hi)),get(w-2*((lo+hi)/2),(lo+hi)/2));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m; cin >> n >> m;
	F0R(i,n) {
		int w,c; cin >> w >> c;
		k[w].pb(c);
	}
	s = (int)k[1].size()+2*(int)k[2].size();
	FOR(i,1,4) {
		sort(k[i].begin(),k[i].end());
		reverse(k[i].begin(),k[i].end());
	}
	FOR(i,1,4) {
		cum[i].pb(0);
		for (int j: k[i]) {
			ll cur = j+cum[i][cum[i].size()-1];
			cum[i].pb(cur);
		}
	}
	// 11, 11,4
	F0R(i,cum[3].size()) {
		int x = min(m-3*i,s);
		if (x >= 0) ans = max(ans,cum[3][i]+solve(x));
		if (x-1 >= 0) ans = max(ans,cum[3][i]+solve(x-1));
	}
	cout << ans;
}