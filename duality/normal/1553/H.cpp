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

int trie[1100000][2],num = 0;
struct info { vi s,b,v; };
info getAns(int u,int d) {
    if (d == 0) {
        info f;
        f.s = f.b = vi(1,0),f.v = vi(1,1e9);
        return f;
    }
    
    int i;
    info f;
    f.s = f.b = f.v = vi(1 << d);
    if (trie[u][0] == 0) {
        info ff = getAns(trie[u][1],d-1);
        for (i = 0; i < (1 << d); i++) {
            f.s[i] = ff.s[i & ((1 << (d-1))-1)];
            f.b[i] = ff.b[i & ((1 << (d-1))-1)];
            if (!(i & (1 << (d-1)))) f.s[i] |= (1 << (d-1)),f.b[i] |= (1 << (d-1));
            f.v[i] = ff.v[i & ((1 << (d-1))-1)];
        }
    }
    else if (trie[u][1] == 0) {
        info ff = getAns(trie[u][0],d-1);
        for (i = 0; i < (1 << d); i++) {
            f.s[i] = ff.s[i & ((1 << (d-1))-1)];
            f.b[i] = ff.b[i & ((1 << (d-1))-1)];
            if (i & (1 << (d-1))) f.s[i] |= (1 << (d-1)),f.b[i] |= (1 << (d-1));
            f.v[i] = ff.v[i & ((1 << (d-1))-1)];
        }
    }
    else {
        info ff1 = getAns(trie[u][0],d-1);
        info ff2 = getAns(trie[u][1],d-1);
        for (i = 0; i < (1 << d); i++) {
            f.v[i] = min(ff1.v[i & ((1 << (d-1))-1)],ff2.v[i & ((1 << (d-1))-1)]);
            if (i & (1 << (d-1))) {
                f.s[i] = ff2.s[i & ((1 << (d-1))-1)];
                f.b[i] = ff1.b[i & ((1 << (d-1))-1)] | (1 << (d-1));
                f.v[i] = min(f.v[i],ff1.s[i & ((1 << (d-1))-1)]-ff2.b[i & ((1 << (d-1))-1)]+(1 << (d-1)));
            }
            else {
                f.s[i] = ff1.s[i & ((1 << (d-1))-1)];
                f.b[i] = ff2.b[i & ((1 << (d-1))-1)] | (1 << (d-1));
                f.v[i] = min(f.v[i],ff2.s[i & ((1 << (d-1))-1)]-ff1.b[i & ((1 << (d-1))-1)]+(1 << (d-1)));
            }
        }
    }
    return f;
}
int main() {
    int i,j;
    int n,k,a;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; i++) {
        scanf("%d",&a);
        int u = 0;
        for (j = k-1; j >= 0; j--) {
            int b = (a >> j) & 1;
            if (trie[u][b] == 0) trie[u][b] = ++num;
            u = trie[u][b];
        }
    }
    info f = getAns(0,k);
    for (i = 0; i < (1 << k); i++) printf("%d ",f.v[i]);
    printf("\n");
    
    return 0;
}