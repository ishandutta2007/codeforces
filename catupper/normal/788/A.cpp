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
Int a[110000];
Int dp[110000];
Int d[110000];
Int ans;
int main(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> a[i];
    for(int i = 0;i < n-1;i++)d[i] = abs(a[i+1] - a[i]);
    dp[n-1]  = 0;
    for(int i = n-2;i >= 0;i--){
        if(i == n-2){
            dp[i] = max(dp[i], d[i]);            
        }
        else{
            dp[i] = max(d[i], dp[i+2] - d[i+1] + d[i]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}