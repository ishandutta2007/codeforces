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
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

vector<Int> primes(Int n){
    vector<Int> res;
    for(Int i = 2;i * i <= n;i++){
        if(n % i == 0){
            res.push_back(i);
            while(n % i == 0)n /= i;
        }
    }
    if(n != 1)res.push_back(n);
    return res;
}

Int a[1100000];
Int n;
Int sum = 0;

Int solve(Int d){
    Int res = 0;
    for(Int i = 0;i < n;i++){
        Int move = a[i] % d;
        res += min(d-move, move);
    }
    return res;
}

int main(){
    cin >> n;
    for(Int i = 0;i < n;i++){
        scanf("%lld", a+i);
        if(i)a[i] += a[i-1];
    }
    Int ans = LINF;
    auto p = primes(a[n-1]);
    for(auto d: p){
        ans = min(ans, solve(d));
    }
    if(a[n-1] == 1)ans = -1;
    printf("%lld\n", ans);
    return 0;
}