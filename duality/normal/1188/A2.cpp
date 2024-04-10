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

vpii adjList[1000];
vector<pair<pii,int> > sol;
vi leaf,leaf2;
int doDFS(int u,int p) {
    if (adjList[u].size() == 1) {
        leaf.pb(u);
        return 0;
    }

    int i;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        if (v != p) doDFS(v,u);
    }
    return 0;
}
int doOp(int u,int v,int x) {
    if ((u == v) || (x == 0)) return 0;
    sol.pb(mp(mp(u,v),x));
    return 0;
}
int main() {
    int i;
    int n,u,v,x;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d %d",&u,&v,&x);
        u--,v--;
        adjList[u].pb(mp(v,x));
        adjList[v].pb(mp(u,x));
    }

    int j,k;
    for (i = 0; i < n; i++) {
        if (adjList[i].size() == 2) {
            if (adjList[i][0].second != adjList[i][1].second) {
                printf("NO\n");
                return 0;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < adjList[i].size(); j++) {
            int v = adjList[i][j].first;
            if (i > v) continue;
            if ((adjList[i].size() == 2) && (adjList[v].size() == 2)) continue;
            if (adjList[i][j].second != 0) {
                    //cout<<i<<","<<v<<endl;
                int w = adjList[i][j].second;
                doDFS(i,v);
                leaf2 = leaf,leaf.clear();
                doDFS(v,i);
                if (leaf.size() == 1) leaf.pb(leaf[0]);
                if (leaf2.size() == 1) leaf2.pb(leaf2[0]);
                swap(leaf[1],leaf.back());
                swap(leaf2[1],leaf2.back());
                //cout<<i<<","<<v<<", w="<<w<<endl;
                //printArr(leaf,leaf.size());
                //printArr(leaf2,leaf2.size());
                doOp(leaf[0],leaf2[0],w/2);
                doOp(leaf[1],leaf2[1],w/2);
                doOp(leaf[0],leaf[1],-w/2);
                doOp(leaf2[0],leaf2[1],-w/2);
                leaf.clear(),leaf2.clear();
                adjList[i][j].second = 0;
                if (adjList[i].size() == 2) {
                    int p = v,u = i;
                    while (adjList[u].size() == 2) {
                        for (k = 0; k < adjList[u].size(); k++) {
                            if (adjList[u][k].first != p) break;
                        }
                        p = u,u = adjList[u][k].first;
                    }
                    printVar(p);
                    printVar(u);
                    for (k = 0; k < adjList[u].size(); k++) {
                        if (adjList[u][k].first == p) adjList[u][k].second = 0;
                    }
                    for (k = 0; k < adjList[p].size(); k++) {
                        if (adjList[p][k].first == u) adjList[p][k].second = 0;
                    }
                }
                if (adjList[v].size() == 2) {
                    int p = i,u = v;
                    while (adjList[u].size() == 2) {
                        for (k = 0; k < adjList[u].size(); k++) {
                            if (adjList[u][k].first != p) break;
                        }
                        p = u,u = adjList[u][k].first;
                    }
                    printVar(p);
                    printVar(u);
                    for (k = 0; k < adjList[u].size(); k++) {
                        if (adjList[u][k].first == p) adjList[u][k].second = 0;
                    }
                    for (k = 0; k < adjList[p].size(); k++) {
                        if (adjList[p][k].first == u) adjList[p][k].second = 0;
                    }
                }
            }
        }
    }
    printf("YES\n");
    printf("%d\n",sol.size());
    for (i = 0; i < sol.size(); i++) printf("%d %d %d\n",sol[i].first.first+1,sol[i].first.second+1,sol[i].second);


    return 0;
}