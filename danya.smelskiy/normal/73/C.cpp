#include <bits/stdc++.h>
using namespace std;

string s;
int n,k;
int pr[100][100];
int dp[1000][30][105];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>k;
    cin>>n;
    for (int i=1;i<=n;++i) {
        char x,y,z;
        int c;
        cin>>x>>y>>c;
        pr[(x-'a')][(y-'a')]=c;
    }
    int x=s[0]-'a';
    for (int i=1;i<=s.size();++i)
        for (int j=0;j<=k;++j)
            for (int z=0;z<=25;++z)
            dp[i][z][j]=-1e9;
    for (int i=0;i<=25;++i)
        if (i!=x) dp[1][i][1]=0;
        else dp[1][i][0]=0;
    int ans=-1e9;
    for (int i=2;i<=s.size();++i) {
        int xx=s[i-1]-'a';
        for (int j=0;j<=k;++j)
            for (int z=0;z<=25;++z)  {
                for (int zz=0;zz<=25;++zz) {
                    if (zz==xx) {
                        if (dp[i-1][z][j]!=-1e9) dp[i][zz][j]=max(dp[i][zz][j],dp[i-1][z][j]+pr[z][zz]);
                    } else {
                        if (j && dp[i-1][z][j-1]!=-1e9) dp[i][zz][j]=max(dp[i][zz][j],dp[i-1][z][j-1]+pr[z][zz]);
                    }
                }
            }
    }
    for (int i=0;i<=25;++i)
        for (int j=0;j<=k;++j)
        ans=max(ans,dp[(int)s.size()][i][j]);
    cout<<ans;
}