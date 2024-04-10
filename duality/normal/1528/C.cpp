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

vi adjList[300000],adjList2[300000];
int order[300000],disc[300000],fin[300000],num = 0;
int parent[300000][20];
int doDFS(int u,int p) {
    int i;
    parent[u][0] = p;
    disc[u] = num++,order[num-1] = u;
    for (i = 0; i < adjList2[u].size(); i++) doDFS(adjList2[u][i],u);
    fin[u] = num-1;
    //cout<<u<<": "<<disc[u]<<" "<<fin[u]<<endl;
    return 0;
}
int logn;
int bit[300001],bit2[300000];
set<pii> S,S2;
int ans = 0;
int qq(int i) {
    int sum = 0;
    for (i++; i > 0; i -= i & (-i)) sum += bit[i];
    return sum;
}
int qq2(int i) {
    int sum = 0;
    for (i++; i > 0; i -= i & (-i)) sum += bit2[i];
    return sum;
}
int query(int u) {
    int i;
    int q = qq(disc[u]);
    if (q == 0) return -1;
    for (i = logn-1; i >= 0; i--) {
        if (parent[u][i] != -1) {
            int v = parent[u][i];
            if (qq(disc[v]) == q) u = v;
        }
    }
    return u;
}
int query2(int u) {
    int i;
    int q = qq2(disc[u]);
    if (q == 0) return -1;
    for (i = logn-1; i >= 0; i--) {
        if (parent[u][i] != -1) {
            int v = parent[u][i];
            if (qq2(disc[v]) == q) u = v;
        }
    }
    return u;
}
int n;
int Sinsert(int u) {
    int i;
    for (i = disc[u]+1; i <= n; i += i & (-i)) bit[i]++;
    for (i = fin[u]+2; i <= n; i += i & (-i)) bit[i]--;
    S.insert(mp(disc[u],fin[u]));
    return 0;
}
int Serase(int u) {
    int i;
    for (i = disc[u]+1; i <= n; i += i & (-i)) bit[i]--;
    for (i = fin[u]+2; i <= n; i += i & (-i)) bit[i]++;
    S.erase(mp(disc[u],fin[u]));
    return 0;
}
int add(int u) {
    int i;
    S2.insert(mp(disc[u],fin[u]));
    for (i = disc[u]+1; i <= n; i += i & (-i)) bit2[i]++;
    for (i = fin[u]+2; i <= n; i += i & (-i)) bit2[i]--;
    int v = query(u);
    debug v;

    if (v != -1) {
        auto it = S.lower_bound(mp(disc[v],fin[v]));
        debug "here";
        assert(it != S.end());
        Serase(order[it->first]);
        Sinsert(u);

        ans = max(ans,(int) S.size());
        debug "here";
        //cout << "S: ";
    //for (auto it = S.begin(); it != S.end(); it++) cout << it->first<<","<<it->second << " ";
    //cout << endl;
        return 0;
    }
    auto it = S.lower_bound(mp(disc[u],0));
    if ((it != S.end()) && (it->second <= fin[u])) {}
    else Sinsert(u);
    ans = max(ans,(int) S.size());
    //cout << "S: ";
    //for (auto it = S.begin(); it != S.end(); it++) cout << it->first<<","<<it->second << " ";
    //cout << endl;
    return 0;
}
int erase(int u) {
    int i;
    S2.erase(mp(disc[u],fin[u]));
    for (i = disc[u]+1; i <= n; i += i & (-i)) bit2[i]--;
    for (i = fin[u]+2; i <= n; i += i & (-i)) bit2[i]++;
    if (S.count(mp(disc[u],fin[u]))) {
        Serase(u);
        int v = query2(u);
        auto it = S.lower_bound(mp(disc[v],0));
        if ((it != S.end()) && (it->second <= fin[v])) {}
        else Sinsert(v);
    }
    return 0;
}
int doDFS2(int u) {
    int i;
    debug "add";
    add(u);
    debug "fin add";
    for (i = 0; i < adjList[u].size(); i++) doDFS2(adjList[u][i]);
    debug "erase";
    erase(u);
    debug "fin erase";
    return 0;
}
int main() {
    int i,j;
    int t,p;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i = 0; i < n-1; i++) scanf("%d",&p),adjList[p-1].pb(i+1);
        for (i = 0; i < n-1; i++) scanf("%d",&p),adjList2[p-1].pb(i+1);
        num = 0;
        doDFS(0,-1);
        for (i = 1; (1 << i) < n; i++) {
            for (j = 0; j < n; j++) {
                if (parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
                else parent[j][i] = -1;
            }
        }
        logn = i;
        ans = 0;
        doDFS2(0);
        printf("%d\n",ans);
        S.clear(),S2.clear();
        for (i = 0; i <= n; i++) bit[i] = 0;
        for (i = 0; i < n; i++) adjList[i].clear(),adjList2[i].clear();
    }

    return 0;
}