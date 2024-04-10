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

char s[1000000];
int ans[1000000],pre[1000001],row[1000000];
int main() {
    int i;
    int t,n,m;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < n*m; i++) scanf(" %c",&s[i]);

        queue<int> col;
        for (i = 0; i < m; i++) col.push(0);
        int good = 0;
        for (i = 0; i < n*m; i++) {
            col.push(col.front()+(s[i]-'0'));
            good += (col.front()+(s[i]-'0') > 0)-(col.front() > 0);
            col.pop();
            ans[i] = good;
        }
        for (i = 0; i < n*m; i++) pre[i+1] = pre[i]+(s[i]-'0');
        for (i = 0; i < n*m; i++) {
            if (i < m) row[i] = (pre[i+1] > 0);
            else row[i] = (pre[i+1]-pre[i-m+1] > 0)+row[i-m];
            ans[i] += row[i];
        }
        for (i = 0; i < n*m; i++) printf("%d%c",ans[i],(i == n*m-1) ? '\n':' ');
    }

    return 0;
}