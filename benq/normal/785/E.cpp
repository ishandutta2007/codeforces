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

template<int SZ> struct mstree { 
    Tree<pii> val[SZ+1]; // for offline queries use vector with binary search instead
    
    void upd(int x, int y, int t = 1) { // x-coordinate between 1 and SZ inclusive
        for (int X = x; X <= SZ; X += X&-X) {
            if (t == 1) val[X].insert({y,x});
            else val[X].erase({y,x});
        }
    }
    
    int query(int x, int y) { 
        int t = 0;    
        for (;x > 0; x -= x&-x) t += val[x].order_of_key({y,MOD});
        return t;
    }
    
    int query(int lox, int hix, int loy, int hiy) { // query number of elements within a rectangle
        return query(hix,hiy)-query(lox-1,hiy)
            -query(hix,loy-1)+query(lox-1,loy-1);
    }
};

mstree<200000> M;

int N,Q;

ll ans = 0;
int nums[200001];

void process(int L, int R) {
    if (L > R) swap(L,R);
    int c1 = M.query(L+1,R-1,nums[L]+1,N); // how many greater in that range
    ans += 2*c1-(R-L-1);
    
    int c2 = M.query(L+1,R-1,1,nums[R]-1);
    ans += 2*c2-(R-L-1);
    
    if (nums[L] < nums[R]) ans++;
    else ans--;
    
    M.upd(L,nums[L],-1);
    M.upd(R,nums[L],1);
    M.upd(R,nums[R],-1);
    M.upd(L,nums[R],1);
    
    swap(nums[L],nums[R]);
}

int main() {
    cin >> N >> Q;
    FOR(i,1,N+1) {
        M.upd(i,i,1);
        nums[i] = i;
    }
    F0R(i,Q) {
        int L,R; cin >> L >> R;
        if (L != R) process(L,R);
        cout << ans << "\n";
    }
}

// read!
// ll vs. int!