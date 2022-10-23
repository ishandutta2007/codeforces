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

int b[100000];
int mm[100001],d[100001];
set<int> S;
int bb[100001],d2[100001];
int a[100005];
vi vv[100005];
int main() {
    int i;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i = 0; i < n; i++) scanf("%d",&b[i]);

        int f = 0;
        for (i = 0; i < n; i++) {
            if (b[i] == 0) f = 1;
        }
        S.clear();
        mm[0] = 1e9,d[0] = 0;
        for (i = 0; i < n; i++) {
            S.insert(b[i]);
            mm[i+1] = min(mm[i],b[i]);
            d[i+1] = S.size();
        }
        S.clear();
        bb[n] = 0,d2[n] = 0;
        for (i = n-1; i >= 0; i--) {
            S.insert(b[i]);
            bb[i] = max(bb[i+1],b[i]);
            d2[i] = S.size();
        }
        for (i = 0; i <= n; i++) {
            if ((mm[i] > i) && (bb[i] <= i)) {
                if (f && ((d2[i] == d[i]+1) || (d2[i] == d[i]))) break;
                if (!f && ((d[i] == d2[i]+1) || (d[i] == d2[i]))) break;
            }
        }
        assert(i <= n);
        int k = i;
        printVar(k);
        for (i = 0; i < n; i++) vv[b[i]].pb(i);
        int l = 0,z;
        if (f) {
            for (int c: vv[0]) {
                if (!S.count(c+1)) a[l++] = c+1;
                else z = c+1;
            }
            a[l++] = z;
        }
        else {
            for (int c: vv[n+1]) {
                if (!S.count(c+1)) a[l++] = c+1;
                else z = c+1;
            }
            a[l++] = z;
        }
        printArr(a,l);
        printVar(p.size());
        printVar(q.size());
        printVar(w);
        while (l < n) {
            int r = a[l-1];
            for (int c: vv[r]) {
                if (!S.count(c+1)) a[l++] = c+1;
                else z = c+1;
            }
            printVar(z);
            a[l++] = z;
        }
        printf("%d\n",k);
        for (i = 0; i < n; i++) printf("%d%c",a[i],(i == n-1) ? '\n':' ');
        for (i = 0; i <= n+2; i++) vv[i].clear();
    }
    
    return 0;
}