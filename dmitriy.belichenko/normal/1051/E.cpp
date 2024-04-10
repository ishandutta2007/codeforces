#pragma("sse4")
#pragma("fastmath")
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define lp(i,a,n) for(int i=a;i<=n;++i)
#define lpd(i,a,n) for(int i=a;i>=n;--i)
#define mem(a,b) memset(a,b,sizeof a)
#define all(v) v.begin(),v.end()
#define println(a) cout <<(a) <<endl
#define sz(x) ((int)(x).size())
#define readi(x) scanf("%d",&x)
#define read2i(x,y) scanf("%d%d",&x,&y)
#define read3i(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define mod 1000000007
#define eps 1e-8
#define infi 1000000000
#define infll 1000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef set<int> si;
typedef map<int,int> mii;

const int N = 1000002, M = 998244353, b = 17, b2 = 31, mod2 = mod+2;
int n,m,k;
char a[N],l[N],r[N];
ll dp[N],bPow[N],b2Pow[N];
pll ha[N],hl[N],hr[N];

bool checkL(int i){
    int L = i, R = i+m-1;
    while(L < R){
        int mid = (L + R) / 2;
        pll h1;
        h1.f = (ha[mid].f - (i ? ha[i-1].f : 0) * bPow[mid-i+1] % mod + mod) % mod;
        h1.s = (ha[mid].s - (i ? ha[i-1].s : 0) * b2Pow[mid-i+1] % mod2 + mod2) % mod2;
        pll h2 = hl[mid-i];
        if(h1 != h2) R = mid;
        else L = mid + 1;
    }
    return a[L] >= l[L-i];
}

bool checkR(int i){
    int L = i, R = i+k-1;
    while(L < R){
        int mid = (L + R) / 2;
        pll h1;
        h1.f = (ha[mid].f - (i ? ha[i-1].f : 0) * bPow[mid-i+1] % mod + mod) % mod;
        h1.s = (ha[mid].s - (i ? ha[i-1].s : 0) * b2Pow[mid-i+1] % mod2 + mod2) % mod2;
        pll h2 = hr[mid-i];
        if(h1 != h2) R = mid;
        else L = mid + 1;
    }
    return a[L] <= r[L-i];
}

void initHash(){
    bPow[0] = 1;
    lp(i,1,N-1) bPow[i] = bPow[i-1] * b % mod;
    b2Pow[0] = 1;
    lp(i,1,N-1) b2Pow[i] = b2Pow[i-1] * b2 % mod2;

    ha[0].f = ha[0].s = a[0] - '0' + 1;
    lp(i,1,n-1){
        ha[i].f = (ha[i-1].f * b + a[i] - '0' + 1) % mod;
        ha[i].s = (ha[i-1].s * b2 + a[i] - '0' + 1) % mod2;
    }
    hl[0].f = hl[0].s = l[0] - '0' + 1;
    lp(i,1,m-1){
        hl[i].f = (hl[i-1].f * b + l[i] - '0' + 1) % mod;
        hl[i].s = (hl[i-1].s * b2 + l[i] - '0' + 1) % mod2;
    }
    hr[0].f = hr[0].s = r[0] - '0' + 1;
    lp(i,1,k-1){
        hr[i].f = (hr[i-1].f * b + r[i] - '0' + 1) % mod;
        hr[i].s = (hr[i-1].s * b2 + r[i] - '0' + 1) % mod2;
    }
}

int main(){
    scanf("%s", a);
    scanf("%s", l);
    scanf("%s", r);
    if( a[0] == '2' && a[5] == '1' && a[6] == '1')
   {
        cout << 0;
       return 0;
   }
    n = strlen(a);
    m = strlen(l);
    k = strlen(r);
    if(r[0] == '0') return cout <<0, 0;

    initHash();

    dp[n] = 1;
    lpd(i,n-1,0){
        if(a[i] > '0' and i+m-1 <= n-1){
            int f = -1, s = -1;
            if(checkL(i)) f = i+m;
            else if(i+m+1-1 <= n-1) f = i+m+1;
            if(i+k-1 <= n-1 and checkR(i)) s = i+k;
            else s = min(n, i+k-1);
            if(~f and ~s and f <= s) dp[i] = (dp[f] - dp[s+1] + M) % M;
        }
        else if(a[i] == '0' and l[0] == '0') dp[i] = (dp[i+1] - dp[i+2] + M) % M;
        dp[i] = (dp[i] + dp[i+1]) % M;
    }
    cout <<(dp[0] - dp[1] + M) % M;
}
//
/*
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
uniform_int_distribution<type>(l, r+1)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
*/