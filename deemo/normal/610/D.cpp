#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define Seg pair<pair<ll, ll>, ll>
#define left first.first
#define right first.second
#define down first.first
#define top first.second

const ll INF = 1e18 + 5;

ll ans;
ll n;
ordered_set	st;
set<pair<pair<ll, ll>, ll>>	secst;
vector<Seg>	row, col;

bool cmp(Seg a, Seg b){
	if (a.second != b.second)
		return	a.second < b.second;
	return	a.first < b.first;
}

bool cmp2(Seg a, Seg b){
	if (a.left != b.left)
		return	a.left < b.left;
	if (a.right != b.right)
		return	a.right < b.right;
	return	a.second < b.second;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++){
		ll a, b, c, d;	cin >> a >> b >> c >> d;
		if (b > d){
			swap(b, d);
			swap(a, c);
		}
		if (a > c){
			swap(a, c);
			swap(b, d);
		}
		if (b == d)
			row.push_back({{a, c}, b}); 
		else
			col.push_back({{b, d}, a});
	}
	sort(row.begin(), row.end(), cmp);
	sort(col.begin(), col.end(), cmp);
	for (ll i = 1; i < row.size(); i++)
		if (row[i - 1].second == row[i].second && row[i].left <= row[i - 1].right){
			row[i].right = max(row[i].right, row[i - 1].right);
			row[i].left = min(row[i].left, row[i - 1].left);
			row[i - 1].left = INF;
		}
	for (ll i = 1; i < col.size(); i++)
		if (col[i - 1].second == col[i].second && col[i].down <= col[i - 1].top){
			col[i].down = min(col[i].down, col[i - 1].down);
			col[i].top = max(col[i].top, col[i - 1].top);
			col[i - 1].down = INF;
		}

	for (ll i = 0; i < row.size(); i++)
		if (row[i].left != INF)
			ans += row[i].right - row[i].left + 1;
	sort(row.begin(), row.end(), cmp2);

	ll b = 0, cn = 0;
	for (Seg v:col){
		if (v.down == INF)	continue;
		cn++;

		while (b < row.size() && v.second >= row[b].left){
			if (row[b].left != INF){
				secst.insert({{row[b].right, row[b].second}, cn});
				st.insert({row[b].second, cn++});
			}
			b++;
		}

		while (secst.size()){
			set<pair<pair<ll, ll>, ll>>::iterator it = secst.begin();
			if ((*it).first.first < v.second){
				st.erase({(*it).first.second, (*it).second});
				secst.erase(it);
			}
			else
				break;	
		}

		ll t = st.order_of_key({v.top, INF}) - st.order_of_key({v.down - 1, INF});
		ans += v.top - v.down + 1 - t;
	}
	cout << ans << endl;
	return 0;
}