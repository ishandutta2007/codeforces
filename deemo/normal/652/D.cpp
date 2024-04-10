#include<iostream>
#include<algorithm>
#include<utility>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define Thing pair<pair<ll, ll>, ll>
#define L first.first
#define R first.second
#define ID second

const ll MAXN = 2e5 + 10;
const ll CC = 1e9 + 5;
const ll MAXVAL = 2e9 + 30;

ll n, ans[MAXN];
Thing vec[MAXN];
ordered_set st;

bool cmp(Thing a, Thing b){return a.R < b.R;}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	
	for (ll i = 0; i < n; i++)
		cin >> vec[i].L >> vec[i].R, vec[i].ID = i, vec[i].L += CC, vec[i].R += CC;
	sort(vec, vec + n, cmp);

	for (ll i = 0; i < n; i++){
		Thing v = vec[i];
		ans[v.ID] = (int)st.size() - (int)st.order_of_key({v.L, -1});
		st.insert({v.L, i});
	}

	for (ll i = 0; i < n; i++)
		cout << ans[i] << "\n";
	return	0;
}