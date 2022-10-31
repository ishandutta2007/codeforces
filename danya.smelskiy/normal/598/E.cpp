#include <bits/stdc++.h>
using namespace std;


int n,x,y,z;
int dp[31][31][51];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i=1;i<=30;++i)
    for (int j=1;j<=30;++j) {
        for (int k=1;k<=50;++k)
            dp[i][j][k]=1e9;
        if (i*j<=50) dp[i][j][i*j]=0;
        for (int ii=1;ii<i;++ii)
            for (int k1=0;k1<=min(50,ii*j);++k1)
                for (int k2=0;k2<=min(50-k1,(i-ii)*j);++k2)
                    dp[i][j][k1+k2]=min(dp[i][j][k1+k2],dp[ii][j][k1]+dp[i-ii][j][k2]+(j*j));
        for (int jj=1;jj<j;++jj)
            for (int k1=0;k1<=min(50,jj*i);++k1)
                for (int k2=0;k2<=min(50-k1,(j-jj)*i);++k2)
                    dp[i][j][k1+k2]=min(dp[i][j][k1+k2],dp[i][jj][k1]+dp[i][j-jj][k2]+(i*i));
    }
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x>>y>>z;
        cout<<dp[x][y][z]<<'\n';
    }
}