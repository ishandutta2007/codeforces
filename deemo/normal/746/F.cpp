#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, greater<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define F first
#define S second

const int INF = 1e9 + 4;
const int MAXN = 2e5 + 10;

int n, k, ln, val[MAXN], t[MAXN], pt[MAXN], pval[MAXN];
ordered_set st;
int r, ans, sm;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> ln;
	for (int i = 0; i < n; i++)	cin >> val[i], pval[i + 1] = pval[i] + val[i];
	for (int i = 0; i < n; i++)	cin >> t[i], pt[i + 1] = pt[i] + t[i];

	r = n;
	for (int i = n - 1; ~i; i--){
		{
			int pos = st.order_of_key(make_pair(t[i], i));
			if (pos < k){
				if (st.size() >= k)
					sm -= st.find_by_order(k-1)->F>>1;
				sm += t[i]>>1;
			}
			st.insert(make_pair(t[i], i));
		}

		while (pt[r] - pt[i] - sm > ln){
			r--;
			st.erase(make_pair(t[r], r));
			int pos = st.order_of_key(make_pair(t[r], r));
			if (pos < k){
				sm -= t[r]>>1;
				if (st.size() >= k)
					sm += st.find_by_order(k-1)->F>>1;
			}
		}

		ans = max(ans, pval[r] - pval[i]);
	}

	cout << ans << "\n";
	//cout << *s.find_by_order(0) << "\n";
	//cout << s.order_of_key(2) << "\n";
	return 0;
}