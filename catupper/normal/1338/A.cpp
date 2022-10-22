#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int a[110000];
void solve(){
    Int n;
    Int need = 0;
    scanf("%lld", &n);
    for(Int i = 0;i < n;i++){
        scanf("%lld", &a[i]);
        if(i){
            need = max(a[i-1] - a[i], need);
            a[i] = max(a[i-1], a[i]);
        }
    }
    Int ans = 0;
    while(need){
        ans++;
        if(need & (1LL << (ans-1)))need -= 1LL << (ans-1);
    }
    printf("%lld\n", ans);
}

int main(){
    Int n;
    scanf("%lld", &n);
    while(n--)solve();
    return 0;
}