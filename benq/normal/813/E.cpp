// Persistent segment tree with lazy updates!

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

struct node {
    int val = 0, lazy = 0;
    node* c[2];
    
    void push(int L, int R) {
        if (!lazy) return;
        val += (R-L+1)*lazy;
        
        if (c[0]) {
            c[0] = new node(*c[0]);
            c[0]->lazy += lazy;
        }
        
        if (c[1]) { 
            c[1] = new node(*c[1]);
            c[1]->lazy += lazy;
        }
        
        lazy = 0;
    }
    
    int query(int low, int high, int L, int R) {  
        if (low <= L && R <= high) return val+lazy*(R-L+1);
        if (R < low || high < L) return 0;
        int M = (L+R)/2;
        return lazy*(min(high,R)-max(L,low)+1)+c[0]->query(low,high,L,M)+c[1]->query(low,high,M+1,R);
    }
    
    void upd(int low, int high, int v, int L, int R) {
        push(L,R);
        if (low <= L && R <= high) {
            lazy = v; push(L,R);
            return;
        }
        if (R < low || high < L) return;
        
        int M = (L+R)/2;
        c[0] = new node(*c[0]), c[1] = new node(*c[1]);
        c[0]->upd(low,high,v,L,M);
        c[1]->upd(low,high,v,M+1,R);
        val = c[0]->val+c[1]->val;
    }
    
    void build(vi& arr, int L, int R) {
        if (L == R) {
            if (L < (int)arr.size()) val = arr[L];
            else val = 0;
            return;
        }
        int M = (L+R)/2;
        c[0] = new node();
        c[0]->build(arr,L,M);
        c[1] = new node();
        c[1]->build(arr,M+1,R);
        val = c[0]->val+c[1]->val;
    }
};

template<int SZ> struct pers {
    node* loc[SZ+1]; // stores location of root after ith update
    int nex = 1;
    
    pers() { loc[0] = new node(); }
    
    void upd(int low, int high, int val) {
        loc[nex] = new node(*loc[nex-1]);
        loc[nex]->upd(low,high,val,0,SZ-1);
        nex++;
    }
    void build(vi& arr) { 
        loc[0]->build(arr,0,SZ-1);
    }
    int query(int ti, int low, int high) { 
        return loc[ti]->query(low,high,0,SZ-1);
    }
};

pers<100000> p;
int n,k, a[100000], pos[100000], lst;
vi nums[100001], st;

int main() {
    cin >> n >> k; 
    F0R(i,n) {
        cin >> a[i];
        pos[i] = nums[a[i]].size();
        if (pos[i] < k) st.pb(1);
        else st.pb(0);
        nums[a[i]].pb(i);
    }
    p.build(st);
    F0R(i,n) {
        if (nums[a[i]].size() > pos[i]+k) p.upd(nums[a[i]][pos[i]+k],nums[a[i]][pos[i]+k],1);
        else {
            p.upd(0, 0, 0);
        }
    }
    int q; cin >> q;
    F0R(i,q) {
        int x,y; cin >> x >> y;
        x = (x+lst) % n, y = (y+lst) % n;
        if (x > y) swap(x,y);
        lst = p.query(x,x,y);
        cout << lst << "\n";
    }
}