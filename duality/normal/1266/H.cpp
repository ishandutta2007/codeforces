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
#define MOD ((1LL << 61)-1)

LLI mult(LLI a,LLI b) {
    if (a < b) swap(a,b);
    LLI s = 0;
    while (b > 0) {
        if (b & 1) {
            s += a;
            if (s >= MOD) s -= MOD;
        }
        b >>= 1;
        a += a;
        if (a >= MOD) a -= MOD;
    }
    return s;
}
LLI inv(LLI n) {
    LLI e = MOD-2,r = 1;
    while (e > 0) {
        if (e & 1) r = mult(r,n);
        e >>= 1;
        n = mult(n,n);
    }
    return r;
}
int b[58],r[58];
LLI mat[58][58],mat2[58][116],vec[58],sol[58];
vi adjList[58];
int visited[58];
int doDFS(int u) {
    if (visited[u]) return 0;
    int i;
    visited[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) doDFS(adjList[u][i]);
    return 0;
}
int main() {
    int i,j,k;
    int n,q,v;
    char s[58];
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) scanf("%d %d",&b[i],&r[i]),b[i]--,r[i]--;
    for (i = 0; i < n-1; i++) mat[i][i] -= 2,mat[b[i]][i]++,mat[r[i]][i]++;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) mat2[i][j] = (mat[i][j]+MOD) % MOD;
        mat2[i][i+n] = 1;
    }
    for (i = 0; i < n-1; i++) {
        for (j = i; j < n; j++) {
            if (mat2[j][i] != 0) break;
        }
        int p = j;
        for (j = i; j < 2*n; j++) swap(mat2[i][j],mat2[p][j]);
        for (j = i+1; j < n; j++) {
            LLI c = mult(mat2[j][i],inv(mat2[i][i]));
            for (k = i; k < 2*n; k++) {
                mat2[j][k] -= mult(c,mat2[i][k]);
                if (mat2[j][k] < 0) mat2[j][k] += MOD;
            }
        }
    }
    for (i = n-2; i >= 0; i--) {
        LLI c = inv(mat2[i][i]);
        for (j = i; j < 2*n; j++) mat2[i][j] = mult(mat2[i][j],c);
        for (j = 0; j < i; j++) {
            LLI c = mat2[j][i];
            for (k = i; k < 2*n; k++) {
                mat2[j][k] -= mult(c,mat2[i][k]);
                if (mat2[j][k] < 0) mat2[j][k] += MOD;
            }
        }
    }
    scanf("%d",&q);
    while (q--) {
        scanf("%d %s",&v,s),v--;

        memset(vec,0,sizeof(vec));
        memset(sol,0,sizeof(sol));
        for (i = 0; i < n-1; i++) {
            if (s[i] == 'R') vec[r[i]]--,vec[i]++;
            if (i == 0) vec[i]--;
            if (i == v) vec[i]++;
        }
        for (i = 0; i < n-1; i++) {
            for (j = 0; j < n-1; j++) {
                sol[i] += mult(mat2[i][j+n],(vec[j]+MOD) % MOD);
                if (sol[i] >= MOD) sol[i] -= MOD;
            }
        }
        for (i = 0; i < n; i++) {
            LLI x = 0;
            for (j = 0; j < n; j++) x += mat[i][j]*sol[j];
            if (x != vec[i]) break;
        }
        if (i < n) printf("-1\n");
        else {
            for (i = 0; i < n; i++) visited[i] = 0,adjList[i].clear();
            for (i = 0; i < n-1; i++) {
                if (s[i] == 'R') adjList[r[i]].pb(i);
                else adjList[b[i]].pb(i);
            }
            doDFS(v);
            for (i = 0; i < n; i++) {
                if (((s[i] == 'R') || (sol[i] > 0)) && !visited[i]) break;
            }
            if (i < n) printf("-1\n");
            else {
                LLI ans = 0;
                for (i = 0; i < n-1; i++) ans += 2*sol[i]+(s[i] == 'R');
                printf("%I64d\n",ans);
            }
        }
    }

    return 0;
}