#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll MAXN = 1e6 + 10;

ll n, vec[MAXN];
map<ll, ll>	cnt;
ll a[MAXN], b[MAXN];
ordered_set	st;

int main()
{
	scanf("%d", &n);
	for (ll i = 0; i < n; i++){
		scanf("%d", &vec[i]);
		cnt[vec[i]]++;
		a[i] = cnt[vec[i]];
	}
	cnt.clear();
	for (ll i = n - 1; i >= 0; i--){
		cnt[vec[i]]++;
		b[i] = cnt[vec[i]];
	}

	ll ans = 0;
	for (ll i = n - 1; i >= 0; i--){
		ll x = a[i];
		ans += (ll)st.order_of_key(make_pair(x, -1));
		st.insert({b[i], i});
	}
	printf("%I64d\n", ans);
	return 0;
}