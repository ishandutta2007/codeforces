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

int a[200000];
pii p[200000];
vpii v[200000];
int ans[200000];
int bit[200001];
int main() {
    int i,j;
    int n,m,k,pos;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),p[i] = mp(-a[i],i);
    sort(p,p+n);
    scanf("%d",&m);
    for (i = 0; i < m; i++) scanf("%d %d",&k,&pos),v[k-1].pb(mp(pos,i));

    for (i = 0; i < n; i++) {
        for (j = p[i].second+1; j <= n; j += j & (-j)) bit[j]++;
        for (j = 0; j < v[i].size(); j++) {
            int l = 0,r = n;
            while (l < r) {
                int m = (l+r) / 2;

                int sum = 0;
                for (k = m+1; k > 0; k -= k & (-k)) sum += bit[k];
                if (sum < v[i][j].first) l = m+1;
                else r = m;
            }
            ans[v[i][j].second] = a[l];
        }
    }
    for (i = 0; i < m; i++) printf("%d\n",ans[i]);

    return 0;
}