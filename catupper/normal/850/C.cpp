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
#include<unordered_map>
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
unordered_map<Int, Int> memo;
unordered_map<Int, Int> cnt;

Int grundy(Int x){
    if(memo.count(x))return memo[x];
    Int used = 0;
    for(Int i = 1;i <= 33;i++){
        Int tmp = x & ((1LL << (i-1))-1);
        tmp |= x >> i;
        if(tmp == x)continue;

        used |= 1LL << grundy(tmp);
    }
    for(Int i = 0;i <= 33;i++){
        if((used >> i) % 2 == 0){
            memo[x] = i;
            break;
        }
    }
    return memo[x];
}



int main(){
    memo[0] = 0;
    Int n;
    cin >> n;
    for(Int i = 0;i < n;i++){
        Int a;
        cin >> a;
        for(Int d = 2;d * d <= a;d++){
            if(a % d)continue;
            Int k = 0;
            while(a % d == 0){
                k++;
                a /= d;
            }
            cnt[d] |= 1LL << (k-1);
        }
        if(a != 1){
            cnt[a] |= 1;
        }
    }
    Int x = 0;
    for(auto p:cnt){

        x ^= grundy(p.second);
    }
    if(x == 0)cout << "Arpa"  << endl;
    else cout << "Mojtaba" << endl;
    return 0;
}