#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int n;
string s;
long long dp[2][5005];
int last[100];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    int x=0,y=1;
    for (int i=1;i<=n;++i) {
        swap(x,y);
        for (int j=0;j<26;++j)
            last[j]=-1;
        for (int j=1;j<=n;++j)
            dp[y][j]=(dp[y][j]+dp[y][j-1])%md;
        for (int j=1;j<=n;++j) {
            if (i==1 && last[s[j-1]-'a']==-1) dp[x][j]=1;
            else dp[x][j]=(dp[y][j]-dp[y][last[s[j-1]-'a']+1]+md)%md;
            last[s[j-1]-'a']=j-1;
        }
    }
    long long ans=0;
    for (int i=1;i<=n;++i)
        ans=(ans+dp[x][i])%md;
    cout<<ans;
}