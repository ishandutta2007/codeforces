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

char s[100000];
int pre0[100001],pre1[100001];
int pre0range[100001],pre1range[100001];
int suff0range[100001],suff1range[100001];
int main() {
    int i;
    int n,k;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; i++) scanf(" %c",&s[i]);

    for (i = 0; i < n; i++) {
        pre0[i+1] = pre0[i] + (s[i] == '0');
        pre1[i+1] = pre1[i] + (s[i] == '1');
    }
    for (i = 0; i <= n-k; i++) {
        if (pre1[i]+pre1[n]-pre1[i+k] == 0) {
            printf("tokitsukaze\n");
            return 0;
        }
        if (pre0[i]+pre0[n]-pre0[i+k] == 0) {
            printf("tokitsukaze\n");
            return 0;
        }
    }
    int l = -1,r = -1;
    for (i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (l == -1) l = i;
            r = max(r,i+1);
        }
        pre0range[i+1] = r-l;
    }
    l = r = -1;
    for (i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (l == -1) l = i;
            r = max(r,i+1);
        }
        pre1range[i+1] = r-l;
    }
    l = n,r = n;
    for (i = n-1; i >= 0; i--) {
        if (s[i] == '0') {
            if (r == n) r = i;
            l = min(l,i-1);
        }
        suff0range[i] = r-l;
    }
    l = n,r = n;
    for (i = n-1; i >= 0; i--) {
        if (s[i] == '1') {
            if (r == n) r = i;
            l = min(l,i-1);
        }
        suff1range[i] = r-l;
    }

    int s = 1;
    for (i = 0; i <= n-k; i++) {
        int a = pre0range[i],b = suff0range[i+k];
        if (!(((a == 0) || (b == 0)) && (a+b <= k))) s = 0;
        a = pre1range[i],b = suff1range[i+k];
        if (!(((a == 0) || (b == 0)) && (a+b <= k))) s = 0;
    }
    if (s) printf("quailty\n");
    else printf("once again\n");

    return 0;
}