#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#include <ext/pb_ds/assoc_container.hpp> //  . 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

typedef __gnu_pbds::tree<
int,
__gnu_pbds::null_type,
less<int>,
__gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update>
ordered_set;

struct Query{int x; int y; int ind;};

bool cmp(Query &a, Query &b){
	return (a.x < b.x);
}

bool cmp2(pair<int, int> &a, pair<int, int> &b){
	if (a.first != b.first) return (a.first > b.first);
	return (a.second < b.second);
}

int main(){
#ifdef LOCAL
	freopen("M_input.txt", "r", stdin);
	//freopen("M_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int> > v;
	vector<int> arr;
	for (int i=0;i<n;++i){
		int x;
		cin >> x;
		arr.push_back(x);
		v.push_back({x, i});
	}

	sort(v.begin(), v.end(), cmp2);

	vector<Query> kek;

	int q;
	cin >> q;
	for (int i=0;i<q;++i){
		int k, pos;
		cin >> k >> pos;
		kek.push_back({k-1, pos, i});
	}

	sort(kek.begin(), kek.end(), cmp);
	ordered_set ms;
	int u=0;

	vector<int> ans(q);

	for (int i=0; i < n; ++i){
		ms.insert(v[i].second);
		while (u < q && kek[u].x == i) {
			int I = kek[u].ind;
			int N = kek[u].y - 1;
			int T = (*ms.find_by_order(N));
			ans[I] = arr[T];
			u++;
		}
	}
	for (int i=0;i<q;++i) cout << ans[i] << "\n";
	

}