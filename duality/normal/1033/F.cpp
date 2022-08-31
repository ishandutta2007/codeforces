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

int c[1 << 12];
LLI ways[1 << 24];
char s[12];
LLI doDFS(int c,int m,int m2) {
    if (c == 12) return ways[(m << 12) | m2];
    if (s[c] == 'A') return doDFS(c+1,m,m2)+doDFS(c+1,m^(1 << c),m2);
    else if (s[c] == 'O') return doDFS(c+1,m,m2);
    else if (s[c] == 'X') return doDFS(c+1,m,m2)+doDFS(c+1,m,m2^(1 << c));
    else if (s[c] == 'a') return doDFS(c+1,m,m2^(1 << c));
    else if (s[c] == 'o') return doDFS(c+1,m^(1 << c),m2)+doDFS(c+1,m,m2^(1 << c));
    else return doDFS(c+1,m^(1 << c),m2);
}
int main() {
    int i,j;
    int w,n,m,a;
    scanf("%d %d %d",&w,&n,&m);
    for (i = 0; i < n; i++) scanf("%d",&a),c[a]++;
    for (i = 0; i < (1 << 12); i++) {
        for (j = 0; j < (1 << 12); j++) ways[((i^j) << 12)|(i & j)] += (LLI) c[i]*c[j];
    }
    for (i = 0; i < m; i++) {
        vi v;
        for (j = 0; j < w; j++) scanf(" %c",&s[j]);
        reverse(s,s+w);
        for (j = w; j < 12; j++) s[j] = 'O';
        printf("%I64d\n",doDFS(0,0,0));
    }

    return 0;
}