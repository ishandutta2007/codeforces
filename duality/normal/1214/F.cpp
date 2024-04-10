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

pii a[200000],b[200000];
LLI dist(int s,int n,int m) {
    int i;
    LLI sum = 0;
    for (i = 0; i < n; i++) sum += min(abs(a[i].first-b[(i+s) % n].first),m-abs(a[i].first-b[(i+s) % n].first));
    return sum;
}
int pp[200000];
int main() {
    int i;
    int m,n;
    scanf("%d %d",&m,&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i].first),a[i].second = i,a[i].first--;
    for (i = 0; i < n; i++) scanf("%d",&b[i].first),b[i].second = i,b[i].first--;
    sort(a,a+n),sort(b,b+n);

    int l = 0,r = (n-1)/2;
    while (l < r-5) {
        int mm = (l+r) / 2;
        if (dist(mm+1,n,m) < dist(mm,n,m)) l = mm+1;
        else r = mm;
    }
    LLI ans1 = dist(l,n,m);
    int p = l;
    for (i = max(l-5,0); i <= l+5; i++) {
        LLI d = dist(i,n,m);
        if (d < ans1) ans1 = d,p = i;
    }
    l = n/2,r = n;
    while (l < r-5) {
        int mm = (l+r) / 2;
        if (dist(mm+1,n,m) < dist(mm,n,m)) l = mm+1;
        else r = mm;
    }
    for (i = max(l-5,0); i <= l+5; i++) {
        LLI d = dist(i,n,m);
        if (d < ans1) ans1 = d,p = i;
    }
    int bb = p;
    printf("%I64d\n",ans1);
    for (i = 0; i < n; i++) pp[a[i].second] = b[(i+bb) % n].second;
    for (i = 0; i < n; i++) printf("%d%c",pp[i]+1,(i == n-1) ? '\n':' ');

    return 0;
}