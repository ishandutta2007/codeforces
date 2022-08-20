/*#include<iostream>
#include<fstream>
#include<set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<string>
#include<bitset>
#include<algorithm>
#include<vector>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

pair<double,pair<ll,ll>> best;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	best = mp(1000000007,mp(0,0));
	ll x,y,n; cin >> x >> y >> n;
	for (ll i = 1; i <= n; ++i) {
		ll num = (i*x)/y;
		best = min(best,mp(abs((double)num*y/i-x),mp(i,num)));
		best = min(best,mp(abs((double)(num+1)*y/i-x),mp(i,num+1)));
	}
	cout << best.s.s << "/" << best.s.f;
}