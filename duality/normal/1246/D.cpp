#define DEBUG 1

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

int parent[100000];
vi adjList[100000];
int depth[100000],leaf[100000],size[100000],num2 = 0;
int disc[100000],fin[100000];
LLI ans = 0;
int doDFS(int u,int d) {
    int i,m = 0;
    size[u] = 1,depth[u] = d;
    if (adjList[u].empty()) leaf[u] = u;
    else leaf[u] = -1;
    disc[u] = num2++;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        size[u] += doDFS(v,d+1);
        m = max(m,size[v]);
        if (leaf[u] == -1) leaf[u] = leaf[v];
        if (depth[leaf[v]] > depth[leaf[u]]) leaf[u] = leaf[v];
    }
    fin[u] = num2;
    return size[u];
}
vi bamboo,sol;
int doDFS2(int u) {
    int i;
    bamboo.pb(u);
    int m = -1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if ((m == -1) || (depth[leaf[v]] > depth[leaf[m]])) m = v;
    }
    if (m != -1) {
        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            if (v != m) doDFS2(v);
        }
        doDFS2(m);
    }
    return 0;
}
int parent2[100000];
int num = 0;
int doDFS3(int u) {
    num++;
    //cout<<"ent "<<u<<endl;
    while ((num < bamboo.size()) && (disc[bamboo[num]] < fin[u]) && (disc[bamboo[num]] >= disc[u])) {
        //cout<<bamboo[num]<<endl;
        doDFS3(bamboo[num]);
        if ((num < bamboo.size()) && (disc[bamboo[num]] < fin[u]) && (disc[bamboo[num]] >= disc[u])) {
            while (parent2[bamboo[num]] != u) sol.pb(bamboo[num]),parent2[bamboo[num]] = parent2[parent2[bamboo[num]]];
        }
    }
    //cout<<"ret "<<u<<endl;
    return 0;
}
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 1; i < n; i++) {
        scanf("%d",&parent[i]);
        adjList[parent[i]].pb(i);
    }
    doDFS(0,0);
    doDFS2(0);
    //printArr(bamboo,n);
    for (i = 1; i < n; i++) parent2[bamboo[i]] = bamboo[i-1];
    doDFS3(0);
    for (i = 0; i < n; i++) printf("%d ",bamboo[i]);
    printf("\n");
    printf("%d\n",sol.size());
    for (i = 0; i < sol.size(); i++) printf("%d ",sol[i]);
    printf("\n");

    return 0;
}