#include <bits/stdc++.h>
using namespace std;

long long n,m;
int x;
long long kol[3000005];
long long dp[3000005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x;
        ++kol[x];
    }
    for (int i=1;i<=3e6;++i) {
        for (int j=1;j*i<=3e6;++j) dp[j*i]+=(i==j? (kol[i]*(kol[i]-1ll)) : kol[i]*kol[j]);
    }
    for (int i=1;i<=3e6;++i)
        dp[i]+=dp[i-1];
    cin>>m;
    for (int i=1;i<=m;++i) {
        cin>>x;
        cout<<(n)*(n-1ll)-dp[x-1]<<'\n';
    }
}