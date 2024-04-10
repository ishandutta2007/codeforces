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

int a[100000],b[100000];
int main() {
    int i;
    int t,n,l;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&l);
        for (i = 0; i < n; i++) scanf("%d",&a[i]),b[i] = a[i];
        reverse(b,b+n);
        for (i = 0; i < n; i++) b[i] = l-b[i];

        double s = 0,e = l;
        int tt = 0;
        while (abs(e-s) > 1e-9) {
            double m = (s+e) / 2;
            tt++;
            if (tt > 200) break;

            double t1 = 0,t2 = 0;
            for (i = 0; i < n; i++) {
                if (a[i] < m) t1 += (double) (a[i]-((i == 0) ? 0:a[i-1]))/(i+1);
                else {
                    t1 += (double) (m-((i == 0) ? 0:a[i-1]))/(i+1);
                    break;
                }
            }
            if (i == n) t1 += (double) (m-((i == 0) ? 0:a[i-1]))/(i+1);
            for (i = 0; i < n; i++) {
                if (b[i] < l-m) t2 += (double) (b[i]-((i == 0) ? 0:b[i-1]))/(i+1);
                else {
                    t2 += (double) (l-m-((i == 0) ? 0:b[i-1]))/(i+1);
                    break;
                }
            }
            if (i == n) t2 += (double) (l-m-((i == 0) ? 0:b[i-1]))/(i+1);
            if (t1 < t2) s = m;
            else e = m;
        }
        double t1 = 0,t2 = 0;
        for (i = 0; i < n; i++) {
            if (a[i] < s) t1 += (double) (a[i]-((i == 0) ? 0:a[i-1]))/(i+1);
            else {
                t1 += (double) (s-((i == 0) ? 0:a[i-1]))/(i+1);
                break;
            }
        }
        if (i == n) t1 += (double) (s-((i == 0) ? 0:a[i-1]))/(i+1);
        printf("%.15lf\n",t1);
    }

    return 0;
}