#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------

int n,p[500000],inv[500000];
struct segtree {
    int f,tree[1 << 20];
    int build(int s,int e,int i) {
        if (s == e) {
            tree[i] = f ? 1e9:-1;
            return 0;
        }

        int mid = (s+e) / 2;
        build(s,mid,2*i+1),build(mid+1,e,2*i+2);
        tree[i] = f ? 1e9:-1;
        return 0;
    }
    int update(int s,int e,int ai,int i,int num) {
        if ((s > ai) || (e < ai)) return 0;
        else if (s == e) {
            tree[i] = num;
            return 0;
        }

        int mid = (s+e) / 2;
        update(s,mid,ai,2*i+1,num),update(mid+1,e,ai,2*i+2,num);
        tree[i] = f ? min(tree[2*i+1],tree[2*i+2]):max(tree[2*i+1],tree[2*i+2]);
        return 0;
    }
    int query(int s,int e,int qs,int qe,int i) {
        if ((s > qe) || (e < qs)) return f ? 1e9:-1;
        else if ((s >= qs) && (e <= qe)) return tree[i];

        int mid = (s+e) / 2;
        return f ? min(query(s,mid,qs,qe,2*i+1),query(mid+1,e,qs,qe,2*i+2)):max(query(s,mid,qs,qe,2*i+1),query(mid+1,e,qs,qe,2*i+2));
    }
    int query(int s,int e) {
        return query(0,n-1,s,e,0);
    }
};
segtree q1,q2;
struct BIT {
    int a[500001];
    int update(int i,int num) {
        for (i++; i <= n; i += i & (-i)) a[i] += num;
        return 0;
    }
    int query(int i) {
        int sum = 0;
        for (i++; i > 0; i -= i & (-i)) sum += a[i];
        return sum;
    }
};
BIT bit1,bit2;
struct segtree2 {
    pii tree[1 << 20];
    int lazy[1 << 20],ss[1 << 20],ee[1 << 20];
    int build(int s,int e,int i) {
        if (s == e) {
            tree[i] = mp(1e9,s),lazy[i] = 0;
            ss[i] = 1e9,ee[i] = -1;
            return 0;
        }

        int mid = (s+e) / 2;
        build(s,mid,2*i+1),build(mid+1,e,2*i+2);
        tree[i] = mp(1e9,s),lazy[i] = 0;
        ss[i] = 1e9,ee[i] = -1;
        return 0;
    }
    int prop(int s,int e,int i) {
        if (lazy[i] != 0) {
            tree[i].first += lazy[i];
            if (s != e) lazy[2*i+1] += lazy[i],lazy[2*i+2] += lazy[i];
            lazy[i] = 0;
        }
        return 0;
    }
    int add(int s,int e,int as,int ae,int i,int l,int r,int num) {
        prop(s,e,i);
        if ((s > ae) || (e < as) || (ss[i] > r) || (ee[i] < l)) return 0;
        else if ((s >= as) && (e <= ae) && (ss[i] >= l) && (ee[i] <= r)) {
            lazy[i] += num;
            prop(s,e,i);
            return 0;
        }

        int mid = (s+e) / 2;
        add(s,mid,as,ae,2*i+1,l,r,num),add(mid+1,e,as,ae,2*i+2,l,r,num);
        tree[i] = min(tree[2*i+1],tree[2*i+2]);
        ss[i] = min(ss[2*i+1],ss[2*i+2]),ee[i] = max(ee[2*i+1],ee[2*i+2]);
        return 0;
    }
    int update(int s,int e,int ai,int i,int num) {
        prop(s,e,i);
        if ((s > ai) || (e < ai)) return 0;
        else if (s == e) {
            tree[i].first = num;
            if (num == 1e9) ss[i] = 1e9,ee[i] = -1;
            else ss[i] = ee[i] = p[ai];
            return 0;
        }

        int mid = (s+e) / 2;
        update(s,mid,ai,2*i+1,num),update(mid+1,e,ai,2*i+2,num);
        tree[i] = min(tree[2*i+1],tree[2*i+2]);
        ss[i] = min(ss[2*i+1],ss[2*i+2]),ee[i] = max(ee[2*i+1],ee[2*i+2]);
        return 0;
    }
};
segtree2 tree1,tree2;
set<int> S1,S2;
int main() {
    int i;
    scanf("%d",&n);
    q1.f = 1,q2.f = 0;
    q1.build(0,n-1,0),q2.build(0,n-1,0);
    for (i = 0; i < n; i++) {
        scanf("%d",&p[i]),inv[--p[i]] = i;
        if (p[i] >= i) q1.update(0,n-1,i,0,p[i]);
        else q2.update(0,n-1,i,0,p[i]);
    }

    tree1.build(0,n-1,0),tree2.build(0,n-1,0);
    int u = q1.query(0,n-1);
    while (u != 1e9) {
        u = inv[u];
        S1.insert(u),tree1.update(0,n-1,u,0,p[u]-u);
        u = q1.query(u+1,n-1);
    }
    u = q2.query(0,n-1);
    while (u != -1) {
        u = inv[u];
        S2.insert(u),tree2.update(0,n-1,u,0,u-p[u]);
        u = q2.query(0,u-1);
    }
    int ans = 0;
    for (i = 0; i < n; i++) {
        int u;
        if (tree1.tree[0].first < tree2.tree[0].first) {
            u = tree1.tree[0].second;
            ans = max(ans,tree1.tree[0].first);
            S1.erase(u),tree1.update(0,n-1,u,0,1e9);
            auto it = S1.upper_bound(u);
            int x = ((it == S1.end()) ? n:p[*it]);
            int v = q1.query((it == S1.begin()) ? 0:*prev(it)+1,u-1);
            while (v < x) {
                v = inv[v];
                S1.insert(v),tree1.update(0,n-1,v,0,p[v]-v+bit1.query(v)-bit2.query(p[v]));
                v = q1.query(v+1,u-1);
            }
        }
        else {
            u = tree2.tree[0].second;
            ans = max(ans,tree2.tree[0].first);
            S2.erase(u),tree2.update(0,n-1,u,0,1e9);
            auto it = S2.upper_bound(u);
            int x = ((it == S2.begin()) ? -1:p[*prev(it)]);
            int v = q2.query(u+1,(it == S2.end()) ? n-1:*it-1);
            while (v > x) {
                v = inv[v];
                S2.insert(v),tree2.update(0,n-1,v,0,v-p[v]-bit1.query(v)+bit2.query(p[v]));
                v = q2.query(u+1,v-1);
            }
        }
        bit1.update(u,1),bit2.update(p[u],1);
        tree1.add(0,n-1,0,u,0,p[u],n-1,-1),tree2.add(0,n-1,u,n-1,0,0,p[u],-1);
        if (p[u] >= u) q1.update(0,n-1,u,0,1e9);
        else q2.update(0,n-1,u,0,-1);
    }
    printf("%d\n",ans);

    return 0;
}