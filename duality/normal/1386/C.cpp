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

int u[200000],v[200000];
int ll[200000];
pii parent[200000];
int size[200000];
pii find(int n) {
    if (parent[n].first != n) {
        pii p = find(parent[n].first);
        return mp(p.first,p.second^parent[n].second);
    }
    else return parent[n];
}
vpii added;
int addEdge(int u,int v) {
    int w = 1;
    pii pu = find(u),pv = find(v);
    w ^= pu.second^pv.second;
    u = pu.first,v = pv.first;
    if (u == v) {
        if (w == 1) return 0;
    }
    else {
        if (size[u] > size[v]) swap(u,v);
        parent[u] = mp(v,w),size[v] += size[u];
        added.pb(mp(u,v));
    }
    return 1;
}
int findAns(int l,int r,int s,int e,int b) {
    if (l > r) return 0;
    else if (!b) {
        fill(ll+l,ll+r+1,s);
        return 0;
    }

    int i;
    int m = (l+r) / 2;
    int bb = b,p1 = added.size();
    for (i = r; i > m; i--) bb &= addEdge(u[i],v[i]);
    int bbb = bb,p2 = added.size();
    i = s+1;
    while ((i <= e) && (i <= m) && bbb) bbb &= addEdge(u[i],v[i]),i++;
    ll[m] = i-1;
    while (added.size() > p2) {
        parent[added.back().first] = mp(added.back().first,0);
        size[added.back().second] -= size[added.back().first];
        added.pop_back();
    }
    bb &= addEdge(u[m],v[m]);
    findAns(l,m-1,s,ll[m],bb);
    while (added.size() > p1) {
        parent[added.back().first] = mp(added.back().first,0);
        size[added.back().second] -= size[added.back().first];
        added.pop_back();
    }
    bb = b;
    for (i = s+1; i <= ll[m]; i++) bb &= addEdge(u[i],v[i]);
    findAns(m+1,r,ll[m],e,bb);
    return 0;
}
int main() {
    int i;
    int N,M,Q;
    scanf("%d %d %d",&N,&M,&Q);
    for (i = 0; i < M; i++) scanf("%d %d",&u[i],&v[i]),u[i]--,v[i]--;
    for (i = 0; i < N; i++) parent[i] = mp(i,0),size[i] = 1;
    findAns(0,M-1,-1,M-1,1);

    int l,r;
    for (i = 0; i < Q; i++) {
        scanf("%d %d",&l,&r);
        l--,r--;
        printf((l <= ll[r]) ? "NO\n":"YES\n");
    }

    return 0;
}