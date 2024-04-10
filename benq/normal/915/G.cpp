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
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const int MX = 2000001;

int n, k, comp[MX];
ll ans = 0;
vi divi[MX];

void gen() {
    FOR(i,2,MX) if (!comp[i]) for (int j = 2*i; j < MX; j += i) comp[j] = 1;
    FOR(i,2,MX) if (comp[i] == 0) {
        // cout << i << "\n";
        for (int j = i; j < MX; j += i) {
            divi[j].pb(i);
        }
    }
}

ll cur = 0;
ll PO[2000001];

ll po (ll b, ll p) {
    return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD;
}

void search(int ind, int cpos, vi& t, int prod, int tmp) {
    if (cpos == sz(t)) {
        cur -= tmp*PO[ind/prod-1];
        cur += tmp*PO[ind/prod];
        return;
    }
    search(ind,cpos+1,t,prod*t[cpos],-tmp);
    search(ind,cpos+1,t,prod,tmp);
}

void calc(int ind) {
    search(ind,0,divi[ind],1,1);
    cur = (cur%MOD+MOD)%MOD;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	gen();
	cin >> n >> k;
	FOR(i,1,MX) PO[i] = po(i,n);
	FOR(i,1,k+1) {
	    calc(i);
	    ans = ans+(cur^i);
	}
	cout << ans%MOD;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!