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

set<Int> s;

Int b(Int a){
    if(a == 1)return 2;
    Int up = 0;
    while((1LL << (up+2)) <= a)up+=2;
    Int start = 1LL << up;
    Int prev = start / 4;
    Int dist = a - start;
    Int res = b(dist % prev + prev)-prev*2;
    if(dist / prev == 0)return res + start * 2;
    if(dist / prev == 1)return res + start * 2 + prev*2;
    if(dist / prev == 2)return res + start * 2 + prev*3;
    if(dist / prev == 3)return res + start * 2 + prev;
    return 0;
}

Int c(Int a){
    return a^b(a);
}

Int  solve(){
    Int n;
    scanf("%lld", &n);n--;
    Int p = n / 3;
    Int x = 0;
    Int cnt = 1;
    Int a = 1;
    while(cnt <= p-x){
        x += cnt;
        cnt *= 4;
        a *= 4;
    }
    a += p-x;
    if(n % 3 == 0)return a;
    if(n % 3 == 1)return b(a);
    if(n % 3 == 2)return c(a);
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)printf("%lld\n", solve());
    return 0;
}