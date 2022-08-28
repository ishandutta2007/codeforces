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

int a[100000];
vi adjList[100000];
vi good[100];
int dist[100][100000];
queue<int> Q;
int tosort[100];
int main() {
    int i;
    int n,m,k,s;
    int u,v;
    scanf("%d %d %d %d",&n,&m,&k,&s);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),a[i]--,good[a[i]].pb(i);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    int j;
    for (i = 0; i < k; i++) {
        fill(dist[i],dist[i]+n,-1);
        for (j = 0; j < good[i].size(); j++) {
            dist[i][good[i][j]] = 0;
            Q.push(good[i][j]);
        }
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();

            for (j = 0; j < adjList[u].size(); j++) {
                int v = adjList[u][j];
                if (dist[i][v] == -1) {
                    dist[i][v] = dist[i][u]+1;
                    Q.push(v);
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) tosort[j] = dist[j][i];
        sort(tosort,tosort+k);
        int sum = 0;
        for (j = 0; j < s; j++) sum += tosort[j];
        printf("%d%c",sum,(i == n-1) ? '\n':' ');
    }

    return 0;
}