#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

ll a, b;

int cal(ll a){
    ll x = a;
    int t = 0;
    while(x) x /= 2, t++;
    t--;
    int ans = t * (t - 1) / 2;
    while(a & (1LL << t)) t--, ans++;
    ans--;
    return ans;
}

int main(){
    scanf("%I64d%I64d", &a, &b);
    printf("%d\n", cal(b + 1) - cal(a));
  return 0;
}