#include <bits/stdc++.h>
using namespace std;

string s;
long long maxim,z;
long long n,dp[100005],dp2[100005];
long long a[100005];
vector<int> v[100005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    for (int i=0;i<26;++i)
        cin>>a[i];
    s="{"+s;
    a[26]=10000000;
    dp[0]=1;
    long long ans2=1;
    for (int i=1;i<s.size();++i){
        maxim=a[s[i]-'a'];
        dp2[i]=i;
        for (int j=1;j<=maxim;++j){
              if (i-j<0) break;
              maxim=min(maxim,a[s[i-j+1]-'a']);
              if (j>maxim) break;
              ans2=max(ans2,(long long)j);
                dp[i]=(dp[i]+dp[i-j])%1000000007;
                dp2[i]=min(dp2[i],dp2[i-j]+1);
        }
    }

    cout<<dp[s.size()-1]<<'\n'<<ans2<<'\n'<<dp2[s.size()-1];

}