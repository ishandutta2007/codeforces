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

int a[100000],kk[100000];
LLI f(int a,int k) {
    LLI x = a/k;
    LLI y = a % k;
    return y*(x+1)*(x+1)+(k-y)*x*x;
}
priority_queue<pair<LLI,int> > H;
int main() {
    int i;
    int n,k;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),kk[i] = 1;

    for (i = 0; i < n; i++) H.push(mp(f(a[i],1)-f(a[i],2),i));
    for (i = 0; i < k-n; i++) {
        pair<LLI,int> p = H.top();
        H.pop();
        kk[p.second]++;
        H.push(mp(f(a[p.second],kk[p.second])-f(a[p.second],kk[p.second]+1),p.second));
    }
    LLI ans = 0;
    for (i = 0; i < n; i++) ans += f(a[i],kk[i]);
    printf("%I64d\n",ans);

    return 0;
}