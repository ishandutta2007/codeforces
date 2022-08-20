/*#include <ext/pb_ds/assoc_container.hpp> 
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

const int MOD = 1000000007;
double PI = 4*atan(1);

int n, a[100001], par[100001], sz[100001];
vi ans[100001];
map<int,int> x;

int getpar(int z) {
    if (par[par[z]] != par[z]) par[z] = getpar(par[z]);
    return par[z];
}

void unite(int a, int b) {
    a = getpar(a), b = getpar(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a,b);
    sz[a] = max(sz[a],sz[b]+1);
    par[b] = a;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	FOR(i,1,n+1) {
	    cin >> a[i];
	    x[a[i]] = 0;
	}
	
	int co = 0;
	for (auto& a: x) a.s = ++co;
	FOR(i,1,n+1) par[i] = i;
	FOR(i,1,n+1) unite(i,x[a[i]]);
	FOR(i,1,n+1) ans[getpar(i)].pb(i);
	
	co = 0;
	FOR(i,1,n+1) if (ans[i].size()) co++;
	cout << co << "\n";
	FOR(i,1,n+1) if (ans[i].size()) {
	    cout << ans[i].size() << " ";
	    for (int j: ans[i]) cout << j << " ";
	    cout << "\n";
	}
}

// read!
// ll vs. int!