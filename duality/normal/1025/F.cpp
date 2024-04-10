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
#define x first
#define y second

pii p[2000];
bool comp(pii a,pii b) {
    if (a.y == b.y) return a.x < b.x;
    else return a.y < b.y;
}
int pos[2000];
vpii vv;
bool comp2(pii a,pii b) {
    return (LLI) (p[a.second].x-p[a.first].x)*(p[b.second].y-p[b.first].y) \
        > (LLI) (p[a.second].y-p[a.first].y)*(p[b.second].x-p[b.first].x);
}
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d",&p[i].x,&p[i].y);
    sort(p,p+n,comp);

    int j;
    LLI ans = 0;
    for (i = 0; i < n; i++) pos[i] = i;
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) vv.pb(mp(i,j));
    }
    sort(vv.begin(),vv.end(),comp2);
    for (i = 0; i < vv.size(); i++) {
        swap(pos[vv[i].first],pos[vv[i].second]);
        int a = min(pos[vv[i].first],pos[vv[i].second]);
        int b = n-max(pos[vv[i].first],pos[vv[i].second])-1;
        ans += (LLI) (a*(a-1)/2)*(b*(b-1)/2);
    }
    printf("%I64d\n",ans);

    return 0;
}