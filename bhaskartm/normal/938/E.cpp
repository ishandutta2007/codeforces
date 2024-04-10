#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 1e6+10;
const int mod = 1e9+7;
 
ll a[MAX_N],n,fact[MAX_N],rfact[MAX_N];
ll num(int t){
    return fact[n-t-1]*rfact[n-t+1]%mod;
}
main(){
    scanf("%lld", &n);
    for(ll i=1;i<=n;i++)
        scanf("%lld", &a[i]);
    fact[0]=rfact[n+1]=1;
    for(int i=1;i<=n+1;i++)
        fact[i]=(fact[i-1]*i)%mod;
    for(int i=n;i>=1;i--)
        rfact[i]=(rfact[i+1]*i)%mod;
    sort(a+1,a+n+1);
    ll cnt=0,curr=0,ans=0;
    for(ll i=1;i<=n&&a[i]!=a[n];i++){
        if(a[i]==a[i-1])
            cnt++;
        else
            curr+=cnt,cnt=1;
        ans=(ans+num(curr)*a[i]%mod)%mod;
    }
    printf("%d",ans);
}