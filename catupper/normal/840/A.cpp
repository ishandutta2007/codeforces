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
vector<Int> a, b;
map<Int,vector<Int>> nums;
int main(){
    cin >> n;
    a.resize(n), b.resize(n);
    for(int i = 0;i < n;i++)cin >> a[i];
    for(int i = 0;i < n;i++)cin >> b[i];
    auto b2 = b;
    auto a2 = a;
    sort(a2.rbegin(), a2.rend());
    sort(b2.begin(), b2.end());
    for(int i = 0;i < n;i++){
        nums[b2[i]].push_back(a2[i]);
    }
    for(int i = 0;i < n;i++){
        printf("%lld ", nums[b[i]].back());
        nums[b[i]].pop_back();        
    }puts("");
    return 0;
}