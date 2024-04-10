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

char a[4001],b[4001],oa[4001],ob[4001];
vi sol;
int doOp(int x) {
    sol.pb(2*(x+1));
    reverse(a,a+2*(x+1));
    return 0;
}
int main() {
    int i,j,k;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%s %s",a,b);
        int m = strlen(a)/2;

        int c[2];
        c[0] = c[1] = 0;
        for (i = 0; i < m; i++) {
            if (a[2*i] == a[2*i+1]) c[a[2*i]-'0']++;
            if (b[2*i] == b[2*i+1]) c[b[2*i]-'0']--;
        }
        if ((c[0] != 0) || (c[1] != 0)) {
            printf("-1\n");
            continue;
        }
        for (i = 0; i < 2*m; i++) oa[i] = a[i],ob[i] = b[i];

        while (1) {
            sol.clear();
            for (j = m-1; j >= 0; j--) {
                if ((a[2*j] == b[2*j]) && (a[2*j+1] == b[2*j+1])) continue;
                else {
                    if (b[2*j] == b[2*j+1]) {
                        for (k = 0; k <= j; k++) {
                            if ((a[2*k] == b[2*j]) && (a[2*k+1] == b[2*j+1])) {
                                if (k > 0) doOp(k),doOp(j);
                                else doOp(j);
                                break;
                            }
                        }
                    }
                    else {
                        if ((a[0] == b[2*j+1]) && (a[1] == b[2*j])) doOp(j);
                        else {
                            for (k = 0; k <= j; k++) {
                                if ((a[2*k] == b[2*j]) && (a[2*k+1] == b[2*j+1])) {
                                    doOp(k),doOp(j);
                                    break;
                                }
                            }
                            if (k > j) {
                                for (k = 0; k <= j; k++) {
                                    if ((a[2*k] == b[2*j+1]) && (a[2*k+1] == b[2*j])) break;
                                }
                                doOp((rand() % (j-k+1))+k);
                                for (k = 0; k <= j; k++) {
                                    if ((a[2*k] == b[2*j]) && (a[2*k+1] == b[2*j+1])) {
                                        doOp(k),doOp(j);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (sol.size() <= 2*m+1) break;
            else {
                for (j = 0; j < 2*m; j++) a[j] = oa[j],b[j] = ob[j];
            }
        }
        printf("%d\n",sol.size());
        for (i = 0; i < sol.size(); i++) printf("%d ",sol[i]);
        printf("\n");
    }

    return 0;
}