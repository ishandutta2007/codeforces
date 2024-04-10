#include <bits/stdc++.h>
using namespace std;

string s;
int x;
long long dp[(1<<18)+5][100];
long long ans;
int kol[1000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>x;
    dp[0][0]=1;
    int n=s.size();
    for (int i=0;i<(1<<n)-1;++i){
        for (int j=0;j<x;++j) if (dp[i][j]) {
            for (int k=0;k<n;++k)
            if (!(i&(1<<k))) {
                if (i==0 && s[k]=='0') continue;
                dp[(i|(1<<k))][(j*10+(s[k]-'0'))%x]+=dp[i][j];
            }
        }
    }
    ans=dp[(1<<n)-1][0];
    for (int i=0;i<s.size();++i) {
        ++kol[s[i]-'0'];
        ans/=kol[s[i]-'0'];
    }
    cout<<ans;
}