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
#define MOD 1000000007
#define MOD2 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

Int n;
string str;
Int f[1 << 20];
Int popcount[1 << 20];
void wht(Int *f, Int n){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < (1<<n);j += 2<<i){
            for(int k = 0;k < 1<<i;k++){
                Int l = f[j + k];
                Int r = f[j + k + (1<<i)];
                f[j+k] = (l + r) % MOD;
                f[j+k+(1<<i)] = (l - r + MOD) % MOD;
            }
        }
    }
}

void invwht(Int *f, Int n){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < (1<<n);j += 2<<i){
            for(int k = 0;k < 1<<i;k++){
                Int l = f[j + k];
                Int r = f[j + k + (1<<i)];
                f[j+k] = (l + r) % MOD;
                if(f[j + k] % 2)f[j+k] += MOD;
                f[j+k] /= 2;
                f[j+k+(1<<i)] = (l - r + MOD) % MOD;
                if(f[j + k + (1<<i)] % 2)f[j+k+(1<<i)] += MOD;
                f[j+k+(1<<i)] /= 2;
            }
        }
    }
}
Int pow2[22];

int main(){
    cin >> n;
    cin >> str;
    pow2[0] = 1;
    for(int i = 1;i <= n;i++){
        pow2[i] = pow2[i-1] * 2 % MOD;
    }
    for(int i = 0;i < (1 << n);i++){
        f[i] = str[i] == '1';
    }
    wht(f, n);
    for(int i = 0;i < (1<<n);i++){
        f[i] = f[i] * f[i] % MOD;
    }
    invwht(f, n);
    Int ans = 0;
    for(int i = 0;i < (1 << n);i++){
        if(i)popcount[i] = popcount[i/2] + i % 2;
        ans += f[i] * pow2[n-popcount[i]];
        ans %= MOD;
    }
    cout << ans * 3 % MOD << endl;    
    
    return 0;
}