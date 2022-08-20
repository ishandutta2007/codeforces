/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
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

int n,w,fin, h1;
pii a = {351960239,210979342}, b = {689283919,597079593};
pii val[200001], cum[200001];
pii des;

ll po(ll x, ll y) {
    if (y < 0) y += (MOD-1);
    
    ll ans = 1;
    while (y) {
        if(y&1) ans = (ans*x) % MOD;
        x = (x*x) % MOD;
        y /= 2;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> w;
	F0R(i,n) {
	    int h; cin >> h;
	    val[i] = {po(a.f,i)*po(a.s,h) % MOD,po(b.f,i)*po(b.s,h) % MOD};
	    cum[i+1].f = (cum[i].f+val[i].f) % MOD;
	    cum[i+1].s = (cum[i].s+val[i].s) % MOD;
	    
	}
	F0R(i,w) {
	    int h; cin >> h;
	    if (i == 0) h1 = h;
	    des.f = (des.f+po(a.f,i)*po(a.s,h)) % MOD;
	    des.s = (des.s+po(b.f,i)*po(b.s,h)) % MOD;
	}
	des.f = des.f*po(a.s,-h1) % MOD;
	des.s = des.s*po(b.s,-h1) % MOD;
	
	F0R(i,n-w+1) {
	    pii x = {(cum[i+w].f-cum[i].f+MOD)%MOD,(cum[i+w].s-cum[i].s+MOD)%MOD};
	    x.f = x.f*po(val[i].f,-1) % MOD;
	    x.s = x.s*po(val[i].s,-1) % MOD;
	    if (x == des) fin++;
	}
	cout << fin;
}