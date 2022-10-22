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

Int d, n, m, a;
vector<Int> ok, ng;

int main(){
    cin >> n >> d >> m;
    for(Int i = 0;i < n;i++){
        cin >> a;
        if(a > m)ng.push_back(a);
        else ok.push_back(a);
    }
    sort(ng.rbegin(), ng.rend());
    sort(ok.rbegin(), ok.rend());
    vector<Int> ok_sum = {0}, ng_sum = {0};
    for(auto x:ok)ok_sum.push_back(ok_sum.back() + x);
    for(auto x:ng)ng_sum.push_back(ng_sum.back() + x);
    Int ans = ok_sum.back();
    for(Int i = 1;i <= ng.size();i++){
        Int rest = n - ((i-1) * (d+1) + 1);
        rest = min(rest, Int(ok_sum.size()) - 1);
        if(rest < 0)break;
        ans = max(ans, ng_sum[i] + ok_sum[rest]);
    }
    
    cout << ans << endl;
    return 0;
}