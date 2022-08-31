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

int p[400000],ip[200001],a[300000],b[300000],del[300000];
vi order;
int op[500000],x[500000],nn[500000];
int ds[400000];
int find(int n) {
    if (ds[n] != n) ds[n] = find(ds[n]);
    return ds[n];
}
vi adjList[400000];
int disc[400000],fin[400000],num = 0;
int doDFS(int u) {
    int i;
    disc[u] = num++,order.pb(u);
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        doDFS(v);
    }
    fin[u] = num;
    return 0;
}
int tree[1 << 20];
int build(int s,int e,int i) {
    if (s == e) {
        tree[i] = p[order[s]];
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    tree[i] = max(tree[2*i+1],tree[2*i+2]);
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
    tree[i] = max(tree[2*i+1],tree[2*i+2]);
    return 0;
}
int query(int s,int e,int qs,int qe,int i) {
    if ((s > qe) || (e < qs)) return 0;
    else if ((s >= qs) && (e <= qe)) return tree[i];

    int mid = (s+e) / 2;
    return max(query(s,mid,qs,qe,2*i+1),query(mid+1,e,qs,qe,2*i+2));
}
int main() {
    int i;
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    for (i = 0; i < n; i++) scanf("%d",&p[i]),ip[p[i]] = i;
    for (i = 0; i < m; i++) scanf("%d %d",&a[i],&b[i]),a[i]--,b[i]--;
    for (i = 0; i < q; i++) {
        scanf("%d",&op[i]);
        if (op[i] == 1) scanf("%d",&x[i]),x[i]--;
        else scanf("%d",&x[i]),x[i]--,del[x[i]] = 1;
    }

    int z = n;
    for (i = 0; i < 2*n; i++) ds[i] = i;
    for (i = 0; i < m; i++) {
        if (!del[i]) {
            int u = a[i],v = b[i];
            if (find(u) != find(v)) {
                adjList[z].pb(find(u));
                adjList[z].pb(find(v));
                ds[find(u)] = z,ds[find(v)] = z++;
            }
        }
    }
    for (i = q-1; i >= 0; i--) {
        if (op[i] == 2) {
            int u = a[x[i]],v = b[x[i]];
            if (find(u) != find(v)) {
                adjList[z].pb(find(u));
                adjList[z].pb(find(v));
                ds[find(u)] = z,ds[find(v)] = z++;
            }
        }
        else nn[i] = find(x[i]);
    }
    for (i = 0; i < 2*n-1; i++) {
        if (find(i) == i) adjList[2*n-1].pb(i);
    }
    doDFS(2*n-1);
    build(0,2*n-1,0);
    for (i = 0; i < q; i++) {
        if (op[i] == 1) {
            int pp = query(0,2*n-1,disc[nn[i]],fin[nn[i]]-1,0);
            printf("%d\n",pp);
            if (pp != 0) update(0,2*n-1,disc[ip[pp]],0,0);
        }
    }

    return 0;
}