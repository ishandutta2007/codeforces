#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

map <ll, ll> L, R;
ll n, m, ans;

int main()
{
    ll i, x;
    
    scanf("%lld%lld", &n, &m);
    
    if(n == 1){
        printf("0\n");
        return 0;
    }
    
    for(i=1; i<=n; i++){
        L[max(1ll, i - 1)] ++;
        R[min(n, i + 1)] ++;
    }
    
    for(i=0; i<m; i++){
        scanf("%lld", &x);
        R[x - i - 1] += R[x - i];
        R[x - i] = 0;
        L[x + i + 1] += L[x + i];
        L[x + i] = 0;
    }
    
    for(pll p: R) ans += min(n, p.first + m) * p.second;
    for(pll p: L) ans -= max(0ll, p.first - m - 1) * p.second;
    
    printf("%lld\n", ans);
    
    return 0;
}