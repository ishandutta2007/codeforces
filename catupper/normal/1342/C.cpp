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
    Int a, b, q;
    cin >> a >> b >> q;
    vector<Int> cnt(a*b,0);
    for(int i = 0;i < a * b;i++){
        if((i % a) % b != (i % b) % a)cnt[i] = 1;
        if(i != 0)cnt[i] += cnt[i-1];
    }
    
    for(int i = 0;i < q;i++){
        Int l, r;
        cin >> l >> r;
        Int l_block = l / (a*b);
        Int r_block = r / (a*b);
        Int ans = (r_block - l_block + 1) * cnt[a*b-1];
        ans -= cnt[a*b-1] - cnt[r % (a*b)];
        if(l % (a*b) > 0)ans -=  cnt[l % (a*b) - 1];
//        cout << l_block << " " << r_block << " " << cnt[a*b-1] << endl;
        printf("%lld ", ans);
    }
    puts("");
}

int main(){
    Int t;
    cin >> t;
    while(t--)solve();
    return 0;
}