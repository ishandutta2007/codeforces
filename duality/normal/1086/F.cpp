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
#define INV2 499122177
#define INV6 166374059

int x[50],y[50];
vi v;
LLI getNum(int t,int n) {
    if (t == 0) return n;
    int i,j;
    LLI c = 0;
    for (i = 0; i < n; i++) {
        int l1 = x[i]-t,r1 = x[i]+t-1,l2 = x[i]-t+1,r2 = x[i]+t;
        int d1 = y[i]-t,u1 = y[i]+t-1,d2 = y[i]-t+1,u2 = y[i]+t;
        for (j = 0; j < n; j++) {
            if (i == j) continue;
            int l,r,d,u;
            if (j > i) l = x[j]-t+1,r = x[j]+t-1,d = y[j]-t+1,u = y[j]+t-1;
            else l = x[j]-t,r = x[j]+t,d = y[j]-t,u = y[j]+t;
            if ((y[i]+t >= d) && (y[i]+t <= u)) {
                if (l <= l1) l1 = max(l1,r+1);
                if (r >= r1) r1 = min(r1,l-1);
            }
            if ((y[i]-t >= d) && (y[i]-t <= u)) {
                if (l <= l2) l2 = max(l2,r+1);
                if (r >= r2) r2 = min(r2,l-1);
            }
            if ((x[i]-t >= l) && (x[i]-t <= r)) {
                if (d <= d1) d1 = max(d1,u+1);
                if (u >= u1) u1 = min(u1,d-1);
            }
            if ((x[i]+t >= l) && (x[i]+t <= r)) {
                if (d <= d2) d2 = max(d2,u+1);
                if (u >= u2) u2 = min(u2,d-1);
            }
        }
        c += max(r1-l1+1,0)+max(r2-l2+1,0)+max(u1-d1+1,0)+max(u2-d2+1,0);
    }
    return c;
}
int main() {
    int i;
    int n,t;
    scanf("%d %d",&n,&t);
    for (i = 0; i < n; i++) scanf("%d %d",&x[i],&y[i]);

    int j;
    LLI ans = 0;
    v.pb(0),v.pb(1),v.pb(t+1);
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            v.pb(max(abs(x[i]-x[j]),abs(y[i]-y[j]))/2);
            v.pb(max(abs(x[i]-x[j]),abs(y[i]-y[j]))/2+1);
        }
    }
    sort(v.begin(),v.end());
    while (v.back() > t+1) v.pop_back();
    v.resize(unique(v.begin(),v.end())-v.begin());
    for (i = 0; i < v.size()-1; i++) {
        if (v[i+1] == v[i]+1) ans += getNum(v[i],n)*v[i],ans %= MOD;
        else {
            LLI p = getNum(v[i],n) % MOD,q = getNum(v[i]+1,n) % MOD;
            LLI a = (q-p+MOD) % MOD,b = (p-(q-p)*v[i]) % MOD;
            if (b < 0) b += MOD;
            LLI s1 = ((((((LLI) (v[i]-1)*v[i]) % MOD)*(2*v[i]-1)) % MOD)*INV6) % MOD;
            LLI s2 = ((((((LLI) (v[i+1]-1)*v[i+1]) % MOD)*(2*v[i+1]-1)) % MOD)*INV6) % MOD;
            ans += (s2-s1+MOD)*a,ans %= MOD;
            s1 = ((((LLI) (v[i]-1)*v[i]) % MOD)*INV2) % MOD;
            s2 = ((((LLI) (v[i+1]-1)*v[i+1]) % MOD)*INV2) % MOD;
            ans += (s2-s1+MOD)*b,ans %= MOD;
        }
    }
    printf("%d\n",(int) ans);

    return 0;
}