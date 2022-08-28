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

int a[1 << 20],size[1 << 20],depth[1 << 20];
queue<int> Q;
vi ans;
int main() {
    int i;
    int t,h,g;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&h,&g);
        for (i = 1; i < (1 << h); i++) scanf("%d",&a[i]);

        for (i = (1 << (h-1)); i < (1 << h); i++) size[i] = 1;
        for (i = (1 << (h-1))-1; i >= 1; i--) size[i] = size[2*i]+size[2*i+1]+1;
        depth[1] = 1;
        for (i = 2; i < (1 << h); i++) depth[i] = depth[i/2]+1;
        Q.push(1);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            printVar(u);

            int c = u;
            while (size[c] > 1) {
                if (a[2*c] > a[2*c+1]) c = 2*c;
                else c = 2*c+1;
            }
            printVar(c);
            if (depth[c] == g) {
                if (depth[u] < g) {
                    Q.push(2*u);
                    Q.push(2*u+1);
                }
                continue;
            }
            c = u;
            Q.push(u);
            ans.pb(u);
            while (size[c] > 1) {
                size[c]--;
                if (a[2*c] > a[2*c+1]) a[c] = a[2*c],c = 2*c;
                else a[c] = a[2*c+1],c = 2*c+1;
            }
            size[c] = 0,a[c] = 0;
            printArr(a,(1 << h));
        }

        LLI sum = 0;
        for (i = 1; i < (1 << g); i++) sum += a[i];
        printf("%I64d\n",sum);
        for (i = 0; i < ans.size(); i++) printf("%d ",ans[i]);
        printf("\n");
        ans.clear();
    }

    return 0;
}