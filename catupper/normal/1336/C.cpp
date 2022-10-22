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

string s, t;
int n, m;
Int dp[3300][3300];//front,back;
int main(){
    cin >> s >> t;
    n = s.size(), m = t.size();
    for(int width = 0;width < n;width++){
        for(int l = 0;l+width <= n;l++){
            int r = l + width;
            if(width == 0)dp[l][r] = 1;
            if(l-1 >= 0)
                if((l-1 < m && s[width] == t[l-1]) || l-1 >= m)
                    (dp[l-1][r] += dp[l][r]) %= MOD;
       
            if(r < n)
                if((r < m && s[width] == t[r]) || r >= m)(dp[l][r+1] += dp[l][r]) %= MOD;
            //    cout << l << " " << r << " " << dp[l][r] << endl;
        }
    }
    Int ans = 0;
    for(int i = m;i <= n;i++)(ans += dp[0][i]) %= MOD;
    cout << ans << endl;
    return 0;
}