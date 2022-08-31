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

int n;
int a[300000],pos[300000];
vi adjList[300000],adjList2[300000];
int parent[300000],depth[300000],disc[300000],fin[300000],num = 0;
int doDFS(int u,int p,int d) {
    int i;
    parent[u] = p,depth[u] = d;
    disc[u] = num++;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u,d+1);
    }
    fin[u] = num;
    return 0;
}
int bit[300001];
int update(int i,int num) {
    for (i++; i <= n; i += i & (-i)) bit[i] += num;
    return 0;
}
int query(int i) {
    int sum = 0;
    for (i++; i > 0; i -= i & (-i)) sum += bit[i];
    return sum;
}
int b[300000],b2[300000];
int doDFS2(int u) {
    int i;
    b[u] = num++;
    for (i = 0; i < adjList2[u].size(); i++) doDFS2(adjList2[u][i]);
    return 0;
}
int main() {
    int i,j,u,v;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),pos[--a[i]] = i;
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    LLI ans = 0;
    doDFS(0,-1,0);
    for (i = 0; i < n; i++) {
        int u = pos[i];
        if (query(fin[u]-1)-query(disc[u]-1) != fin[u]-disc[u]-1) {
            ans += depth[u];
            break;
        }
        else {
            ans += depth[u],update(disc[u],1);
            if (parent[u] != -1) adjList2[parent[u]].pb(u);
        }
    }
    for (i = 0; i < n; i++) {
        set<int> S;
        for (j = 0; j < adjList2[i].size(); j++) S.insert(adjList2[i][j]);
        vpii vv;
        for (j = 0; j < adjList[i].size(); j++) {
            int v = adjList[i][j];
            if ((v != parent[i]) && !S.count(v)) vv.pb(mp(a[v],v));
        }
        sort(vv.begin(),vv.end());
        for (j = 0; j < vv.size(); j++) adjList2[i].pb(vv[j].second);
    }
    num = 0;
    doDFS2(0);
    for (i = 0; i < n; i++) pos[b[i]] = i,b2[i] = b[i];
    printArr(b,n);
    printVar(ans);
    int c = 0;
    u = 0;
    deque<int> Q;
    while (1) {
        int f = 0;
        Q.pb(c);
        for (i = 0; i < adjList2[u].size(); i++) {
            if (b[adjList2[u][i]] == c+1) {
                c++,u = adjList2[u][i],f = 1;
                break;
            }
        }
        if (!f) break;
    }
    printArr(Q,Q.size());
    LLI r = ans;
    while (r > 0) {
        if (Q.size() < 2) {
            b2[0] = -1;
            break;
        }
        if (r <= Q.size()-1) {
            for (i = 0; i < r; i++) swap(Q[i],Q[i+1]);
            r = 0;
        }
        else {
            debug "here";
            printVar(r);
            printArr(Q,Q.size());
            printVar(c);
            printVar(u);
            r -= Q.size()-1;
            b2[u] = Q.front();
            Q.pop_front(),u = parent[u];
            while ((c+1 < n) && (parent[pos[c+1]] == u)) {
                Q.pb(++c),u = pos[c];
            }
        }
    }
    vi path;
    while (u != -1) path.pb(u),u = parent[u];
    reverse(path.begin(),path.end());
    for (i = 0; i < Q.size(); i++) b2[path[i]] = Q[i];
    printArr(b2,n);
    for (i = 0; i < n; i++) {
        if (b2[i] != a[i]) break;
    }
    if (i == n) {
        printf("YES\n%I64d\n",ans);
        for (i = 0; i < n; i++) printf("%d ",b[i]+1);
        printf("\n");
    }
    else printf("NO\n");

    return 0;
}