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

int e[100000],c[100000],d[100000],other[100001];
int inv(LLI n) {
    LLI r = 1;
    int e = MOD-2;
    while (e > 0) {
        if (e & 1) r *= n,r %= MOD;
        e >>= 1;
        n *= n,n %= MOD;
    }
    return r;
}
int invn[200001];
struct query { int l,r,i; };
vector<query> v[100001];
int B;
bool comp(query a,query b) {
    if (a.l/B == b.l/B) {
        if ((a.l/B) & 1) return a.r > b.r;
        else return a.r < b.r;
    }
    else return a.l/B < b.l/B;
}
int ans[100000];
LLI aa;
int add(int p,int k) {
    aa *= c[e[p]]+k-d[e[p]],aa %= MOD,d[e[p]]++;
    return 0;
}
int del(int p,int k) {
    d[e[p]]--,aa *= invn[c[e[p]]+k-d[e[p]]],aa %= MOD;
    return 0;
}
int main() {
    int i;
    int n,m,q;
    int l,r,k;
    scanf("%d %d %d",&n,&m,&q);
    for (i = 0; i < n; i++) scanf("%d",&e[i]),c[--e[i]]++;
    for (i = 0; i < q; i++) scanf("%d %d %d",&l,&r,&k),v[k].pb((query){l-1,r-1,i});

    int j;
    for (i = 1; i <= 200000; i++) invn[i] = inv(i);
    for (i = 0; i <= 100000; i++) {
        if (v[i].empty()) continue;
        B = n/sqrt(v[i].size())+1;
        sort(v[i].begin(),v[i].end(),comp);
        int l = 0,r = -1;
        other[n] = 1;
        for (j = n-1; j >= 1; j--) other[j] = (other[j+1]*(((LLI) i*m+n-j) % MOD)) % MOD;
        aa = 1;
        for (j = 0; j < v[i].size(); j++) {
            while (l > v[i][j].l) add(--l,i);
            while (r < v[i][j].r) add(++r,i);
            while (l < v[i][j].l) del(l++,i);
            while (r > v[i][j].r) del(r--,i);
            ans[v[i][j].i] = (aa*other[r-l+1]) % MOD;
        }
        fill(d,d+m,0);
    }
    for (i = 0; i < q; i++) printf("%d\n",ans[i]);

    return 0;
}