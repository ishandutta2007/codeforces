#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

int n,m,k;
vector<pair<int,pii>> v1, v2;
pll a1[1000002], a2[1000002];
int bes[100001];
ll ans = 1e18;

void gen() {
    sort(v1.begin(),v1.end());
    int nex = 0;
    FOR(i,1,1000001) {
        a1[i] = a1[i-1];
        while (nex < (int)v1.size() && v1[nex].f == i) {
            if (bes[v1[nex].s.f] == 0) {
                bes[v1[nex].s.f] = v1[nex].s.s;
                a1[i].s ++;
                a1[i].f += bes[v1[nex].s.f];
            } else {
                a1[i].f -= bes[v1[nex].s.f];
                bes[v1[nex].s.f] = min(bes[v1[nex].s.f],v1[nex].s.s);
                a1[i].f += bes[v1[nex].s.f];
            }
            nex ++;
        }
    }
    
    sort(v2.begin(),v2.end()); reverse(v2.begin(),v2.end());
    nex = 0; memset(bes,0,sizeof bes);
    FORd(i,1,1000001) {
        a2[i] = a2[i+1];
        while (nex < (int)v2.size() && v2[nex].f == i) {
            if (bes[v2[nex].s.f] == 0) {
                bes[v2[nex].s.f] = v2[nex].s.s;
                a2[i].s ++;
                a2[i].f += bes[v2[nex].s.f];
            } else {
                a2[i].f -= bes[v2[nex].s.f];
                bes[v2[nex].s.f] = min(bes[v2[nex].s.f],v2[nex].s.s);
                a2[i].f += bes[v2[nex].s.f];
            }
            nex ++;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> k;
	F0R(i,m) {
	    int d,f,t,c; cin >> d >> f >> t >> c;
	    if (t == 0) v1.pb({d,{f,c}});
	    else v2.pb({d,{t,c}});
	}
	gen();
	F0R(i,1000001) if (i+k+1 <= 1000000 && a1[i].s == n && a2[i+k+1].s == n) 
	    ans = min(ans,a1[i].f+a2[i+k+1].f);
	
	if (ans == 1e18) cout << -1;
	else cout << ans;
}

// read!
// ll vs. int!