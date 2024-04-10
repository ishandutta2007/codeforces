#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include<set>
#include<algorithm>
#include<utility>
#include<vector>
#include<functional>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 2e3 + 10;

int n, vec[MAXN], cl[MAXN], cr[MAXN];
pair<int, int>	sec[MAXN];
ordered_set	st;

int main(){
	cin >> n;	
	for (int i = 0; i < n; i++){
		cin >> vec[i];	vec[i] = abs(vec[i]);
		cl[i] = st.order_of_key({vec[i], -1e9});
		st.insert({vec[i], i});
	}
	st.clear();
	for (int i = n - 1; i >= 0; i--){
		cr[i] = st.order_of_key({vec[i], -1e9});
		st.insert({vec[i], i});
		sec[i] = {vec[i], i};
	}

	sort(sec, sec + n, greater<pair<int, int>>());
	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += min(cl[i], cr[i]);
	cout << ans << "\n";
	return 0;
}