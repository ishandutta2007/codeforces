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

bool is_prime[2200000];
Int n, x, y, a[2200000];
Int cnt[2200000], sum[2200000];
Int c = 0;


Int calc(Int mod){
    Int res = 0;
    Int cc = min(c, mod);
    for(Int i = mod;i < 2200000;i += mod){
        Int l = i - mod;
        Int r = i;
        int m = r- cc;
        Int diff = ((cnt[r] - cnt[m]) * i - (sum[r] - sum[m]));
        if(diff > 2200000)return LINF;
        if(res > 1e15)return LINF;
        res += y * diff;
        res += (cnt[m] - cnt[l]) * x;
    }
    return res;
}

int main(){
    Int ans = LINF;
    cin >> n >> x >> y;
    while(c < 2200000 && c * y < x)c++;
    for(Int i = 0;i < n;i++){
        cin >> a[i];
        sum[a[i]] += a[i];
        cnt[a[i]]++;
    }
    for(int i = 1;i < 2200000;i++){
        sum[i] += sum[i-1];
        cnt[i] += cnt[i-1];
    }
    
    for(Int i = 2;i < 2200000;i++){
        ans = min(ans, calc(i));
    }
    cout << ans << endl;
    return 0;
}