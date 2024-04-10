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
    Int x, y, a, b;
    cin >> x >> y;
    cin >> a >> b;
    Int only_a = a * (x + y);
    Int a_and_b = a * abs(x-y) + b * min(x, y);
    cout << min(only_a, a_and_b) << endl;
}

int main(){
    Int t;
    cin >> t;
    while(t--)solve();
    return 0;
}