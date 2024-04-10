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


Int fact[1100000];
Int revfact[1100000];
Int rev[1100000];

void init(){
    Int m = MOD;
    fact[0] = 1;
    revfact[0] = 1;
    rev[0] = 0;
    rev[1] = 1;
    for(int i = 1;i < 1100000;i++){
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
    Int res = mod_pow(x, a / 2, m);
    res = res * res % m;
    if(a % 2)res *= x;
    return res % m;
}

Int inv(Int x, Int m = MOD){
    return mod_pow(x, m-2, m);
}


Int stirling(Int n, Int k){
    Int ans = 0;
    for(int i = 0;i <= k;i++){
        if(i % 2 == 0)
            ans +=nCk(k,i)*mod_pow(k-i, n);
        if(i % 2 == 1)
            ans -=nCk(k,i)*mod_pow(k-i, n);
        ans %= MOD;
    }
    return ans;
}

int main(){
    init();
    Int n, k;
    cin >> n >> k;
    if(k == 0){
        Int ans = 1;
        for(int i = 1;i <= n;i++){
            ans *= i;
            ans %= MOD;
        }
        cout << ans << endl;
    }
    else{
        Int ans = nCk(n, k) * stirling(n, n-k) % MOD;
        ans *= 2;
        ans %= MOD;
        if(ans < 0)ans += MOD;
        cout << ans << endl;
    }
    return 0;
}