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

const int MOD = 1000000007;
double PI = 4*atan(1);

int n,k; 
ll ans = 0;

struct {
	ll sum = 0, numchild = 0;
	ll rem[5] = {0,0,0,0,0};
	vi adj;
} node[200001];

void dfs(int par, int cur) {
	for (int i: node[cur].adj) if (i != par) {
		dfs(cur,i);
		
		ll temp = node[cur].numchild*(node[i].numchild+node[i].sum);
		temp += node[i].numchild*node[cur].sum;
		
		ll co[5]; F0R(i1,5) co[i1] = 0;
		
		F0R(i1,k) F0R(i2,k) co[(i1+i2+1)%k] += node[cur].rem[i1]*node[i].rem[i2];
		FOR(i1,1,k) temp += (k-i1)*co[i1];
		ans += temp/k;
		
		node[cur].sum += (node[i].numchild+node[i].sum);
		node[cur].numchild += node[i].numchild;
		
		F0R(i1,k) node[cur].rem[(i1+1) % k] += node[i].rem[i1];
	}
	ll temp = node[cur].sum;
	FOR(i,1,k) temp += (k-i)*node[cur].rem[i];
	ans += temp/k;
	node[cur].numchild++;
	node[cur].rem[0] ++;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	F0R(i,n-1) {
		int x,y; cin >> x >> y;
		node[x].adj.pb(y);
		node[y].adj.pb(x);
	}
	dfs(0,1);
	cout << ans;
}