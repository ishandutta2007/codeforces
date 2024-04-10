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
#define MOD 998244353

char b[2000][2000];
vi adjList[4000];
int v[4000],visited[4000],n,e,x;
int doDFS(int u) {
    visited[u] = 1,n++,x ^= v[u];
    for (int v: adjList[u]) {
        if (!visited[v]) doDFS(v);
        e += (u < v);
    }
    return 0;
}
int main() {
    int i,j;
    int r,c;
    scanf("%d %d",&r,&c);
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) scanf(" %c",&b[i][j]);
    }

    if (!(r & 1) && !(c & 1)) {
        int w = 1;
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (b[i][j] == '?') w = (2*w) % MOD;
            }
        }
        printf("%d\n",w);
    }
    else if (!(r & 1)) {
        int e = 1,o = 1;
        for (i = 0; i < r; i++) {
            int x = 0,y = 0;
            for (j = 0; j < c; j++) {
                if (b[i][j] == '1') x ^= 1;
                else if (b[i][j] == '?') y++;
            }
            if (y == 0) {
                if (x) e = 0;
                else o = 0;
            }
            else {
                for (j = 0; j < y-1; j++) e = (2*e) % MOD,o = (2*o) % MOD;
            }
        }
        printf("%d\n",(e+o) % MOD);
    }
    else if (!(c & 1)) {
        int e = 1,o = 1;
        for (i = 0; i < c; i++) {
            int x = 0,y = 0;
            for (j = 0; j < r; j++) {
                if (b[j][i] == '1') x ^= 1;
                else if (b[j][i] == '?') y++;
            }
            if (y == 0) {
                if (x) e = 0;
                else o = 0;
            }
            else {
                for (j = 0; j < y-1; j++) e = (2*e) % MOD,o = (2*o) % MOD;
            }
        }
        printf("%d\n",(e+o) % MOD);
    }
    else {
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (b[i][j] == '1') v[i] ^= 1,v[j+r] ^= 1;
                else if (b[i][j] == '?') {
                    adjList[i].pb(j+r);
                    adjList[j+r].pb(i);
                }
            }
        }
        int ee = 1,oo = 1;
        for (i = 0; i < r+c; i++) {
            if (!visited[i]) {
                n = e = x = 0;
                doDFS(i);
                if (n & 1) {
                    if (x) ee = 0;
                    else oo = 0;
                }
                else {
                    if (x) ee = oo = 0;
                }
                for (j = 0; j < e-(n-1); j++) ee = (2*ee) % MOD,oo = (2*oo) % MOD;
            }
        }
        printf("%d\n",(ee+oo) % MOD);
    }

    return 0;
}