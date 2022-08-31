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

int a[200000],w[200000];
LLI bit1[200001],bit2[200001];
int update(int i,LLI num,int n,LLI *bit,int m) {
    for (i++; i <= n; i += i & (-i)) {
        bit[i] += num;
        if (m) bit[i] %= MOD;
    }
    return 0;
}
LLI query(int i,LLI *bit,int m) {
    LLI sum = 0;
    for (i++; i > 0; i -= i & (-i)) {
        sum += bit[i];
        if (m) sum %= MOD;
    }
    return sum;
}
int main() {
    int i;
    int n,q,x,y;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),a[i] -= i;
    for (i = 0; i < n; i++) scanf("%d",&w[i]),update(i,w[i],n,bit1,0),update(i,((LLI) a[i]*w[i]) % MOD,n,bit2,1);
    for (i = 0; i < q; i++) {
        scanf("%d %d",&x,&y);
        if (x < 0) {
            x = -x-1;
            update(x,-w[x],n,bit1,0),update(x,MOD-(((LLI) a[x]*w[x]) % MOD),n,bit2,1);
            w[x] = y;
            update(x,w[x],n,bit1,0),update(x,((LLI) a[x]*w[x]) % MOD,n,bit2,1);
        }
        else {
            x--,y--;
            LLI z = query(x-1,bit1,0);
            LLI total = query(y,bit1,0)-z;
            int l = x,r = y;
            while (l < r) {
                int m = (l+r) / 2;
                LLI zz = query(m,bit1,0)-z;
                if (zz >= (total+1)/2) r = m;
                else l = m+1;
            }
            printVar(l);
            LLI ans = 0;
            ans -= query(l-1,bit2,1)-query(x-1,bit2,1);
            ans += (((query(l-1,bit1,0)-z) % MOD)*a[l]) % MOD;
            ans += query(y,bit2,1)-query(l,bit2,1);
            ans -= (((query(y,bit1,0)-query(l,bit1,0)) % MOD)*a[l]) % MOD;
            ans %= MOD;
            if (ans < 0) ans += MOD;
            printf("%I64d\n",ans);
        }
    }

    return 0;
}