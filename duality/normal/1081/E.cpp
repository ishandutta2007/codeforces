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

int x[100000];
int fac[200001];
LLI ans[100000];
vpii fact;
vi all;
int getAll(int x,int c) {
    if (c == fact.size()) {
        all.pb(x);
        return 0;
    }

    int i;
    for (i = 0; i <= fact[c].second; i++) {
        getAll(x,c+1);
        if (i < fact[c].second) x *= fact[c].first;
    }
    return 0;
}
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n/2; i++) scanf("%d",&x[i]);

    int j;
    for (i = 1; i <= 200000; i++) fac[i] = i;
    for (i = 2; i <= 200000; i++) {
        if (fac[i] == i) {
            for (j = i; j <= 200000; j += i) fac[j] = i;
        }
    }

    LLI p = 0;
    for (i = 0; i < n/2; i++) {
        int t = x[i],f = fac[t],c = 0;
        fact.clear(),all.clear();
        while (t > 1) {
            if (fac[t] != f) fact.pb(mp(f,c)),f = fac[t],c = 1;
            else c++;
            t /= fac[t];
        }
        fact.pb(mp(f,c));
        getAll(1,0);
        printArr(all,all.size());
        ans[2*i+1] = 1e18;
        for (j = 0; j < all.size(); j++) {
            int a = all[j],b = x[i]/all[j];
            if ((a+b) & 1) continue;
            if (((LLI) ((b-a)/2)*((b-a)/2)) > p) ans[2*i+1] = min(ans[2*i+1],(LLI) ((a+b)/2)*((a+b)/2));
        }
        if (ans[2*i+1] == 1e18) {
            printf("No\n");
            return 0;
        }
        else ans[2*i] = ans[2*i+1]-x[i],p = ans[2*i+1];
    }
    printf("Yes\n");
    for (i = 0; i < n; i++) printf("%I64d ",ans[i]-((i == 0) ? 0:ans[i-1]));
    printf("\n");

    return 0;
}