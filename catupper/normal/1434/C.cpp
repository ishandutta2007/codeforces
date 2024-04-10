#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using Int = long long;
using Real = long double;
using CP = complex<Real>;
using P = pair<Int, Int>;

const Int MOD = 1000000007;
const Int MOD2 = 998244353;
const Int LINF = (1LL << 60);
const int INF = (1000000007);
const Real EPS = 1e-10;
const long double PI = 3.141592653589793238462643383279502884L;

Int calc(Int t, Int a, Int b, Int c, Int d){
    if(t == 0)return 0;
    Int ans = t * a;
    ans -= b * c * t;
    Int r = c;
    Int l = max(c % d, c - (t-1) * d);
    ans += (r + l) * ((r - l) / d + 1) / 2 * b;
    return ans;  
}

void solve(){
    Int a, b, c, d;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    if(a - b * c > 0){
        puts("-1");
        return;
    }
    Int bottom = 0,top = 1e12+10;
    while(top - bottom > 1){
        Int mid = (top + bottom) / 2;
        if(calc(mid,a,b,c,d) <= calc(mid+1,a,b,c,d))bottom = mid;
        else top = mid;
    }
    printf("%lld\n", calc(top, a, b, c, d));
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)solve();    
    return 0;
}