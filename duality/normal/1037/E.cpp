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

int x[200000],y[200000];
int del[200000];
queue<int> Q;
set<int> adjList[200000];
int aa[200000];
int main() {
    int i;
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for (i = 0; i < m; i++) scanf("%d %d",&x[i],&y[i]),x[i]--,y[i]--;

    int ans = n;
    for (i = 0; i < m; i++) adjList[x[i]].insert(y[i]),adjList[y[i]].insert(x[i]);
    for (i = 0; i < n; i++) {
        if (adjList[i].size() < k) Q.push(i);
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        if (del[u]) continue;
        del[u] = 1,ans--;
        for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
            int v = *it;
            adjList[v].erase(u);
            if (adjList[v].size() < k) Q.push(v);
        }
        adjList[u].clear();
    }
    aa[m-1] = ans;
    for (i = m-1; i >= 1; i--) {
        if (!del[x[i]] && !del[y[i]]) {
            adjList[x[i]].erase(y[i]);
            adjList[y[i]].erase(x[i]);
            if (adjList[x[i]].size() < k) Q.push(x[i]);
            if (adjList[y[i]].size() < k) Q.push(y[i]);
        }
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();

            if (del[u]) continue;
            del[u] = 1,ans--;
            for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
                int v = *it;
                adjList[v].erase(u);
                if (adjList[v].size() < k) Q.push(v);
            }
            adjList[u].clear();
        }
        aa[i-1] = ans;
    }
    for (i = 0; i < m; i++) printf("%d\n",aa[i]);

    return 0;
}