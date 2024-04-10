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

int b[300000],pre[300001];
int main() {
    int i;
    int n;
    LLI a;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%I64d",&a);
        while (a > 0) b[i] += a & 1,a >>= 1;
        pre[i+1] = pre[i]+b[i];
    }

    int j,k;
    LLI ans = 0;
    for (i = 0; i < 100; i++) {
        int num[2];
        num[0] = num[1] = 0;
        vpii v;
        int p = -1;
        for (j = 0; j < n; j++) {
            if (b[j] > i) {
                if (j-1 >= p+1) v.pb(mp(p+1,j-1));
                p = j;
            }
        }
        if (j-1 >= p+1) v.pb(mp(p+1,j-1));
        for (j = 0; j < v.size(); j++) {
            int l = v[j].first;
            int num[2];
            num[0] = num[1] = 0;
            for (k = v[j].first; k <= v[j].second; k++) {
                while (pre[k+1]-pre[l] >= 2*i) {
                    num[pre[l] & 1]++;
                    l++;
                }
                ans += num[pre[k+1] & 1];
            }
        }
        v.clear();
        p = -1;
        for (j = 0; j < n; j++) {
            if (b[j] >= i) {
                if (j-1 >= p+1) v.pb(mp(p+1,j-1));
                p = j;
            }
        }
        if (j-1 >= p+1) v.pb(mp(p+1,j-1));
        for (j = 0; j < v.size(); j++) {
            int l = v[j].first;
            int num[2];
            num[0] = num[1] = 0;
            for (k = v[j].first; k <= v[j].second; k++) {
                while (pre[k+1]-pre[l] >= 2*i) {
                    num[pre[l] & 1]++;
                    l++;
                }
                ans -= num[pre[k+1] & 1];
            }
        }
        v.clear();
    }
    printf("%I64d\n",ans);

    return 0;
}