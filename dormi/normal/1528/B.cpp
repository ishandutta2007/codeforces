#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=998244353;
const int MN=3e6+1;
ll dp[MN];
ll factcnt[MN];
int lastfact[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    n*=2;
    dp[0]=1;
    factcnt[1]=1;
    for(ll i=2;i<=n;i++){
        if(lastfact[i]==0){
            factcnt[i]=2;
            for(ll j=i*i;j<=n;j+=i)lastfact[j]=i;
        }
        else{
            ll te=lastfact[i];
            ll cnt=0;
            while(i%te==0)te=te*lastfact[i],cnt++;
            te/=lastfact[i];
            if(te==i)factcnt[i]=cnt+1;
            else factcnt[i]=factcnt[te]*factcnt[i/te];
        }
        if(i%2==0) {
            dp[i] = (dp[i] + dp[i - 2]) % mod;
            dp[i] = (dp[i] + (factcnt[i/2] - 1)) % mod;
            dp[i] = (dp[i] + dp[i - 2]) % mod;
        }
    }
    printf("%lli\n",(dp[n]-dp[n-2]+mod)%mod);
    return 0;
}