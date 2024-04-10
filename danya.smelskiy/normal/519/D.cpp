#include <bits/stdc++.h>
using namespace std;


string s;
long long a[50];
long long ans;
map<pair<long long,long long>, long long > kol;
long long dp[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i=1;i<=26;++i){
        cin>>a[i];
    }
    cin>>s;
    for (int i=1;i<=s.size();++i){
        int x=s[i-1]-'a'+1;
        ans+=kol[make_pair(dp[i-1]-a[x],x)];
        ++kol[make_pair(dp[i-1],x)];
        dp[i]=dp[i-1]+a[x];
    }
    cout<<ans;
}