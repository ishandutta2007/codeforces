#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<complex>
using namespace std;
#define MOD2 1000000007
#define MOD 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

Int dp[2200000];

Int fact[4400000];
Int revfact[4400000];
Int rev[4400000];

void init(){
    Int m = MOD;
    fact[0] = 1;
    revfact[0] = 1;
    rev[0] = 0;
    rev[1] = 1;
    for(int i = 1;i < 4400000;i++){
        fact[i] = fact[i-1] * i % m;
        if(i>1)rev[i] = MOD / i * (MOD-rev[MOD % i]) % MOD;
        revfact[i] = revfact[i-1] * rev[i] % MOD;
    }
}

Int nCk(Int n, Int k){
    if(n < k)return 0;
    return fact[n] * revfact[n-k] % MOD * revfact[k] % MOD;
}

Int mod_pow(Int x, Int a, Int m = MOD){
    if(a == 0)return 1;
    if(a % 2 == 1)return x * mod_pow(x, a - 1, m) % m;
    Int res = mod_pow(x, a / 2, m);
    return res * res % m;
}

Int inv(Int x, Int m = MOD){    
    return mod_pow(x, m-2, m);
}


int main(){
    init();
    Int n, m;
    cin >> n >> m;
    Int ans = 0, sum = 0;
    for(int r = 1;r <= n;r++){
        ans = sum * rev[r] % MOD * m % MOD;
        ans += (1 + (n-r) % MOD * rev[m+1] % MOD) * nCk(m+r, m) % MOD * rev[r] % MOD;
        sum += ans;
        sum %= MOD;
    }
    ans = ans * n % MOD * inv(nCk(m + n - 1, m)) % MOD;
    ans = (ans + n) % MOD;
    cout << ans << endl;
    return 0;
}