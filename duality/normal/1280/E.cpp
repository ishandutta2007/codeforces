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

char s[1000000];
int parent[200000],num = 0;
char type[200000];
vi adjList[200000];
int dp[200000];
int findSol(int u,int no,int r) {
    if (type[u] == '*') {
        if (!no) printf(" %I64d",(LLI) dp[0]*r);
        else printf(" 0");
        return 0;
    }

    int i;
    if (no) {
        for (i = 0; i < adjList[u].size(); i++) findSol(adjList[u][i],1,r);
    }
    else {
        if (type[u] == 'S') {
            for (i = 0; i < adjList[u].size(); i++) {
                if (dp[adjList[u][i]] == dp[u]) break;
            }
            int p = i;
            for (i = 0; i < adjList[u].size(); i++) {
                if (i == p) findSol(adjList[u][i],0,r);
                else findSol(adjList[u][i],1,r);
            }
        }
        else {
            for (i = 0; i < adjList[u].size(); i++) findSol(adjList[u][i],0,r);
        }
    }
    return 0;
}
int main() {
    int i,j;
    int t,r;
    scanf("%d",&t);
    while (t--) {
        scanf("%d ",&r);
        fgets(s,sizeof(s),stdin);

        int u = 0;
        type[u] = '*';
        for (i = 0; s[i] != '\0'; i++) {
            if (s[i] == '(') {
                adjList[u].pb(++num),parent[num] = u;
                u = num,type[u] = '*';
            }
            else if ((s[i] == 'P') || (s[i] == 'S')) {
                u = parent[u],type[u] = s[i];
                adjList[u].pb(++num),parent[num] = u;
                u = num,type[u] = '*';
            }
            else if (s[i] == ')') u = parent[u];
        }
        for (i = num; i >= 0; i--) {
            if (type[i] == 'S') {
                dp[i] = 1e9;
                for (j = 0; j < adjList[i].size(); j++) dp[i] = min(dp[i],dp[adjList[i][j]]);
            }
            else if (type[i] == 'P') {
                dp[i] = 0;
                for (j = 0; j < adjList[i].size(); j++) dp[i] += dp[adjList[i][j]];
            }
            else dp[i] = 1;
        }
        printf("REVOLTING");
        findSol(0,0,r);
        printf("\n");

        for (i = 0; i <= num; i++) adjList[i].clear();
        num = 0;
    }

    return 0;
}