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

int a[100000],used[100000];
vi sol[1000];
int nxt[100000],bit[100001];
int main() {
    int i,j;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i = 0; i < n; i++) scanf("%d",&a[i]);

        int c = 0;
        fill(used,used+n,0);
        int can = 1;
        while ((can+1)*(can+2)/2 <= n) can++;
        while (1) {
            vpii v;
            int r = 0;
            for (i = 0; i < n; i++) {
                if (!used[i]) {
                    int p = lower_bound(v.begin(),v.end(),mp(a[i],0))-v.begin();
                    if (p == v.size()) nxt[i] = v.empty() ? -1:v.back().second,v.pb(mp(a[i],i));
                    else v[p] = mp(a[i],i),nxt[i] = (p == 0) ? -1:v[p-1].second;
                    r++;
                }
            }
            if (r == 0) break;
            if (r-v.size() >= (can-c)*(can-c+1)/2) break;
            int u = v.back().second;
            while (u != -1) sol[c].pb(a[u]),used[u] = 1,u = nxt[u];
            reverse(sol[c].begin(),sol[c].end()),c++;
        }
        int k = c;
        fill(bit,bit+n+1,0);
        for (i = 0; i < n; i++) {
            if (!used[i]) {
                int m = 0;
                for (j = a[i]; j > 0; j -= j & (-j)) m = max(m,bit[j]);
                sol[c+m].pb(a[i]),k = max(k,c+m+1);
                for (j = a[i]; j <= n; j += j & (-j)) bit[j] = max(bit[j],m+1);
            }
        }
        printf("%d\n",k);
        for (i = 0; i < k; i++) {
            printf("%d",sol[i].size());
            for (j = 0; j < sol[i].size(); j++) printf(" %d",sol[i][j]);
            printf("\n");
            sol[i].clear();
        }
    }

    return 0;
}