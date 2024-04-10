#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;

const int MAXN = 3e6 + 100;
const int INF = 1e9 + 7;

int n, k;
ordered_set st;
pair<int, int>	vec[MAXN];
int sec[MAXN], sz;
vector<pair<int, int>>	ans;

bool cmp(pair<int, int>	a, pair<int, int>	b){
	if (a.first != b.first)	
		return	a.first < b.first;
	return	a.second < b.second;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++){
		scanf("%d%d", &vec[i].first, &vec[i].second);
		sec[sz++] = vec[i].first;
		sec[sz++] = vec[i].second;
	}
	sort(vec, vec + n, cmp);
	sort(sec, sec + sz);

	int b = 0;
	for (int i = 0; i < sz; i++){
		if (i){
			int temp;
			if (sec[i] != sec[i - 1])
				temp = st.size() - st.order_of_key({sec[i - 1], INF});
			else
				temp = st.size() - st.order_of_key({sec[i - 1], -INF});

			if (temp >= k)
				ans.push_back({sec[i - 1], sec[i]});
		}

		while (b < n && vec[b].first == sec[i])
			st.insert({vec[b++].second, b});
	}

	int cnt = 0;
	for (int i = 1; i < ans.size(); i++){
		if (ans[i - 1].second == ans[i].first){
			ans[i].first = ans[i - 1].first;
			ans[i - 1].first = INF;
			cnt++;
		}
	}

	cout << (int)ans.size() - cnt << endl;
	for (int i = 0; i < ans.size(); i++)
		if (ans[i].first != INF)
			cout << ans[i].first << " " << ans[i].second << endl;
	
	return 0;
}