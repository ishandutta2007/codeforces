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
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int fact[1100000];
Int revfact[1100000];
Int rev[1100000];

void init(Int m = MOD){
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



int main(){
    Int n, m;
    Int ans = 0;
    cin >> n >> m;
    init(m);
    for(int i = 1;i <= n;i++){
        ans += (n - i + 1) * (n - i + 1) % m * fact[i] % m * fact[n-i] % m;
        ans %=m;
    }
    cout << ans << endl;
    return 0;
}