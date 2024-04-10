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
const int SZ = 2500;

int n,m,q;

struct BIT2D { 
    ll bit[SZ+1][SZ+1];
    void upd(int X, int Y, ll val) {
        for (; X <= SZ; X += (X&-X))
            for (int Y1 = Y; Y1 <= SZ; Y1 += (Y1&-Y1))
                bit[X][Y1] ^= val;
    }
    ll query(int X, int Y) {
        ll ans = 0;
        for (; X > 0; X -= (X&-X))
            for (int Y1 = Y; Y1 > 0; Y1 -= (Y1&-Y1))
                ans ^= bit[X][Y1];
        return ans;
    }
};

BIT2D B;

map<pair<pii,pii>,ll> hsh;

ll gen() {
    ll x = rand();
    x ^= ((ll)rand()<<15);
    x ^= ((ll)rand()<<30);
    x ^= ((ll)rand()<<45);
    return x;
}

int main() {
    srand(time(0));
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> q;
	F0R(i,q) {
	    int t,r1,c1,r2,c2; cin >> t >> r1 >> c1 >> r2 >> c2;
	    if (t == 1) {
	        ll val = 0;
	        val = hsh[{{r1,c1},{r2,c2}}] = gen();
	        B.upd(r1,c1,val);
	        B.upd(r1,c2+1,val);
	        B.upd(r2+1,c1,val);
	        B.upd(r2+1,c2+1,val);
	    } else if (t == 2) {
	        ll val = hsh[{{r1,c1},{r2,c2}}];
	        B.upd(r1,c1,val);
	        B.upd(r1,c2+1,val);
	        B.upd(r2+1,c1,val);
	        B.upd(r2+1,c2+1,val);
	    } else {
	        if (B.query(r1,c1) == B.query(r2,c2)) cout << "Yes";
	        else cout << "No";
	        cout << "\n";
	    }
	}
}

// read!
// ll vs. int!