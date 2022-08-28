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

pii p[200000];
int c[200000];
int bit[200001];
vi v;
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d",&p[i].y,&p[i].x),v.pb(p[i].y);
    sort(p,p+n,greater<pii>());
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());

    for (i = 0; i < n; i++) p[i].y = lower_bound(v.begin(),v.end(),p[i].y)-v.begin();

    int j,k;
    LLI ans = 0;
    vi toAdd;
    int num = 0;
    for (i = 0; i < n; i++) {
        toAdd.pb(p[i].y);
        if ((i == n-1) || (p[i].x != p[i+1].x)) {
            sort(toAdd.begin(),toAdd.end());
            for (j = 0; j < toAdd.size(); j++) {
                if (c[toAdd[j]] == 0) {
                    c[toAdd[j]] = 1,num++;
                    for (k = toAdd[j]+1; k <= v.size(); k += k & (-k)) bit[k]++;
                }
            }
            ans += ((LLI) num*(num+1))/2;
            toAdd.pb(v.size());
            for (j = 0; j < toAdd.size(); j++) {
                int x = 0;
                for (k = toAdd[j]; k > 0; k -= k & (-k)) x += bit[k];
                for (k = (j == 0) ? 0:toAdd[j-1]+1; k > 0; k -= k & (-k)) x -= bit[k];
                ans -= ((LLI) x*(x+1))/2;
            }
            toAdd.clear();
        }
    }
    printf("%I64d\n",ans);

    return 0;
}