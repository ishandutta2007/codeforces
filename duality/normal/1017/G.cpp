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

int p[100000];
vi adjList[100000];
int size[100000],heavy[100000];
int chain[100000],head[100000],disc[100000],fin[100000],csize[100000],num = 0,c = 0;
int doDFS(int u) {
    int i;
    size[u] = 1,heavy[u] = -1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        size[u] += doDFS(v);
        if ((heavy[u] == -1) || (size[v] > size[heavy[u]])) heavy[u] = v;
    }
    return 0;
}
int doHLD(int u) {
    int i;
    chain[u] = c,disc[u] = num++;
    if (csize[c] == 0) head[c] = u;
    csize[c]++;
    if (heavy[u] != -1) doHLD(heavy[u]);
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != heavy[u]) c++,doHLD(v);
    }
    fin[u] = num;
    return 0;
}
pii tree[1 << 18];
int lazy[1 << 18];
pii com(pii a,pii b) {
    if (a == mp((int) 1e9,(int) 1e9)) return b;
    else if (b == mp((int) 1e9,(int) 1e9)) return a;
    else return mp(a.first+b.first,max(b.second,a.second+b.first));
}
int build(int s,int e,int i) {
    if (s == e) {
        tree[i] = mp(-1,-1),lazy[i] = 1e9;
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    tree[i] = com(tree[2*i+1],tree[2*i+2]),lazy[i] = 1e9;
    return 0;
}
int prop(int s,int e,int i) {
    if (lazy[i] != 1e9) {
        tree[i] = mp((e-s+1)*lazy[i],max(lazy[i],(e-s+1)*lazy[i]));
        if (s != e) lazy[2*i+1] = lazy[2*i+2] = lazy[i];
        lazy[i] = 1e9;
    }
    return 0;
}
int update(int s,int e,int as,int ae,int i,int num,int t) {
    prop(s,e,i);
    if ((s > ae) || (e < as)) return 0;
    else if ((s >= as) && (e <= ae)) {
        lazy[i] = (t == 2) ? tree[i].first+num:num;
        prop(s,e,i);
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1,num,t),update(mid+1,e,as,ae,2*i+2,num,t);
    tree[i] = com(tree[2*i+1],tree[2*i+2]);
    return 0;
}
pii query(int s,int e,int qs,int qe,int i) {
    prop(s,e,i);
    if ((s > qe) || (e < qs)) return mp((int) 1e9,(int) 1e9);
    else if ((s >= qs) && (e <= qe)) return tree[i];

    int mid = (s+e) / 2;
    return com(query(s,mid,qs,qe,2*i+1),query(mid+1,e,qs,qe,2*i+2));
}
pii querypath(int u,int n) {
    pii q = mp((int) 1e9,(int) 1e9);
    while (u != -1) q = com(query(0,n-1,disc[head[chain[u]]],disc[u],0),q),u = p[head[chain[u]]];
    return q;
}
int main() {
    int i;
    int n,q,t,v;
    scanf("%d %d",&n,&q);
    p[0] = -1;
    for (i = 1; i < n; i++) scanf("%d",&p[i]),adjList[--p[i]].pb(i);
    doDFS(0),doHLD(0);
    build(0,n-1,0);
    for (i = 0; i < q; i++) {
        scanf("%d %d",&t,&v),v--;
        if (t == 1) update(0,n-1,disc[v],disc[v],0,1,2);
        else if (t == 2) {
            pii q = querypath(p[v],n);
            update(0,n-1,disc[v],fin[v]-1,0,-1,1);
            if ((v != 0) && (q.second > 0)) update(0,n-1,disc[v],disc[v],0,-q.second,2);
        }
        else {
            pii q = querypath(v,n);
            printf((q.second >= 0) ? "black\n":"white\n");
        }
    }

    return 0;
}