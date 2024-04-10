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

int a[1000][1000],aa[1000][1000];
struct mat {
    int a[4][4];
    int *operator[](int i) { return a[i]; }
};
mat mult(mat a,mat b) {
    int i,j,k;
    mat c;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            c[i][j] = 0;
            for (k = 0; k < 4; k++) c[i][j] += a[i][k]*b[k][j];
        }
    }
    return c;
}
int main() {
    int i,j,k,l;
    int t,n,m;
    char c;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) scanf("%d",&a[i][j]),a[i][j]--;
        }
        mat I;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) I[i][j] = 0;
            I[i][i] = 1;
        }
        mat r = I;
        for (i = 0; i < m; i++) {
            scanf(" %c",&c);
            mat b = I;
            if (c == 'R') b[0][3] = 1;
            else if (c == 'L') b[0][3] = -1;
            else if (c == 'D') b[1][3] = 1;
            else if (c == 'U') b[1][3] = -1;
            else if (c == 'C') b[1][1] = b[2][2] = 0,b[1][2] = b[2][1] = 1;
            else b[0][0] = b[2][2] = 0,b[0][2] = b[2][0] = 1;
            r = mult(b,r);
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                int v[4],vv[4];
                v[0] = j,v[1] = i,v[2] = a[i][j],v[3] = 1;
                for (k = 0; k < 4; k++) {
                    vv[k] = 0;
                    for (l = 0; l < 4; l++) vv[k] += r[k][l]*v[l];
                    vv[k] %= n;
                    if (vv[k] < 0) vv[k] += n;
                }
                aa[vv[1]][vv[0]] = vv[2];
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) printf("%d ",aa[i][j]+1);
            printf("\n");
        }
    }

    return 0;
}