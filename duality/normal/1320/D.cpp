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
#define MOD1 1000000007
#define S1 37
#define MOD2 1000000009
#define S2 41

int inv(LLI n,int MOD) {
    int e = MOD-2;
    LLI r = 1;
    while (e > 0) {
        if (e & 1) r *= n,r %= MOD;
        e >>= 1;
        n *= n,n %= MOD;
    }
    return r;
}
int INV1 = inv(S1,MOD1),INV2 = inv(S2,MOD2);
char t[200000];
int num[200000];
LLI power[200001],power2[200001];
struct node {
    LLI h1,h2;
    int len;
    int s,e;
};
node com(node a,node b) {
    if (a.len == 0) return b;
    else if (b.len == 0) return a;
    node c;
    if (a.e && b.s) {
        c.h1 = (MOD1+a.h1-power[a.len-1]+((power[a.len-1]*(b.h1-1)) % MOD1)*INV1) % MOD1;
        c.h2 = (MOD2+a.h2-power2[a.len-1]+((power2[a.len-1]*(b.h2-1)) % MOD2)*INV2) % MOD2;
        c.len = a.len+b.len-2;
        c.s = a.s,c.e = b.e;
        if (a.len == 1) c.s = 0;
        if (b.len == 1) c.e = 0;
    }
    else {
        c.h1 = (a.h1+power[a.len]*b.h1) % MOD1;
        c.h2 = (a.h2+power2[a.len]*b.h2) % MOD2;
        c.len = a.len+b.len;
        c.s = a.s,c.e = b.e;
    }
    return c;
}
node tree[1 << 19];
int build(int s,int e,int i) {
    if (s == e) {
        tree[i] = (node){num[s],num[s],1,t[s]-'0',t[s]-'0'};
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    tree[i] = com(tree[2*i+1],tree[2*i+2]);
    return 0;
}
node query(int s,int e,int qs,int qe,int i) {
    if ((s > qe) || (e < qs)) return (node){0,0,0,0,0};
    else if ((s >= qs) && (e <= qe)) return tree[i];

    int mid = (s+e) / 2;
    return com(query(s,mid,qs,qe,2*i+1),query(mid+1,e,qs,qe,2*i+2));
}
int main() {
    int i;
    int n,q;
    int l1,l2,len;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf(" %c",&t[i]),num[i] = (t[i] == '1') ? 1:3;
    power[0] = 1;
    for (i = 1; i <= n; i++) power[i] = (S1*power[i-1]) % MOD1;
    power2[0] = 1;
    for (i = 1; i <= n; i++) power2[i] = (S2*power2[i-1]) % MOD2;
    build(0,n-1,0);
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d %d %d",&l1,&l2,&len);
        l1--,l2--;
        node a = query(0,n-1,l1,l1+len-1,0),b = query(0,n-1,l2,l2+len-1,0);
        if (a.len == 0) a.s = a.e = -1;
        if (b.len == 0) b.s = b.e = -1;
        if ((a.h1 == b.h1) && (a.h2 == b.h2) && (a.len == b.len) && (a.s == b.s) && (a.e == b.e)) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}