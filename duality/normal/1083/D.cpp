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

int a[100000],l[100000],r[100000],pos[100000];
vi sorted;
int sumA[1 << 18],sumB[1 << 18],sumProd[1 << 18];
int lazyA[1 << 18],lazyB[1 << 18];
int prop(int s,int e,int i) {
    sumProd[i] += ((LLI) lazyA[i]*sumB[i]) % MOD,sumProd[i] %= MOD;
    sumA[i] += ((LLI) (e-s+1)*lazyA[i]) % MOD,sumA[i] %= MOD;
    sumProd[i] += ((LLI) lazyB[i]*sumA[i]) % MOD,sumProd[i] %= MOD;
    sumB[i] += ((LLI) (e-s+1)*lazyB[i]) % MOD,sumB[i] %= MOD;
    if (s != e) {
        lazyA[2*i+1] = (lazyA[2*i+1]+lazyA[i]) % MOD,lazyA[2*i+2] = (lazyA[2*i+2]+lazyA[i]) % MOD;
        lazyB[2*i+1] = (lazyB[2*i+1]+lazyB[i]) % MOD,lazyB[2*i+2] = (lazyB[2*i+2]+lazyB[i]) % MOD;
    }
    lazyA[i] = lazyB[i] = 0;
    return 0;
}
int update(int s,int e,int as,int ae,int i,int num,int t) {
    prop(s,e,i);
    if ((s > ae) || (e < as)) return 0;
    else if ((s >= as) && (e <= ae)) {
        if (t == 0) lazyA[i] = (lazyA[i]+num) % MOD;
        else lazyB[i] = (lazyB[i]+num) % MOD;
        prop(s,e,i);
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1,num,t),update(mid+1,e,as,ae,2*i+2,num,t);
    sumA[i] = (sumA[2*i+1]+sumA[2*i+2]) % MOD,sumB[i] = (sumB[2*i+1]+sumB[2*i+2]) % MOD;
    sumProd[i] = (sumProd[2*i+1]+sumProd[2*i+2]) % MOD;
    return 0;
}
int query(int s,int e,int qs,int qe,int i) {
    prop(s,e,i);
    if ((s > qe) || (e < qs)) return 0;
    else if ((s >= qs) && (e <= qe)) return sumProd[i];

    int mid = (s+e) / 2;
    return (query(s,mid,qs,qe,2*i+1)+query(mid+1,e,qs,qe,2*i+2)) % MOD;
}
vpii v1,v2;
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),sorted.pb(a[i]);
    sort(sorted.begin(),sorted.end());
    sorted.resize(unique(sorted.begin(),sorted.end())-sorted.begin());
    for (i = 0; i < n; i++) a[i] = lower_bound(sorted.begin(),sorted.end(),a[i])-sorted.begin();

    fill(pos,pos+n,-1);
    for (i = 0; i < n; i++) l[i] = pos[a[i]],pos[a[i]] = i;
    fill(pos,pos+n,n);
    for (i = n-1; i >= 0; i--) r[i] = pos[a[i]],pos[a[i]] = i;
    fill(pos,pos+n,-1);
    int L = 0,ans = 0;
    v1.pb(mp(-1,n+10)),v2.pb(mp(-1,-10));
    for (i = 0; i < n; i++) {
        update(0,n-1,i,i,0,i-l[i]-1,0),update(0,n-1,i,i,0,r[i]-i-1,1);
        int p = i;
        while (l[i] >= v1.back().second) {
            update(0,n-1,v1.back().first,p-1,0,(v1.back().second-l[i]+MOD) % MOD,0);
            p = v1.back().first,v1.pop_back();
        }
        v1.pb(mp(p,l[i]));
        p = i;
        while (r[i] <= v2.back().second) {
            update(0,n-1,v2.back().first,p-1,0,(r[i]-v2.back().second+MOD) % MOD,1);
            p = v2.back().first,v2.pop_back();
        }
        v2.pb(mp(p,r[i]));
        if (pos[a[i]] != -1) L = max(L,pos[a[i]]+1);
        pos[a[i]] = i;
        ans += query(0,n-1,L,i,0),ans %= MOD;
        update(0,n-1,0,i,0,MOD-1,1);
    }
    printf("%d\n",ans);

    return 0;
}