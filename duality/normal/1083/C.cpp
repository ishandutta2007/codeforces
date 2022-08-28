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

int p[200000],pos[200000];
vi adjList[200000];
int depth[200000],disc[200000],num = 0;
int sparse[400000][19],logg[400000];
int doDFS(int u) {
    int i;
    sparse[num][0] = depth[u],disc[u] = num++;
    for (i = 0; i < adjList[u].size(); i++) doDFS(adjList[u][i]),sparse[num++][0] = depth[u];
    return 0;
}
int query(int l,int r) {
    int x = logg[r-l+1];
    return min(sparse[l][x],sparse[r-(1 << x)+1][x]);
}
int dist(pii uu,pii vv) {
    int u = uu.second,v = vv.second;
    return depth[u]+depth[v]-2*query(disc[u],disc[v]);
}
pii tree[1 << 19];
pii x[4];
int d[4][4];
pii com(pii a,pii b) {
    if (a == mp(-1,-1)) return mp(-1,-1);
    else if (b == mp(-1,-1)) return mp(-1,-1);
    int i,j;
    x[0].second = a.first,x[1].second = a.second,x[2].second = b.first,x[3].second = b.second;
    for (i = 0; i < 4; i++) x[i].first = disc[x[i].second];
    sort(x,x+4);
    for (i = 0; i < 4; i++) {
        for (j = i+1; j < 4; j++) d[i][j] = dist(x[i],x[j]);
    }
    int c = d[0][1]+d[1][2]+d[2][3]+d[0][3];
    for (i = 0; i < 4; i++) {
        for (j = i+1; j < 4; j++) {
            if (2*d[i][j] == c) return mp(x[i].second,x[j].second);
        }
    }
    return mp(-1,-1);
}
int build(int s,int e,int i) {
    if (s == e) {
        tree[i] = mp(pos[s],pos[s]);
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    tree[i] = com(tree[2*i+1],tree[2*i+2]);
    return 0;
}
int update(int s,int e,int ai,int i) {
    if ((s > ai) || (e < ai)) return 0;
    else if (s == e) {
        tree[i] = mp(pos[s],pos[s]);
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,ai,2*i+1),update(mid+1,e,ai,2*i+2);
    tree[i] = com(tree[2*i+1],tree[2*i+2]);
    return 0;
}
int query(int s,int e,int i,pii p) {
    if (s == e) {
        pii q = com(p,tree[i]);
        if (q != mp(-1,-1)) return s+1;
        else return s;
    }

    int mid = (s+e) / 2;
    pii q = com(p,tree[2*i+1]);
    if (q != mp(-1,-1)) return query(mid+1,e,2*i+2,q);
    else return query(s,mid,2*i+1,p);
}
int main() {
    int i,j;
    int n,q,d,t,u,v;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&p[i]),pos[p[i]] = i;
    for (i = 1; i < n; i++) {
        scanf("%d",&d),d--;
        adjList[d].pb(i),depth[i] = depth[d]+1;
    }
    doDFS(0);
    for (i = 2; i <= num; i++) logg[i] = logg[i/2]+1;
    for (i = 1; (1 << i) < num; i++) {
        for (j = 0; j <= num-(1 << i); j++) sparse[j][i] = min(sparse[j][i-1],sparse[j+(1 << (i-1))][i-1]);
    }
    build(0,n-1,0);

    int pans = -1;
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d",&t);
        if (t == 1) {
            scanf("%d %d",&u,&v),u--,v--;
            swap(p[u],p[v]),swap(pos[p[u]],pos[p[v]]);
            update(0,n-1,p[u],0),update(0,n-1,p[v],0),pans = -1;
        }
        else if (t == 2) {
            if (pans != -1) printf("%d\n",pans);
            else {
                pans = query(0,n-1,0,mp(pos[0],pos[0]));
                printf("%d\n",pans);
            }
        }
    }

    return 0;
}