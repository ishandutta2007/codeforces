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
pii edges[200000];
int isEdge(int u,int v,int m) {
    if (u > v) swap(u,v);
    return binary_search(edges,edges+m,mp(u,v));
}
vi large;
int conn[1000][1000];
int main() {
    int i;
    int n,m;
    int A,B,C;
    int u,v;
    ULLI ans = 0;
    scanf("%d %d %d %d %d",&n,&m,&A,&B,&C);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&u,&v);
        if (u > v) swap(u,v);
        adjList[u].pb(v);
        adjList[v].pb(u);
        ans -= ((ULLI) A*u+(ULLI) B*v)*(n-v-1) + (ULLI) (n+v)*(n-v-1)/2*C;
        ans -= ((ULLI) A*u+(ULLI) C*v)*(v-u-1) + (ULLI) (u+v)*(v-u-1)/2*B;
        ans -= ((ULLI) B*u+(ULLI) C*v)*u + (ULLI) (u-1)*u/2*A;
        edges[i] = mp(u,v);
    }
    sort(edges,edges+m);

    int j;
    for (i = 0; i < n; i++) ans += (ULLI) (n-i-1)*(n-i-2)/2*A*i + (ULLI) i*(n-i-1)*B*i + (ULLI) i*(i-1)/2*C*i;
    for (i = 0; i < n; i++) {
        sort(adjList[i].begin(),adjList[i].end());
        ULLI lsum = 0,lnum = 0,rsum = 0,rnum = 0;
        ULLI lall = 0,rall = 0;
        for (j = 0; j < adjList[i].size(); j++) {
            v = adjList[i][j];
            if (v < i) lsum += v,lnum++;
            else rsum += v,rnum++;
        }
        ans += A*lsum*rnum + (ULLI) B*i*lnum*rnum + C*rsum*lnum;
        for (j = 0; j < adjList[i].size(); j++) {
            v = adjList[i][j];
            if (v < i) lall += (ULLI) A*v*(lnum-j-1) + (ULLI) B*v*j;
            else rall += (ULLI) B*v*(adjList[i].size()-j-1) + (ULLI) C*v*(j-lnum);
        }
        ans += lall + lnum*(lnum-1)/2*C*i;
        ans += rall + rnum*(rnum-1)/2*A*i;
    }
    int k;
    int s = sqrt(m)+EPS;
    for (i = 0; i < n; i++) {
        if (adjList[i].size() <= s) {
            for (j = 0; j < adjList[i].size(); j++) {
                for (k = j+1; k < adjList[i].size(); k++) {
                    int a = i,b = adjList[i][j],c = adjList[i][k];
                    if (!isEdge(b,c,m)) continue;
                    if (a > b) swap(a,b);
                    if (b > c) swap(b,c);
                    if (a > b) swap(a,b);
                    if ((a == i) || ((b == i) && (adjList[a].size() > s)) \
                        || ((c == i) && (adjList[a].size() > s) && (adjList[b].size() > s)))
                            ans -= (ULLI) A*a+(ULLI) B*b+(ULLI) C*c;
                }
            }
        }
        else large.pb(i);
    }
    for (i = 0; i < large.size(); i++) {
        for (j = i+1; j < large.size(); j++) conn[i][j] = isEdge(large[i],large[j],m);
    }
    for (i = 0; i < large.size(); i++) {
        for (j = i+1; j < large.size(); j++) {
            if (!conn[i][j]) continue;
            for (k = j+1; k < large.size(); k++) {
                if (conn[i][k] && conn[j][k]) ans -= (ULLI) A*large[i]+(ULLI) B*large[j]+(ULLI) C*large[k];
            }
        }
    }
    printf("%I64u\n",ans);

    return 0;
}