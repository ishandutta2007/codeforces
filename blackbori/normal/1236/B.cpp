#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll mod = 1e9 + 7;
 
ll pow(ll a, ll b)
{
    ll ret = 1;
    
    for(; b; b>>=1){
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
    }
    
    return ret;
}
 
int main()
{
    ll n, m;
    
    scanf("%lld%lld", &n, &m);
    printf("%lld\n", pow(pow(2ll, m) - 1, n));
    
    return 0;
}