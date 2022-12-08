#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll mpow(ll x, ll y){
    if(!y) return 1;
    if(y&1) return mpow(x, y-1) * x % MOD;
    ll tmp = mpow(x, y>>1);
    return tmp*tmp%MOD;
}

int n, k;
ll fact[10002];
ll factInv[10002];
int DP[202][402][202];
ll ans[202];
ll comb[402][402];
int constant[402][202][202];

int main(){
    fact[0] = 1;
    for(ll i=1; i<=10000; i++) fact[i] = (fact[i-1] * i) % MOD;
    factInv[10000] = mpow(fact[10000], MOD-2);
    for(ll i=9999; i>=0; i--) factInv[i] = (factInv[i+1] * (i+1)) % MOD;

    scanf("%d %d", &n, &k);

    for(ll i=0; i<=400; i++){
        for(ll j=0; j<=400; j++){
            if(i+j>n) continue;
            comb[i][j] = factInv[j];
            for(int x=n-i; x>n-i-j; x--) comb[i][j] = (comb[i][j] * x) % MOD;
        }
    }

    for(int l=1; l<=200; l++){
        for(int j=1; j<=400; j++){
            ll prob = 1;
            for(int cnt=1; j-(l+1)*cnt >= 0; cnt++){
                prob *= comb[j-(l+1)*cnt][l+1] * fact[l] % MOD;
                prob %= MOD;
                constant[j][l][cnt] = prob * factInv[cnt] % MOD;
            }
        }
    }

    for(int i=0; i<=200; i++) DP[0][0][i] = 1;
    ans[0] = 1;
    for(int i=1; i<=k; i++){ /// swap 
        for(int j=1; j<=n && j<=2*k; j++){ ///   
            for(int l=1; l<=i && l<=k; l++){ ///  swap  
                for(int i2=i-l, j2=j-(l+1), cnt = 1; i2>=0 && j2>=0; i2-=l, j2-=l+1, cnt++){
                    DP[i][j][l] += ll(DP[i2][j2][l-1]) * constant[j][l][cnt] % MOD;
                    DP[i][j][l] %= MOD;
                }
//                if(i>=j && DP[i][j][l]) printf("%d %d %d: %lld\n", i, j, l, DP[i][j][l]);
            }
            for(int l=1; l<=k; l++){
                ans[i] += DP[i][j][l];
                ans[i] %= MOD;
                DP[i][j][l] += DP[i][j][l-1];
                DP[i][j][l] %= MOD;
            }
        }
    }

    for(int i=1; i<=k; i++){
        if(i>=2) ans[i] = (ans[i] + ans[i-2]) % MOD;
        printf("%lld ", ans[i]);
    }
}