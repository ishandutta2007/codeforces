#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+100;
const long long mod = 1e9+7;
typedef long long ll;
ll dp[maxn][70];
ll ans = 1;
ll k;
const int maxN = 3.4e7;
bool used[maxN];
int prime[maxN],tot;
ll power(ll x,ll y){
    ll res = 1;
    x %= mod;
    while (y){
        if (y & 1){
            res = res * x % mod;
        }
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}
ll fm[100];
void init(){
    for (int i=1;i<100;i++){
        fm[i] = power(i,mod-2);
    }
    for (ll i=2;i < maxN;i++){
        if (!used[i]){
            prime[tot++] = i;
        }
        for (ll j=0; j < tot;j ++){
            if(i * prime[j] > maxN)break;
            used[i * prime[j]] = 1;
            if (i % prime[j] == 0)break;
        }
    }
}

void work(ll fac,ll N){
    int cnt = 0;
    while (N % fac == 0){
        cnt ++;
        N /= fac;
    }
    memset(dp,0,sizeof dp);
    dp[0][cnt] = 1;
    for (int i=0;i<=k-1;i++){
        for (int j=0;j<=cnt;j++){
            // i step ^j
            for (int k=0;k<=j;k++){
                (dp[i+1][k] += dp[i][j] * fm[j+1] % mod) %= mod;
            }
        }
    }
    ll temp_ans = 0;
    for (int j=0;j<=cnt;j++){
        (temp_ans += power(fac,j) * dp[k][j] % mod) %= mod;
    }
    ans = ans * temp_ans % mod;
}
int main(){
    init();
    ll n;
    cin>>n>>k;
    bool flag = false;
    for (int i = 0;i < tot;i++){
        if (n % prime[i] == 0){
            work(prime[i],n);
            while (n % prime[i] == 0){
                n /= prime[i];
            }
            flag = true;
        }
    }
    if (n != 1){
        work(n,n);
    }
    cout<<ans<<endl;
    return 0;
}

/*
 dp[i][j] = i  jP
 dp[i][j] =
 */