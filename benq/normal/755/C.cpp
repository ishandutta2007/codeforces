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

int par[10001], ans;

int getpar(int node) {
    if (par[par[node]] == par[node]) return par[node];
    return par[node] = getpar(par[node]);
}

void unio(int a, int b) {
    a = getpar(a), b = getpar(b);
    if (a == b) return;
    if (a>b) swap(a,b);
    ans--;
    par[b] = a;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	ans = n;
	FOR(i,1,n+1) par[i] = i;
	FOR(i,1,n+1) {
	    int x; 
	    cin >> x;
	    unio(i,x);
	}
	cout << ans;
}

// ll vs. int!
// read!