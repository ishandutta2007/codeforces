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

map<int, int> cnt;
Int n;
vector<Int> nums;
Int dp[330][330];

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
    if(k < 0)return 0;
    if(n < k)return 0;
    return fact[n] * revfact[n-k] % MOD * revfact[k] % MOD;
}



Int calc(Int sum, Int nxt, Int from, Int to){
    Int ans = 0;
    for(Int split_into = 1;split_into <= nxt;split_into++){
        Int nxt_concat_cnt = nxt - split_into;
        Int from_concat_cnt = to - nxt_concat_cnt;
        if(from_concat_cnt < 0)continue;
        Int into_froms = from - from_concat_cnt;
        Int other_place = sum + 1 - from;
        ans += nCk(nxt-1, split_into - 1) * nCk(from, into_froms) %MOD * nCk(other_place, split_into - into_froms) % MOD;
        ans %= MOD;
    }
    return ans;
} 

int main(){
    init();
    cin >> n;
    for(int i = 0;i < n;i++){
        Int a;
        cin >> a;
        for(Int j = 2;j * j <= a;j++){
            while(a % (j*j) == 0){
                a /= j * j;
            }
        }
        cnt[a]++;
    }
    for(auto it:cnt){
        nums.push_back(it.second);
    }
    dp[0][0] = 1;
    Int sum = 0;
    Int perm = 1;
    for(int i = 0;i < nums.size();i++){
        for(int j = 0;j <= 300;j++){
            for(int k = 0;k <= 300;k++){
                dp[i+1][k] += dp[i][j] * calc(sum, nums[i], j, k) % MOD;
                dp[i+1][k] %= MOD;
            }
        }
        perm *= fact[nums[i]];perm %= MOD;
        sum += nums[i];
    }
    cout << dp[nums.size()][0] * perm % MOD << endl;
    return 0;
}