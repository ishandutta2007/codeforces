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

int n, a[100001],lst[100001], nex[100001];
vi A;

struct node {
    int val = 0;
    node* c[2];
    
    int query(int hi, int L, int R) {  // first one which is greater than hi 
        if (L == R) {
            if (val > hi) return L;
            return n+1;
        }
        int M = (L+R)/2;
        if (c[0]->val <= hi) return c[1]->query(hi-c[0]->val,M+1,R);
        else return c[0]->query(hi,L,M);
    }
    
    void upd(int ind, int v, int L, int R) {
        if (L == ind && R == ind) {
            val += v;
            return;
        }
        if (R < ind || ind < L) return;
        
        int M = (L+R)/2;
        c[0] = new node(*c[0]), c[1] = new node(*c[1]);
        c[0]->upd(ind,v,L,M);
        c[1]->upd(ind,v,M+1,R);
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
    
    void upd(int ind, int val) {
        loc[nex] = new node(*loc[nex-1]);
        loc[nex]->upd(ind,val,0,SZ-1);
        nex++;
    }
    void build(vi& arr) { 
        loc[0]->build(arr,0,SZ-1);
    }
    int query(int ti, int hi) { 
        return loc[ti]->query(hi,0,SZ-1);
    }
};

pers<100001> p;

void solve(int x) {
    int ans = 0, cur = 0;
    while (cur != n) {
        cur = p.query(cur,cur+x)-1;
        ans++;
    }
    cout << ans << " ";
}

int main() {
    cin >> n; A.resize(n+1);
    FOR(i,1,n+1) {
        cin >> a[i];
        if (lst[a[i]]) nex[lst[a[i]]] = i;
        else A[i] = 1;
        lst[a[i]] = i;
    }
    p.build(A);
    FOR(i,1,n+1) {
        if (nex[i]) p.upd(nex[i],1);
        else {
            p.loc[i] = p.loc[i-1];
            p.nex++;
        }
    }
    FOR(i,1,n+1) solve(i);
}