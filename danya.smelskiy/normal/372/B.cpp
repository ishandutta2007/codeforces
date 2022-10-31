#include <bits/stdc++.h>
using namespace std;

int n,m,k;
string s[45];
long long dp[45][45][45][45];
long long kol[45][45];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i){
        cin>>s[i];
        for (int j=1;j<=m;++j) {
            kol[i][j]=kol[i-1][j]+kol[i][j-1]-kol[i-1][j-1]+(s[i][j-1]-'0');
        }
    }
    for (int i=n;i>0;--i) {
        for (int j=m;j>0;--j) {
            for (int ii=i;ii<=n;++ii)
            for (int jj=j;jj<=m;++jj) {
                dp[i][j][ii][jj] = (kol[ii][jj]+kol[i-1][j-1]-kol[i-1][jj]-kol[ii][j-1] ? 0 : 1);
                for (int k=1;k<(1<<4);++k) {
                    int x=i,y=j,xx=ii,yy=jj;
                    int kol=0;
                    if (k&1) {
                        ++kol;
                        ++x;
                    }
                    if (k&2) {
                        ++kol;
                        ++y;
                    }
                    if (k&4) {
                        ++kol;
                        --xx;
                    }
                    if (k&8) {
                        ++kol;
                        --yy;
                    }
                    if (kol&1) dp[i][j][ii][jj]+=dp[x][y][xx][yy];
                    else dp[i][j][ii][jj]-=dp[x][y][xx][yy];
                }
            }
        }
    }
    for (int i=1;i<=k;++i) {
        int x,y,xx,yy;
        cin>>x>>y>>xx>>yy;
        cout<<dp[x][y][xx][yy]<<'\n';
    }
}