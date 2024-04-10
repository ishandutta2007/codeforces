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

vi adjList[200000];
int visited[200000],parent[200000],root[200000];
int doDFS(int u,int p,int r) {
    visited[u] = 1,parent[u] = p,root[u] = r;
    for (int v: adjList[u]) {
        if (!visited[v]) {
            if (doDFS(v,u,r)) return 1;
        }
        else if (root[v] != r) {
            vi p1,p2;
            int x = v;
            while (x != -1) p1.pb(x),x = parent[x];
            p2.pb(v),x = u;
            while (x != -1) p2.pb(x),x = parent[x];
            reverse(p1.begin(),p1.end());
            reverse(p2.begin(),p2.end());
            printf("Possible\n");
            printf("%d\n",p1.size());
            for (int x: p1) printf("%d ",x+1);
            printf("\n");
            printf("%d\n",p2.size());
            for (int x: p2) printf("%d ",x+1);
            printf("\n");
            return 1;
        }
    }
    return 0;
}
int main() {
    int i;
    int n,m,s,u,v;
    scanf("%d %d %d",&n,&m,&s),s--;
    for (i = 0; i < m; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        if (v != s) adjList[u].pb(v);
    }

    parent[s] = -1;
    for (int v: adjList[s]) {
        if (!visited[v]) {
            if (doDFS(v,s,v)) return 0;
        }
        else {
            int u = s;
            vi p1,p2;
            int x = v;
            while (x != -1) p1.pb(x),x = parent[x];
            p2.pb(v),x = u;
            while (x != -1) p2.pb(x),x = parent[x];
            reverse(p1.begin(),p1.end());
            reverse(p2.begin(),p2.end());
            printf("Possible\n");
            printf("%d\n",p1.size());
            for (int x: p1) printf("%d ",x+1);
            printf("\n");
            printf("%d\n",p2.size());
            for (int x: p2) printf("%d ",x+1);
            printf("\n");
            return 0;
        }
    }
    printf("Impossible\n");

    return 0;
}