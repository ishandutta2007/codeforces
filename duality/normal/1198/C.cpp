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

int u[500000],v[500000];
int used[300000];
vi match;
int main() {
    int i;
    int T,n,m;
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < m; i++) {
            scanf("%d %d",&u[i],&v[i]);
            u[i]--,v[i]--;
        }

        fill(used,used+3*n,0);
        for (i = 0; i < m; i++) {
            if (!used[u[i]] && !used[v[i]]) {
                used[u[i]] = used[v[i]] = 1;
                match.pb(i);
            }
        }
        if (match.size() >= n) {
            printf("Matching\n");
            for (i = 0; i < n; i++) printf("%d ",match[i]+1);
            printf("\n");
        }
        else {
            match.clear();
            for (i = 0; i < 3*n; i++) {
                if (!used[i]) match.pb(i);
            }
            printf("IndSet\n");
            for (i = 0; i < n; i++) printf("%d ",match[i]+1);
            printf("\n");
        }

        match.clear();
    }

    return 0;
}