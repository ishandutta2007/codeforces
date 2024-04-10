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

void solve(){
    int n;
    scanf("%d", &n);
    int last = 0;
    Int ans = 0;
    for(int i = 0;i < n;i++){
        int a;
        scanf("%d", &a);
        if(last > a)ans += last - a;
        last = a;
    }
    printf("%lld\n", ans);
}


int main(){int n;
    scanf("%d", &n);
    while(n--)solve();
    return 0;
}