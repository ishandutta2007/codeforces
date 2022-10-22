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
 
 
using namespace std;	

const int nax = 2e5 + 111;
ll n;
pair<ll, ll> a[nax];
ll ans = 0;
vector <int> ind;
bool byl[nax];

int main() {
	scanf("%lld", &n);
	FOR(i, 1, n) {
		scanf("%lld", &a[i].fi);
	}
	FOR(i, 1, n)
		scanf("%lld", &a[i].se);
	
	sort(a + 1, a + n + 1);
	FOR(i, 1, n) {
		if(i > 1 && a[i].fi == a[i - 1].fi) {
			ans += a[i].se;
			for(auto it : ind) {
				if(byl[it])
					continue;
				if((a[it].fi & a[i].fi) == a[it].fi) {
					byl[it] = 1;
					ans += a[it].se;
				}
			}
		}
		else {
			ind.pb(i);
		}
	}
	cout << ans;
		
	
	
		
	
	
	
	return 0;
}