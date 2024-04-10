#include <bits/stdc++.h>
using namespace std;
long long n,l,r,dp[100001],sz;

long long ll,ans;
void dfs(long long n,long long d){
    if (ll>r) return;
    if (n<=1) {
        ++ll;
        if (n==1 && ll>=l && ll<=r) ++ans;
        return;
    }
    if (ll+dp[d+1]<l) ll+=dp[d+1];
    else dfs(n/2,d+1);
    ++ll;
    if (n%2==1) {
        if (ll>=l && ll<=r) ++ans;
    }
    dfs(n/2,d+1);
}
int main(){
    cin>>n>>l>>r;
    long long m=n;
    while (m>1){
        ++sz;
        m/=2;
    }
    ++sz;
    dp[sz]=1;
    for (int i=sz-1;i>0;--i)
        dp[i]=(dp[i+1])*2+1;
    dfs(n,1);
    cout<<ans;
}