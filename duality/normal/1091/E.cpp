#define DEBUG 1

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

int a[500000],b[500001];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    sort(a,a+n,greater<int>());

    int l = 0,r = n;
    while (l < r) {
        int m = (l+r+1) / 2;

        for (i = 0; i < n; i++) {
            if (a[i] <= m) break;
        }
        int p = i;
        for (; i < n; i++) b[i+1] = a[i];
        b[p] = m;
        for (i = 0; i < p; i++) b[i] = a[i];
        int j = n;
        LLI sum = 0,sum2 = 0;
        int f = 0;
        for (i = 0; i <= n; i++) {
            while ((j > i) && (b[j] <= i)) sum += b[j],j--;
            while (j+1 <= i) sum -= b[j+1],j++;
            sum2 += b[i];
            //if(m==1)cout<<sum2<<","<<sum<<","<<j<<endl;
            if (sum2 > (LLI) i*(i+1)+sum+(LLI) (i+1)*(j-i)) {
                if (i >= p) f = 1;
            }
        }
        if (f) r = m-1;
        else l = m;
    }
    int R = r;
    l = 0,r = n;
    while (l < r) {
        int m = (l+r) / 2;

        for (i = 0; i < n; i++) {
            if (a[i] <= m) break;
        }
        int p = i;
        for (; i < n; i++) b[i+1] = a[i];
        b[p] = m;
        for (i = 0; i < p; i++) b[i] = a[i];
        int j = n;
        LLI sum = 0,sum2 = 0;
        int f = 0;
        for (i = 0; i <= n; i++) {
            while ((j > i) && (b[j] <= i)) sum += b[j],j--;
            while (j+1 <= i) sum -= b[j+1],j++;
            sum2 += b[i];
            //if(m==1)cout<<sum2<<","<<sum<<","<<j<<endl;
            if (sum2 > (LLI) i*(i+1)+sum+(LLI) (i+1)*(j-i)) {
                if (i < p) f = 1;
            }
        }
        if (f) l = m+1;
        else r = m;
    }
    int L = l;
    //cout<<L<<","<<R<<endl;
    LLI sum = 0;
    int num = 0;
    for (i = 0; i < n; i++) sum += a[i];
    for (i = L; i <= R; i++) {
        if (!((sum+i) & 1)) printf("%d ",i),num++;
    }
    if (num == 0) printf("-1");
    printf("\n");

    return 0;
}