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

int MOD;
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
map<int,int> occ;
vpii v;
int findSizes(int s,int h) {
    if ((h == 1) || (s == 1)) occ[s]++;
    else findSizes(s/2,h-1),findSizes((s+1)/2,h-1);
    return 0;
}
int main() {
    int n,k;
    cin >> n >> k >> MOD;
    findSizes(n,k);
    for (auto it = occ.begin(); it != occ.end(); it++) v.pb(*it);

    int i,j;
    LLI ans = 0;
    for (i = 0; i < v.size(); i++) {
        LLI x = ((LLI) v[i].first*(v[i].first-1)) % MOD;
        x *= inv(4),x %= MOD;
        ans += v[i].second*x,ans %= MOD;
    }
    for (i = 0; i < v.size(); i++) {
        for (j = i; j < v.size(); j++) {
            LLI o = ((LLI) v[i].second*v[j].second) % MOD;
            if (i == j) o = ((LLI) v[i].second*(v[i].second-1)/2) % MOD;
            for (k = 2; k <= v[i].first+v[j].first; k++) {
                LLI c = (inv(2)-inv(k)+MOD) % MOD;
                c *= o,c %= MOD;
                ans += c*(min(k-1,v[i].first)-max(k-v[j].first,1)+1),ans %= MOD;
            }
        }
    }
    cout << ans << endl;

    return 0;
}