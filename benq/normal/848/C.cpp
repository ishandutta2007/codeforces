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
const int SZ = 100005;

// position 1: start 
// positions 2 to n+1: middle
// position n+2: end

int n,m, A[SZ];
set<int> nums[SZ];
unordered_map<int,ll> vals[SZ];

void upd(int x, int Y, int val) {
    for (;x <= SZ-1; x += (x&-x))
        for (int y = Y; y <= SZ-1; y += (y&-y)) {
            vals[x][y] += val;
        }
}

ll query(int x, int Y) {
    ll tmp = 0;
    for (;x > 0; x -= (x&-x))
        for (int y = Y; y > 0; y -= (y&-y)) {
            if (vals[x].count(y)) tmp += vals[x][y];
        }
    return tmp;
}

ll query(int lox, int hix, int loy, int hiy) {
    return query(hix,hiy)-query(hix,loy-1)-query(lox-1,hiy)+query(lox-1,loy-1);
}

void change(int pos, int x) {
    int p1 = *prev(nums[A[pos]].find(pos)), p2 = *next(nums[A[pos]].find(pos));
    nums[A[pos]].erase(pos);  
    
    if (p1 != 1) upd(p1,pos,-(pos-p1)); 
    if (p2 != n+2) upd(pos,p2,-(p2-pos));
    if (p1 != 1 && p2 != n+2) upd(p1,p2,p2-p1);
    
    A[pos] = x; nums[x].insert(pos);
    p1 = *prev(nums[x].find(pos)), p2 = *next(nums[x].find(pos));
    
    if (p1 != 1) upd(p1,pos,pos-p1); 
    if (p2 != n+2) upd(pos,p2,p2-pos);
    if (p1 != 1 && p2 != n+2) upd(p1,p2,-(p2-p1));
}

void init() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	FOR(i,1,n+1) nums[i].insert(1), nums[i].insert(n+2);
	FOR(i,2,n+2) {
	    cin >> A[i];
	    nums[A[i]].insert(i);
	}
	FOR(i,1,n+1) {
        for (int a: nums[i]) if (a != 1 && a != n+2) {
            int x = *prev(nums[i].find(a));
            upd(x,a,a-x);
        }
    }
}

int main() {
	init();
	F0R(i,m) {
	    int t; cin >> t;
	    if (t == 1) {
	        int p,x; cin >> p >> x; 
	        change(p+1,x);
	    } else {
	        int l,r; cin >> l >> r; 
	        cout << query(l+1,r+1,l+1,r+1) << "\n";
	    }
	}
}

// read!
// ll vs. int!