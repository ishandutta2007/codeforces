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

int yes[1 << 17];
struct info {
    int a[2][2];
    int *operator[](int i) { return a[i]; }
};
info findAns(int l,int r) {
    if (r == l+3) {
        int i,j,k;
        int a = (yes[l] || yes[l+1]),b = (yes[l+2] || yes[l+3]);
        info ans;
        ans[0][0] = ans[0][1] = ans[1][0] = ans[1][1] = -1e9;
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                for (k = 0; k < 2; k++) {
                    int l1 = yes[l+1-i],l2 = yes[l+3-j],c = a+b;
                    if (l1 || l2) c++;
                    int x = yes[l+i] + yes[l+2+j];
                    c += (x > 0);
                    if (x > 0) ans[x-1][1] = max(ans[x-1][1],c+1);
                    ans[min(x,1)][l1 | l2] = max(ans[min(x,1)][l1 | l2],(l1 | l2)+c);
                }
            }
        }
        return ans;
    }

    int i,j,k,ll;
    int m = (l+r) / 2;
    info L = findAns(l,m),R = findAns(m+1,r);
    info ans;
    ans[0][0] = ans[0][1] = ans[1][0] = ans[1][1] = -1e9;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                for (ll = 0; ll < 2; ll++) {
                    int c = L[i][j]+R[k][ll];
                    if (i || k) c++;
                    if (j || ll) c++;
                    if (i || k) ans[i+k-1][1] = max(ans[i+k-1][1],c+1);
                    ans[i | k][j | ll] = max(ans[i | k][j | ll],c+(j | ll));
                }
            }
        }
    }
    return ans;
}
int main() {
    int i;
    int n,k,a;
    scanf("%d %d",&n,&k);
    for (i = 0; i < k; i++) scanf("%d",&a),yes[a-1] = 1;
    if (k == 0) {
        printf("0\n");
        return 0;
    }
    info f = findAns(0,(1 << n)-1);
    printf("%d\n",1+max(max(f[0][0],f[0][1]),max(f[1][0],f[1][1])));
    return 0;
}