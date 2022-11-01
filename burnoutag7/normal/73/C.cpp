#include<bits/stdc++.h>
using namespace std;

string s;
int n,k;
int dp[256][256][256];
int g[256][256];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>k;
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;int t;
        cin>>a>>b>>t;
        g[a-'a'][b-'a']=t;
    }
    memset(dp,0xc0,sizeof(dp));
    dp[0][26][k]=0;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<=26;j++){
            for(int kk=0;kk<=k;kk++){
                for(int l=0;l<26;l++){
                    int nk=(s[i]==l+'a')?kk:(kk-1);
                    if(nk>=0){
                        dp[i+1][l][nk]=max(dp[i+1][l][nk],dp[i][j][kk]+g[j][l]);
                    }
                }
            }
        }
    }
    int ans=-1e9;
    for(int i=0;i<=26;i++){
        for(int j=0;j<=k;j++){
            ans=max(ans,dp[s.size()][i][j]);
        }
    }
    cout<<ans<<endl;

    return 0;
}