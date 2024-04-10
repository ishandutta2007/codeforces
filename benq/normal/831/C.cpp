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

ll k,n, cum[2001];
vector<ll> a;
multiset<ll> b;
set<ll> posi;

bool test(ll z) {
    vector<ll> temp;
    FOR(i,1,k+1) temp.pb(z+cum[i]);
    
    auto b1 = b;
    F0Rd(i,temp.size()) {
        if (b1.size() == 0) break;
        if (b1.find(temp[i]) != b1.end()) b1.erase(b1.find(temp[i]));
    }
    
    if (b1.size() == 0) return 1;
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> k >> n;
	a.resize(k);
	
    F0R(i,k) {
        cin >> a[i];
        cum[i+1] = cum[i]+a[i];
    }
    
    F0R(i,n) {
        ll x; cin >> x;
        b.insert(x);
    }
    
    FOR(i,1,k+1) if (test(*b.begin()-cum[i])) posi.insert(*b.begin()-cum[i]);
    cout << posi.size();
}