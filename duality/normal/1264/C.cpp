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

int p[200000];
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
int num[200000];
plli tree[1 << 19];
plli com(plli a,plli b) {
    if (a == mp(-1LL,-1LL)) return b;
    else if (b == mp(-1LL,-1LL)) return a;
    else return mp((b.first+b.second*a.first) % MOD,(a.second*b.second) % MOD);
}
int build(int s,int e,int i) {
    if (s == e) {
        tree[i] = mp(num[s],num[s]);
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    tree[i] = com(tree[2*i+1],tree[2*i+2]);
    return 0;
}
plli query(int s,int e,int qs,int qe,int i) {
    if ((s > qe) || (e < qs)) return mp(-1,-1);
    else if ((s >= qs) && (e <= qe)) return tree[i];

    int mid = (s+e) / 2;
    return com(query(s,mid,qs,qe,2*i+1),query(mid+1,e,qs,qe,2*i+2));
}
set<int> check;
int main() {
    int i;
    int n,q,u;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) scanf("%d",&p[i]),num[i] = (100LL*inv(p[i])) % MOD;
    check.insert(0),check.insert(n);
    build(0,n-1,0);
    LLI ans = query(0,n-1,0,n-1,0).first;
    for (i = 0; i < q; i++) {
        scanf("%d",&u),u--;
        if (check.count(u)) {
            check.erase(u);
            auto it = check.lower_bound(u);
            auto it2 = it;
            it2--;
            ans -= query(0,n-1,*it2,u-1,0).first+query(0,n-1,u,*it-1,0).first;
            ans += query(0,n-1,*it2,*it-1,0).first;
        }
        else {
            check.insert(u);
            auto it = check.upper_bound(u);
            auto it2 = it;
            it2--,it2--;
            ans += query(0,n-1,*it2,u-1,0).first+query(0,n-1,u,*it-1,0).first;
            ans -= query(0,n-1,*it2,*it-1,0).first;
        }
        ans %= MOD;
        if (ans < 0) ans += MOD;
        printf("%d\n",(int) ans);
    }

    return 0;
}