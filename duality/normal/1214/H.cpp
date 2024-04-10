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

int n,k;
vi adjList[200000];
int parent[200000],dist[200000];
int doDFS(int u,int p,int d) {
    int i;
    parent[u] = p,dist[u] = d;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u,d+1);
    }
    return 0;
}
int ans[200000];
vi diam;
int no[200000];
int doDFS2(int u,int p,int x,int y) {
    int i;
    ans[u] = x;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (no[v]) continue;
        if (v != p) doDFS2(v,u,(x+y+k) % k,y);
    }
    return 0;
}
int height[200000],height2[200000];
int doDFS3(int u,int p) {
    int i;
    parent[u] = p,height[u] = 0;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) height[u] = max(height[u],doDFS3(v,u)+1);
    }
    return height[u];
}
int doDFS4(int u,int p,int h) {
    int i;
    int m1 = 0,m2 = 0,mi = -1;
    height2[u] = h;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            if (height[v]+1 >= m1) m2 = m1,m1 = height[v]+1,mi = v;
            else if (height[v]+1 >= m2) m2 = height[v]+1;
        }
    }
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            if (v == mi) doDFS4(v,u,max(h+1,m2+1));
            else doDFS4(v,u,max(h+1,m1+1));
        }
    }
    return 0;
}
int main() {
    int i;
    int u,v;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    doDFS(0,-1,0);
    int mi = 0;
    for (i = 0; i < n; i++) {
        if (dist[i] > dist[mi]) mi = i;
    }
    int a = mi;
    doDFS(a,-1,0);
    mi = 0;
    for (i = 0; i < n; i++) {
        if (dist[i] > dist[mi]) mi = i;
    }
    int b = mi;
    u = b;
    int j,c = 0;
    fill(ans,ans+n,-1);
    while (u != -1) ans[u] = c,c = (c+1) % k,diam.pb(u),no[u] = 1,u = parent[u];
    printArr(ans,n);
    for (i = 0; i < diam.size(); i++) {
        if (i < diam.size()/2) doDFS2(diam[i],-1,ans[diam[i]],-1);
        else doDFS2(diam[i],-1,ans[diam[i]],1);
    }
    int f = 0;
    doDFS3(0,-1),doDFS4(0,-1,0);
    if (k > 2) {
        for (i = 0; i < n; i++) {
            int m1 = height2[i],m2 = 0,m3 = 0;
            for (j = 0; j < adjList[i].size(); j++) {
                int v = adjList[i][j];
                if (v != parent[i]) {
                    int h = height[v]+1;
                    if (h >= m1) m3 = m2,m2 = m1,m1 = h;
                    else if (h >= m2) m3 = m2,m2 = h;
                    else if (h >= m3) m3 = h;
                }
            }
            if (m1 == 0) m1 = -1e9;
            if (m2 == 0) m2 = -1e9;
            if (m3 == 0) m3 = -1e9;
            if (m2+m3+1 >= k) break;
        }
        if (i < n) f = 1;
    }
    if (f) printf("No\n");
    else {
        printf("Yes\n");
        for (i = 0; i < n; i++) printf("%d%c",ans[i]+1,(i == n-1) ? '\n':' ');
    }

    return 0;
}