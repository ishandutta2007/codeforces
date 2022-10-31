
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef LL ll;
const int inf = 0x3f3f3f3f;
ll n;
int main() {
    scanf("%I64d",&n);
    ll sum = 1LL*(1 + n) * n / 2;
    for(ll i=2;i*i<=sum;i++) {
        if (sum % i == 0) {
            puts("Yes");
            printf("1 %I64d\n",i);
            vector<ll> ans;
            ans.push_back(n - 1);
            for (int j = 1; j <= n; j++) {
                if (j != i){
                    ans.push_back(j);
                }
            }
            for (ll x: ans){
                printf("%I64d ",x);
            }
            puts("");
            exit(0);
        }
    }
    puts("No");
    return 0;
}