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

int C[20][20];
vi v[16];
int modPow(int b,int e) {
    int r = 1;
    while (e > 0) {
        if (e & 1) r = ((LLI) r*b) % MOD;
        e >>= 1;
        b = ((LLI) b*b) % MOD;
    }
    return r;
}
struct info { int k,x,w; };
bool comp(info a,info b) {
    if (a.k == b.k) return a.x < b.x;
    else return a.k < b.k;
}
vector<info> dp[16];
info dp2[17][100000];
int ss[17];
int tempa[17][1 << 16],tempb[17][1 << 16],tempc[17][1 << 16];
int FWHT(int *arr,int c) {
    int i,j,k;
    for (k = 1; k < (1 << c); k <<= 1) {
        for (i = 0; i < (1 << c); i += 2*k) {
            for (j = 0; j < k; j++) {
                int u = arr[i+j],v = arr[i+j+k];
                arr[i+j] = u+v,arr[i+j+k] = u-v;
                if (arr[i+j] >= MOD) arr[i+j] -= MOD;
                if (arr[i+j+k] < 0) arr[i+j+k] += MOD;
            }
        }
    }
    return 0;
}
vector<info> com(vector<info> a,vector<info> b,int K,int c) {
    if ((LLI) a.size()*b.size() < ((K*(c+K/2)) << c)) {
        int i,j;
        vector<info> ans;
        ans.reserve(a.size()*b.size());
        for (i = 0; i < a.size(); i++) {
            for (j = 0; j < b.size(); j++) {
                if (a[i].k+b[j].k <= K) ans.pb((info){a[i].k+b[j].k,a[i].x^b[j].x, \
                    ((((LLI) a[i].w*b[j].w) % MOD)*C[a[i].k+b[j].k][a[i].k]) % MOD});
            }
        }
        return ans;
    }

    int i,j,k;
    vector<info> ans;
    ans.reserve(K << c);
    memset(tempa,0,sizeof(tempa));
    memset(tempb,0,sizeof(tempb));
    memset(tempc,0,sizeof(tempc));
    for (i = 0; i < a.size(); i++) {
        tempa[a[i].k][a[i].x] += a[i].w;
        if (tempa[a[i].k][a[i].x] >= MOD) tempa[a[i].k][a[i].x] -= MOD;
    }
    for (i = 0; i < b.size(); i++) {
        tempb[b[i].k][b[i].x] += b[i].w;
        if (tempb[b[i].k][b[i].x] >= MOD) tempb[b[i].k][b[i].x] -= MOD;
    }
    for (i = 0; i <= K; i++) FWHT(tempa[i],c),FWHT(tempb[i],c);
    for (i = 0; i <= K; i++) {
        for (j = 0; j <= K-i; j++) {
            for (k = 0; k < (1 << c); k++) tempc[i+j][k] = (tempc[i+j][k]+(((LLI) tempa[i][k]*tempb[j][k]) % MOD)*C[i+j][i]) % MOD;
        }
    }
    int inv = modPow((1 << c),MOD-2);
    for (i = 0; i <= K; i++) {
        FWHT(tempc[i],c);
        for (j = 0; j < (1 << c); j++) {
            tempc[i][j] = ((LLI) tempc[i][j]*inv) % MOD;
            if (tempc[i][j] > 0) ans.pb((info){i,j,tempc[i][j]});
        }
    }
    return ans;
}
vector<info> comAll(int l,int r,int K,int c) {
    if (l == r) return dp[l];
    int m = (l+r) / 2;
    return com(comAll(l,m,K,c),comAll(m+1,r,K,c),K,c);
}
int ans[1 << 16];
int main() {
    int i,j;
    for (i = 0; i < 20; i++) {
        C[i][0] = 1;
        for (j = 1; j <= i; j++) C[i][j] = (C[i-1][j-1]+C[i-1][j]) % MOD;
    }
    int n,K,c,a;
    scanf("%d %d %d",&n,&K,&c);
    for (i = 0; i < n; i++) {
        scanf("%d",&a);
        for (j = c-1; j >= 0; j--) {
            if ((a^(a-K)) & (1 << j)) break;
        }
        v[j].pb(a);
    }

    int k,l;
    for (i = 0; i < c; i++) {
        dp[i].pb((info){0,0,1});
        for (j = 0; j < v[i].size(); j++) {
            for (l = 0; l < dp[i].size(); l++) {
                for (k = 0; k <= K-dp[i][l].k; k++) {
                    int kk = dp[i][l].k+k;
                    dp2[kk][ss[kk]++] = (info){kk,dp[i][l].x^(v[i][j]-k),((LLI) dp[i][l].w*C[kk][k]) % MOD};
                }
            }
            dp[i].clear();
            for (k = 0; k <= K; k++) {
                int s = dp2[k][0].x,b = dp2[k][0].x;
                for (l = 0; l < ss[k]; l++) s = min(s,dp2[k][l].x),b = max(b,dp2[k][l].x);
                vi ways(b-s+1);
                for (l = 0; l < ss[k]; l++) {
                    ways[dp2[k][l].x-s] += dp2[k][l].w;
                    if (ways[dp2[k][l].x-s] >= MOD) ways[dp2[k][l].x-s] -= MOD;
                }
                for (l = s; l <= b; l++) {
                    if (ways[l-s] > 0) dp[i].pb((info){k,l,ways[l-s]});
                }
                ss[k] = 0;
            }
        }
    }
    vector<info> vv = comAll(0,c-1,K,c);
    for (i = 0; i < vv.size(); i++) {
        if (vv[i].k == K) ans[vv[i].x] += vv[i].w,ans[vv[i].x] %= MOD;
    }
    int r = modPow(n,K);
    r = modPow(r,MOD-2);
    for (i = 0; i < (1 << c); i++) printf("%I64d ",((LLI) ans[i]*r) % MOD);
    printf("\n");

    return 0;
}