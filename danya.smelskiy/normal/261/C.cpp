#include <bits/stdc++.h>
using namespace std;

long long n,t;
long long dp[65][65];

long long solve(long long x,int y){
    string s="";
    while (x) {
        s+=char(x%2+'0');
        x>>=1;
    }
    reverse(s.begin(),s.end());
    int kol=0;
    long long ans=0;
    for (int i=0;kol<=y && i<s.size();++i) {
        if (s[i]=='0') continue;
        ans+=dp[(int)s.size()-i-1][y-kol];
        //cout<<s.size()-i-1<<" "<<y-kol<<'\n';
        ++kol;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>t;
    long long tt=t;
    dp[0][0]=1;
    for (int i=1;i<=60;++i)
    for (int j=0;j<=60;++j) {
        dp[i][j]=dp[i-1][j] + (j ? dp[i-1][j-1] : 0);
    }
    int kol=0;
    while (!(t&1)) {
        ++kol;
        t>>=1;
    }
    if (t>1) {
        cout<<0;
        return 0;
    }
    kol=0;
    t=tt;
    --tt;
    while (tt) {
        kol+=tt%2;
        tt/=2;
    }

    long long res=solve(n+2,kol+1);
    if (t==1) --res;

    cout<<res;
}