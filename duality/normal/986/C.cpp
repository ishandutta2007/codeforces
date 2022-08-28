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

int a[1 << 22],b[1 << 22];
char visited[2 << 22];
int doDFS(int u,int m,int n) {
    if (visited[u]) return 0;
    visited[u] = 1;
    if (u < m) doDFS(a[u]+m,m,n);
    else {
        int i;
        u -= m;
        if (b[u] != -1) doDFS(b[u],m,n);
        for (i = 0; i < n; i++) {
            if (!(u & (1 << i))) doDFS((u | (1 << i))+m,m,n);
        }
    }
    return 0;
}
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    fill(b,b+(1 << n),-1);
    for (i = 0; i < m; i++) scanf("%d",&a[i]),b[((1 << n)-1)^a[i]] = i;
    int c = 0;
    for (i = 0; i < m; i++) {
        if (!visited[i]) doDFS(i,m,n),c++;
    }
    printf("%d\n",c);

    return 0;
}