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
#define MOD 998244353

int inv(LLI n) {
    int e = MOD-2;
    LLI r = 1;
    while (e > 0) {
        if (e & 1) r *= n,r %= MOD;
        e >>= 1;
        n *= n,n %= MOD;
    }
    return r;
}
int x[100000],v[100000],p[100000],invp[100000],invp2[100000];
int tree[1 << 18][4];
int com(int i,int mid) {
    tree[i][0] = ((((LLI) tree[2*i+1][0]*tree[2*i+2][0]) % MOD)*invp[mid+1]) % MOD;
    tree[i][0] += ((((LLI) tree[2*i+1][1]*tree[2*i+2][2]) % MOD)*invp2[mid+1]) % MOD;
    if (tree[i][0] >= MOD) tree[i][0] -= MOD;
    tree[i][1] = ((((LLI) tree[2*i+1][0]*tree[2*i+2][1]) % MOD)*invp[mid+1]) % MOD;
    tree[i][1] += ((((LLI) tree[2*i+1][1]*tree[2*i+2][3]) % MOD)*invp2[mid+1]) % MOD;
    if (tree[i][1] >= MOD) tree[i][1] -= MOD;
    tree[i][2] = ((((LLI) tree[2*i+1][2]*tree[2*i+2][0]) % MOD)*invp[mid+1]) % MOD;
    tree[i][2] += ((((LLI) tree[2*i+1][3]*tree[2*i+2][2]) % MOD)*invp2[mid+1]) % MOD;
    if (tree[i][2] >= MOD) tree[i][2] -= MOD;
    tree[i][3] = ((((LLI) tree[2*i+1][2]*tree[2*i+2][1]) % MOD)*invp[mid+1]) % MOD;
    tree[i][3] += ((((LLI) tree[2*i+1][3]*tree[2*i+2][3]) % MOD)*invp2[mid+1]) % MOD;
    if (tree[i][3] >= MOD) tree[i][3] -= MOD;
    return 0;
}
int build(int s,int e,int i) {
    if (s == e) {
        tree[i][0] = ((LLI) p[s]*p[s+1]) % MOD;
        tree[i][1] = ((LLI) p[s]*(MOD+1-p[s+1])) % MOD;
        tree[i][2] = ((LLI) (MOD+1-p[s])*p[s+1]) % MOD;
        tree[i][3] = ((LLI) (MOD+1-p[s])*(MOD+1-p[s+1])) % MOD;
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    com(i,mid);
    return 0;
}
int update(int s,int e,int ai,int i,int m) {
    if ((s > ai) || (e < ai)) return 0;
    else if (s == e) {
        tree[i][m] = 0;
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,ai,2*i+1,m),update(mid+1,e,ai,2*i+2,m);
    com(i,mid);
    return 0;
}
struct data { int n,d,i,m; };
bool comp(data a,data b) {
    return (LLI) a.n*b.d < (LLI) b.n*a.d;
}
vector<data> poss;
int main() {
    int i;
    int n;
    int inv100 = inv(100);
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d",&x[i],&v[i],&p[i]),p[i] = ((LLI) p[i]*inv100) % MOD;
        invp[i] = inv(p[i]),invp2[i] = inv(MOD+1-p[i]);
    }
    if (n == 1) {
        printf("0\n");
        return 0;
    }

    for (i = 1; i < n; i++) {
        poss.pb((data){x[i]-x[i-1],v[i]+v[i-1],i-1,1});
        if (v[i-1] > v[i]) poss.pb((data){x[i]-x[i-1],v[i-1]-v[i],i-1,0});
        else if (v[i-1] < v[i]) poss.pb((data){x[i]-x[i-1],v[i]-v[i-1],i-1,3});
    }
    sort(poss.begin(),poss.end(),comp);
    LLI ans = 0;
    build(0,n-2,0);
    for (i = 0; i < poss.size(); i++) {
        int p1 = ((LLI) tree[0][0]+tree[0][1]+tree[0][2]+tree[0][3]) % MOD;
        update(0,n-2,poss[i].i,0,poss[i].m);
        int p2 = ((LLI) tree[0][0]+tree[0][1]+tree[0][2]+tree[0][3]) % MOD;
        LLI v = ((LLI) poss[i].n*inv(poss[i].d)) % MOD;
        ans += v*(p1-p2+MOD),ans %= MOD;
    }
    printf("%I64d\n",ans);

    return 0;
}