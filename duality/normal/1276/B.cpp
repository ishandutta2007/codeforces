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
int com1[200000],com2[200000];
int a,b;
int doDFS(int u,int c) {
    if (com1[u] != -1) return 0;
    if (u == a) return 0;
    int i;
    com1[u] = c;
    for (i = 0; i < adjList[u].size(); i++) doDFS(adjList[u][i],c);
    return 0;
}
int doDFS2(int u,int c) {
    if (com2[u] != -1) return 0;
    if (u == b) return 0;
    int i;
    com2[u] = c;
    for (i = 0; i < adjList[u].size(); i++) doDFS2(adjList[u][i],c);
    return 0;
}
vpii vv;
bool comp(pii a,pii b) {
    return a.second < b.second;
}
int main() {
    int i;
    int t;
    int n,m,u,v;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d %d %d",&n,&m,&a,&b);
        a--,b--;
        for (i = 0; i < m; i++) {
            scanf("%d %d",&u,&v);
            u--,v--;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }

        int c = 0;
        for (i = 0; i < n; i++) com1[i] = com2[i] = -1;
        for (i = 0; i < n; i++) {
            if ((i != a) && (com1[i] == -1)) doDFS(i,c),c++;
        }
        c = 0;
        for (i = 0; i < n; i++) {
            if ((i != b) && (com2[i] == -1)) doDFS2(i,c),c++;
        }
        for (i = 0; i < n; i++) {
            if ((i != a) && (i != b)) vv.pb(mp(com1[i],com2[i]));
        }
        sort(vv.begin(),vv.end());
        LLI ans = (LLI) (n-2)*(n-3)/2;
        c = 0;
        for (i = 0; i < vv.size(); i++) {
            //cout<<vv[i].first<<","<<vv[i].second<<endl;
            ans -= c;
            c++;
            if ((i < (int) vv.size()-1) && (vv[i].first != vv[i+1].first)) c = 0;
        }
        c = 0;
        for (i = 0; i < vv.size(); i++) {
            //cout<<vv[i].first<<","<<vv[i].second<<endl;
            ans += c;
            c++;
            if ((i < (int) vv.size()-1) && (vv[i] != vv[i+1])) c = 0;
        }
        sort(vv.begin(),vv.end(),comp);
        c = 0;
        for (i = 0; i < vv.size(); i++) {
            //cout<<vv[i].first<<","<<vv[i].second<<endl;
            ans -= c;
            c++;
            if ((i < (int) vv.size()-1) && (vv[i].second != vv[i+1].second)) c = 0;
        }
        printf("%I64d\n",ans);
        vv.clear();
        for (i = 0; i < n; i++) adjList[i].clear();
    }

    return 0;
}