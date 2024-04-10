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
const int SZ = 1000;
int n,m;

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
    ll query(int X1, int X2, int Y1, int Y2) {
        return query(X2,Y2)^query(X1-1,Y2)^query(X2,Y1-1)^query(X1-1,Y1-1);
    }
};

BIT2D bit[2][2];

void upd(int x, int y, ll v) {
    if (x == 0 || y == 0) return;
    bit[0][0].upd(x,y,v);
    if (x&1) bit[1][0].upd((x+1)/2,y,v);
    if (y&1) bit[0][1].upd(x,(y+1)/2,v);
    if ((x&1)&(y&1)) bit[1][1].upd((x+1)/2,(y+1)/2,v);
}

ll query(int x, int y) {
    ll ans = 0;
    
    // those completely inside, with both odd components
    ans ^= bit[1][1].query((x+1)/2,(y+1)/2);
    
    // those outside with the odd component
    if (x&1) ans ^= bit[0][1].query(x+1,1000,1,(y+1)/2);
    
    // those outside with the other odd component 
    if (y&1) ans ^= bit[1][0].query(1,(x+1)/2,y+1,1000);
    
    // those completely outside
    if ((x&1)&(y&1)) ans ^= bit[0][0].query(x+1,1000,y+1,1000);
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	F0R(i,m) {
	    int t; cin >> t;
	    if (t == 1) {
	        int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
	        cout << (query(x1,y1)^query(x1,y0-1)^query(x0-1,y1)^query(x0-1,y0-1)) << "\n";
	    } else {
	        int x0, y0, x1, y1; ll v; 
	        cin >> x0 >> y0 >> x1 >> y1 >> v;
	        upd(x1,y1,v); // 3,3
	        upd(x1,y0-1,v); 
	        upd(x0-1,y1,v); // 2,3
	        upd(x0-1,y0-1,v);
	    }
	}
}

// read!
// ll vs. int!