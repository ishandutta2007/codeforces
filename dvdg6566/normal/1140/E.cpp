#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e18;
ll MOD = 998244353;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 200100

vi A,B;
ll ans = 1;
ll N,K,a;
ll dp[MAXN][2];
vpi V;

ll query(int n, int a){
    // n is the number of terms in between
    // a is 1 if the 2 sides are the same, and a is 0 if they are different
    if (n == 0){
        if (a == 1)return 0;
        return 1;
    }
    if (dp[n][a] != -1)return dp[n][a];
    if (a == 1){
        return dp[n][a] = ((K-1) * query(n-1,0))%MOD;
    }
    else {
        // Both are different
        return dp[n][a] = (query(n-1,1) + (K-2) * query(n-1,0))%MOD;
    }
}

int main(){
    // freopen("in.txt","r",stdin);
    cin >> N >> K;
    for (int i=0;i<N;++i){
        cin >> a;
        if (i%2==0)A.pb(a);
        else B.pb(a);
    }
    memset(dp,-1,sizeof(dp));
    // for (auto i : A)cout<<i<<' ';
    for (int i=0;i<SZ(A);++i){
        if (A[i] != -1)V.pb(mp(A[i],i+1));
    }
    // for (auto i : V)cout<<i.f<<' '<<i.s<<'\n';
    if (SZ(V) == 0){
        if (SZ(A) == 1){
            ans = (ans*K)%MOD;
        }
        else{
            int t = SZ(A);
            ans *= (((K * query(t-2, 1))%MOD + ((((K*(K-1)) % MOD) * query(t-2,0))%MOD) %MOD))%MOD;
            ans %= MOD;
        }
    }
    else{
        ll l = V[0].s-1;
        if (l){
            // cout<<"X\n";
            ans = ans * (((K-1) * query(l-1,0))%MOD + query(l-1,1))%MOD;
            ans %= MOD;
        }
        l = SZ(A) - V.back().s;
        if (l){
            // cout<<"Y\n";
            ans = ans * (((K-1) * query(l-1,0))%MOD + query(l-1,1))%MOD;
            ans %= MOD;
        }
        for (int i=0;i<SZ(V)-1;++i){
            int same = (V[i].f == V[i+1].f);
            int l = V[i+1].s - V[i].s - 1;
            // cout<<same<<' '<<l<<'\n';
            ans = ans*query(l,same);
            ans %= MOD;
        }
    }
    // cout<<ans<<'\n';
    V.clear();
    swap(A,B);
    // for (auto i : A)cout<<i<<' ';
    for (int i=0;i<SZ(A);++i){
        if (A[i] != -1)V.pb(mp(A[i],i+1));
    }
    if (SZ(V) == 0){
        if (SZ(A) == 1){
            ans = (ans*K)%MOD;
        }
        else{
            int t = SZ(A);
            ans *= (((K * query(t-2, 1))%MOD + ((((K*(K-1)) % MOD) * query(t-2,0))%MOD) %MOD))%MOD;
            ans %= MOD;
        }
    }
    else{
        ll l = V[0].s-1;
        if (l){
            // cout<<"X\n";
            ans = ans * (((K-1) * query(l-1,0))%MOD + query(l-1,1))%MOD;
            ans %= MOD;
        }
        l = SZ(A) - V.back().s;
        if (l){
            // cout<<"Y\n";
            ans = ans * (((K-1) * query(l-1,0))%MOD + query(l-1,1))%MOD;
            ans %= MOD;
        }
        for (int i=0;i<SZ(V)-1;++i){
            int same = (V[i].f == V[i+1].f);
            int l = V[i+1].s - V[i].s - 1;
            // cout<<same<<' '<<l<<'\n';
            ans = ans*query(l,same);
            ans %= MOD;
        }
    }
    cout<<ans;
}