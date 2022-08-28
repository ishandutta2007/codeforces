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
#define MOD 1000000007

vi tree[1 << 15];
int update(int s,int e,int as,int ae,int i,int x) {
    if ((s > ae) || (e < as)) return 0;
    else if ((s >= as) && (e <= ae)) {
        tree[i].pb(x);
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1,x);
    update(mid+1,e,as,ae,2*i+2,x);
    return 0;
}
bitset<10001> ret[1 << 15];
int query(int s,int e,int i) {
    if (s == e) {
        ret[i][0] = 1;
        while (!tree[i].empty()) ret[i] |= (ret[i] << tree[i].back()),tree[i].pop_back();
        return 0;
    }

    int mid = (s+e) / 2;
    query(s,mid,2*i+1);
    query(mid+1,e,2*i+2);
    ret[i] = ret[2*i+1] | ret[2*i+2];
    while (!tree[i].empty()) ret[i] |= (ret[i] << tree[i].back()),tree[i].pop_back();
    return 0;
}
int main() {
    int i;
    int n,q,l,r,x;
    scanf("%d %d",&n,&q);
    for (i = 0; i < q; i++) {
        scanf("%d %d %d",&l,&r,&x);
        update(0,n-1,l-1,r-1,0,x);
    }
    query(0,n-1,0);

    int k = 0;
    for (i = 1; i <= n; i++) {
        if (ret[0][i]) k++;
    }
    printf("%d\n",k);
    for (i = 1; i <= n; i++) {
        if (ret[0][i]) {
            printf("%d%c",i,(k == 1) ? '\n':' ');
            k--;
        }
    }

    return 0;
}