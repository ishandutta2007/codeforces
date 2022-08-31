#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
const ll INF = 1e18;

int n;
ll a[5005], sum[5005];
pair<ll,pair<pii,int>> bes = {-INF,{{0,0},0}};

pair<ll,pii> get(int ind) {
    // excluding the first ind elements 
    // sum[ind] to sum[n]
    pair<ll,pii> b = {-INF,{0,0}};
    pll mn = {INF,0};
    FOR(i,ind,n+1) {
        mn = min(mn,{sum[i],i});
        if (sum[i]-mn.f > b.f) b = {sum[i]-mn.f,{mn.s,i}};
    }
    return b;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; 
	FOR(i,1,n+1) {
    	cin >> a[i];
    	sum[i] = a[i]+sum[i-1];
	}
	F0R(i,n+1) {
	    pair<ll,pii> op = get(i);
	    if (op.f+sum[i] > bes.f) bes = {op.f+sum[i],{{i,op.s.f},op.s.s}};
	}
	cout << bes.s.f.f << " " << bes.s.f.s << " " << bes.s.s;
}

// read!
// ll vs. int!