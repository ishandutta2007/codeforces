#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
string s[100];
int dp[100][100];

inline int get(int x,int y,int xx,int yy){
    int res=0;
    res=dp[xx][yy]+dp[x-1][y-1]-dp[xx][y-1]-dp[x-1][yy];
    return res;
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>s[i];
    for (int i=1;i<=n;++i)
    for (int j=1;j<=m;++j) {
        dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+(s[i][j-1]-'0');
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            for (int k=i;k<=n;++k)
                for (int z=j;z<=m;++z)
                    if (!get(i,j,k,z)) ans=max(ans,k-i+1+k-i+1+z-j+1+z-j+1);
    cout<<ans;
}