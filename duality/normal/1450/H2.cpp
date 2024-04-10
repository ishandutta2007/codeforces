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

int modPow(int b,int e) {
    int r = 1;
    while (e > 0) {
        if (e & 1) r = ((LLI) r*b) % MOD;
        e >>= 1;
        b = ((LLI) b*b) % MOD;
    }
    return r;
}
int inv(int n) {
    return modPow(n,MOD-2);
}
int fact[200001],invfact[200001];
int C(int n,int k) {
    if ((k > n) || (k < 0)) return 0;
    else return ((((LLI) fact[n]*invfact[k]) % MOD)*invfact[n-k]) % MOD;
}
int X[2],L[2],R[2];
LLI A[2] = {1,1};
int query(int xx,int ll,int rr,int t) {
    int &x = X[t],&l = L[t],&r = R[t];
    LLI &a = A[t];
    while (x < xx) a = (2*a-C(x,r)+C(x,l-1)) % MOD,x++;
    while (x > xx) a = ((a+C(x-1,r)-C(x-1,l-1))*((MOD+1)/2)) % MOD,x--;
    while (l < ll) a = (a-C(x,l++)) % MOD;
    while (l > ll) a = (a+C(x,--l)) % MOD;
    while (r < rr) a = (a+C(x,++r)) % MOD;
    while (r > rr) a = (a-C(x,r--)) % MOD;
    return a;
}
int query(int xx,int ll,int rr,int p,int t) {
    if (xx < 0) return 0;
    ll = max(ll,0),rr = min(rr,xx);
    while ((ll & 1) != p) ll++;
    while ((rr & 1) != p) rr--;
    if (ll > rr) return 0;
    else {
        if (xx == 0) return 1;
        else return query(xx-1,ll-1,rr,t);
    }
}
int getAns(int b,int x,int n) {
    int p = (n/2+b) & 1;
    LLI ans = (LLI) query(x,n/2-b,x,p,0)*(b-n/2)+(LLI) x*query(x-1,n/2-b-1,x-1,!p,0);
    LLI ans2 = (LLI) query(x,0,n/2-b-1,p,1)*(n/2-b)-(LLI) x*query(x-1,0,n/2-b-2,!p,1);
    ans += ans2,ans %= MOD;
    ans *= modPow((MOD+1)/2,x),ans %= MOD;
    if (ans < 0) ans += MOD;
    return ans;
}
char s[200000];
int main() {
    int i;
    int n,m,b = 0,x = 0,p;
    char c;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        scanf(" %c",&s[i]);
        if (i & 1) {
            if (s[i] == 'b') s[i] = 'w';
            else if (s[i] == 'w') s[i] = 'b';
        }
        b += (s[i] == 'b'),x += (s[i] == '?');
    }
    fact[0] = 1;
    for (i = 1; i <= n; i++) fact[i] = ((LLI) i*fact[i-1]) % MOD;
    for (i = 0; i <= n; i++) invfact[i] = inv(fact[i]);
    printf("%d\n",getAns(b,x,n));
    for (i = 0; i < m; i++) {
        scanf("%d %c",&p,&c),p--;
        b -= (s[p] == 'b'),x -= (s[p] == '?');
        s[p] = c;
        if (p & 1) {
            if (s[p] == 'b') s[p] = 'w';
            else if (s[p] == 'w') s[p] = 'b';
        }
        b += (s[p] == 'b'),x += (s[p] == '?');
        printf("%d\n",getAns(b,x,n));
    }

    return 0;
}