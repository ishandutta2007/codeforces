#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pii;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
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
 
int main() {
    ll n,f,sum=0; cin >> n >> f;
    vector<ll> posi;
    F0R(i,n) {
        ll k,l; cin >> k >> l;
        sum += min(k,l);
        posi.pb(min(2*k,l)-min(k,l));
    }
    sort(posi.begin(),posi.end()); reverse(posi.begin(),posi.end());
    F0R(i,f)  sum += posi[i];
    cout << sum;
}