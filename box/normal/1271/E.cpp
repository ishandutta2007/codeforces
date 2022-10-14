// writer: piggydan
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using ordered_set=tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;
/*
ifstream fin("x.in");
ofstream fout("x.out");
#define cin fin
#define cout fout
*/

ll n, k;

int test(ll p) {
	ll i = 0, ans = 0;
	if(p % 2 == 0) {
		p >>= 1;
		ans = -1;
	}
	while(n >= p*(1ull<<i)) {
		ans += min(n-p*(1ull<<i)+1, 1ull<<i);
		i++;
	}
	return (ans >= k);
}



signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	ll Ans = -1;
	rep(mo, 2) {
		ll low = 1, high = n+1, ans = -1;
		while(low <= high) {
			ll mid = (low + high)/2;
			if(test(2 * mid - mo)) {
				low = mid+1;
				ans = 2 * mid - mo;
			} else high = mid-1;
		}
		Ans = max(Ans, ans);
	}
	cout << Ans << endl;
}