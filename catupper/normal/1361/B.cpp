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
#include<unordered_map>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

Int mod_pow(Int x, Int a, Int m){
    if(a == 0)return 1;
    Int res = mod_pow(x, a / 2, m);
    res = res * res % m;
    if(a % 2)res *= x;
    return res % m;
}

Int inv(Int x, Int m){
    return mod_pow(x, m-2, m);
}


void solve(){
    Int n, p, k;
    scanf("%lld%lld", &n, &p);
    vector<Int> ks;
    for(int i = 0;i < n;i++){
        scanf("%lld", &k);
        ks.push_back(k);
    }
    sort(ks.rbegin(), ks.rend());
    Int now = 1100000;
    Int cnt = 0;
    bool big = false;
    for(auto k:ks){
        if(now != k){
            Int diff = now - k;
            while(cnt != 0 && p != 1 && !big && diff--){
                cnt = cnt * p;
                if(cnt >= MOD){
                    cnt %= MOD;
                    big = true;
                }
            }
            if(diff > 0)cnt = cnt * mod_pow(p, diff, MOD) % MOD;
            now = k;
        }
        if(!big && cnt == 0)cnt++;
        else cnt--;
        if(cnt < 0)cnt += MOD;
        if(cnt >= MOD){
            cnt %= MOD;
            big = true;
        }
    }
    if(now != 0){
        Int diff = now - 0;
        cnt = cnt * mod_pow(p, diff, MOD) % MOD;
        now = 0;
    }
    if(cnt < 0)cnt += MOD;
    
    printf("%lld\n", cnt);
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}