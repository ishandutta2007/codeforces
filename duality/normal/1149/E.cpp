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

int h[200000];
vi adjList[200000];
int nim[200000];
int doDFS(int u) {
    if (nim[u] != -1) return 0;
    int i,j = 0;
    vi s;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        doDFS(v),s.pb(nim[v]);
    }
    sort(s.begin(),s.end());
    for (i = 0; i <= adjList[u].size(); i++) {
        while ((j < s.size()) && (s[j] < i)) j++;
        if ((j == s.size()) || (s[j] > i)) break;
    }
    nim[u] = i;
    return 0;
}
int x[200000],y[200000];
int main() {
    int i;
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) scanf("%d",&h[i]);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&u,&v);
        adjList[u-1].pb(v-1);
    }

    int c = 0;
    fill(nim,nim+n,-1);
    for (i = 0; i < n; i++) doDFS(i),x[nim[i]] ^= h[i];
    for (i = 0; i < n; i++) {
        if (x[i] > 0) c++;
    }
    if (c == 0) {
        printf("LOSE\n");
        return 0;
    }

    int j;
    for (i = 0; i < n; i++) {
        if ((x[nim[i]]^h[i]) < h[i]) {
            int c2 = 1;
            for (j = 0; j < adjList[i].size(); j++) {
                int v = adjList[i][j];
                if ((x[nim[v]] > 0) && !y[nim[v]]) c2++;
                y[nim[v]] = 1;
            }
            if (c == c2) {
                h[i] ^= x[nim[i]];
                for (j = 0; j < adjList[i].size(); j++) {
                    int v = adjList[i][j];
                    h[v] ^= x[nim[v]],x[nim[v]] = 0;
                }
                printf("WIN\n");
                for (j = 0; j < n; j++) printf("%d%c",h[j],(j == (n-1)) ? '\n':' ');
                break;
            }
            else {
                for (j = 0; j < adjList[i].size(); j++) y[nim[adjList[i][j]]] = 0;
            }
        }
    }

    return 0;
}