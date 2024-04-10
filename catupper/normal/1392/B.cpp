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

int n;
Int k;
int a[220000];
void solve(){
    scanf("%d%lld", &n, &k);
    for(int i = 0;i < n;i++)scanf("%d",a+i);
    k %= 2;k += 2;
    while(k--){
        int mx = *max_element(a, a + n);
        for(int i = 0;i < n;i++)a[i] = mx - a[i];
    }
    for(int i = 0;i < n;i++)printf("%d ", a[i]);
    puts("");
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)solve();
    return 0;
}