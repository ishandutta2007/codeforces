#include <bits/stdc++.h>
using namespace std;
int t;
long long f[1000];
long long n;
int sz;
long long dp[1000][2];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    for (int z=1;z<=t;++z) {
        f[1]=1;
        f[2]=2;
        sz=2;
        cin>>n;
        vector<int> v;
        for (int i=3;f[i-1]+f[i-2]<=n;++i) f[++sz]=f[i-1]+f[i-2];
        for (int i=sz;i>0 && n;--i)
        if (f[i]<=n) {
            n-=f[i];
            v.push_back(i);
        }
        v.push_back(0);
        reverse(v.begin(),v.end());
        dp[0][0]=1;
        dp[0][1]=0;
        for (int i=1;i<v.size();++i) {
            dp[i][0]=dp[i-1][1]+dp[i-1][0];
            dp[i][1]=dp[i-1][0]*((v[i]-v[i-1]-1ll)/2ll)+dp[i-1][1]*((v[i]-v[i-1])/2ll);
        }
        cout<<dp[(int)v.size()-1][0]+dp[(int)v.size()-1][1]<<'\n';
    }
}