#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
map<long long,long long> dp;
map<long long,long long> kol;
long long a[200005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=n;i>0;--i){
        ans+=dp[a[i]];
        if (a[i]%m==0)
        dp[a[i]/m]+=kol[a[i]*m];
        ++kol[a[i]];
    }
    cout<<ans;
}