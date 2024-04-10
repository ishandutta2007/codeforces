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

int n,m;
char grid[200000];
int num[200000];
vi adjList[100000],adjList2[100000];
int in[100000],in2[100000];
int addEdge(int r,int c,int r2,int c2) {
    if ((r >= 0) && (r < n) && (c >= 0) && (c < m)) {
        int u = num[r*m+c],v = num[r2*m+c2];
        if ((r+c) & 1) adjList[u].pb(v),in[v]++;
        else adjList2[u].pb(v),in2[v]++;
    }
    return 0;
}
int tree[1 << 18],lazy[1 << 18],occ[1 << 18];
int build(int s,int e,int i) {
    if (s == e) {
        tree[i] = lazy[i] = 0,occ[i] = 1;
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    tree[i] = lazy[i] = 0,occ[i] = e-s+1;
    return 0;
}
int prop(int s,int e,int i) {
    tree[i] += lazy[i];
    if (s != e) lazy[2*i+1] += lazy[i],lazy[2*i+2] += lazy[i];
    lazy[i] = 0;
    return 0;
}
int update(int s,int e,int as,int ae,int i,int num) {
    prop(s,e,i);
    if ((s > ae) || (e < as)) return 0;
    else if ((s >= as) && (e <= ae)) {
        lazy[i] += num;
        prop(s,e,i);
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1,num),update(mid+1,e,as,ae,2*i+2,num);
    tree[i] = min(tree[2*i+1],tree[2*i+2]);
    occ[i] = ((tree[i] == tree[2*i+1]) ? occ[2*i+1]:0)+((tree[i] == tree[2*i+2]) ? occ[2*i+2]:0);
    return 0;
}
int disc[100000],fin[100000],c = 0;
LLI ans = 0;
int doDFS(int u) {
    int i;
    disc[u] = c++;
    for (i = 0; i < adjList2[u].size(); i++) doDFS(adjList2[u][i]);
    fin[u] = c;
    return 0;
}
int doDFS2(int u) {
    int i;
    update(0,n*m/2,disc[u],fin[u]-1,0,1);
    ans += n*m/2+1-occ[0];
    for (i = 0; i < adjList[u].size(); i++) doDFS2(adjList[u][i]);
    update(0,n*m/2,disc[u],fin[u]-1,0,-1);
    return 0;
}
int main() {
    int i,j;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) scanf(" %c",&grid[i*m+j]);
    }

    int c = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (grid[i*m+j] == 'L') num[i*m+j] = num[i*m+j+1] = c++;
            else if (grid[i*m+j] == 'U') num[i*m+j] = num[(i+1)*m+j] = c++;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (grid[i*m+j] == 'L') addEdge(i,j+2,i,j);
            else if (grid[i*m+j] == 'R') addEdge(i,j-2,i,j);
            else if (grid[i*m+j] == 'U') addEdge(i+2,j,i,j);
            else addEdge(i-2,j,i,j);
        }
    }
    build(0,n*m/2,0);
    for (i = 0; i < c; i++) {
        if (in2[i] == 0) doDFS(i);
    }
    for (i = 0; i < c; i++) {
        if (in[i] == 0) doDFS2(i);
    }
    printf("%I64d\n",ans);

    return 0;
}