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

LLI gcd(LLI a,LLI b) {
    LLI t;
    while (a > 0) t = b % a,b = a,a = t;
    return b;
}
LLI c[500005];
vi adj[500005];
int num[500005],cc;
int size[500005];
LLI sum[500005];
int main() {
    int i,j,k;
    int t,n,m,u,v;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < n; i++) scanf("%I64d",&c[i]);
        for (i = 0; i < m; i++) {
            scanf("%d %d",&u,&v);
            u--,v--;
            adj[u].pb(v);
        }

        cc = 1;
        for (i = 0; i < n; i++) num[i] = 0;
        size[0] = n;
        for (i = 0; i < n; i++) {
            vpii v;
            for (j = 0; j < adj[i].size(); j++) v.pb(mp(num[adj[i][j]],adj[i][j]));
            sort(v.begin(),v.end());
            j = 0;
            while (j < v.size()) {
                k = j;
                while ((k < v.size()) && (v[k].first == v[j].first)) k++;
                int e = k;
                for (k = j; k < e; k++) num[v[k].second] = cc;
                cc++;
                j = e;
            }
        }
        fill(sum,sum+cc,0);
        for (i = 0; i < n; i++) sum[num[i]] += c[i];
        LLI g = 0;
        for (i = 1; i < cc; i++) g = gcd(g,sum[i]);//,cout<<"sum:"<<sum[i]<<endl;
        printf("%I64d\n",g);

        for (i = 0; i < n; i++) adj[i].clear();
    }

    return 0;
}