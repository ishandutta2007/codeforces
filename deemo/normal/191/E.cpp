#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 1e5 + 10;

ll n, val[MAXN];
ll k, ss;
ordered_set st;

ll cnt(ll mid){
	ll ret = 0;
	ss = 0;
	st.clear();

	for (int i = 0; i < n; i++){
		ss += val[i];
		st.insert({val[i] - ss, i});
		
		ret += (int)st.size() - st.order_of_key({mid - ss, -1});
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> val[i];

	ll b = -1e18, e = 1e18, ret = -1e18;
	while (b <= e){
		ll mid = (b + e)/ 2;
		if (cnt(mid) >= k)	
			ret = mid, b = mid + 1;
		else
			e = mid - 1;
	}
	cout << ret << "\n";
	return 0;
}