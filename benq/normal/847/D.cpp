#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

int n,T, t[200001], ans[200001], fin = 0;

void solve1() {
    Tree<int> ti;
    vector<pii> vals;
    F0R(i,n+1) vals.pb({t[i],-i});
    sort(vals.begin(),vals.end());
    
    for (auto& a: vals) { // greater ones come before
        a.s *= -1;
        ti.insert(a.s);
        if (a.f+a.s >= T) ans[a.s] = -MOD;
        else ans[a.s] = ti.order_of_key(T-a.f)-ti.order_of_key(a.s);
    }
}

void solve2() {
    Tree<int> ti;
    vector<pii> vals;
    F0R(i,n+1) vals.pb({t[i],i});
    sort(vals.begin(),vals.end()); 
    
    for (auto& a: vals) {
        ti.insert(a.s);
        if (a.f+a.s < T && a.f >= 0) 
            fin = max(fin,(int)ti.order_of_key(a.s)+ans[a.s]);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> T;
    FOR(i,1,n+1) {
        cin >> t[i]; 
        t[i] -= i;
    }
    solve1();
    solve2();
    cout << fin-1;
}

// read!
// ll vs. int!