#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=2005;
const int mdn=1000000007;

unsigned f[maxn][maxn][3];
unsigned g[maxn][maxn][3];
int n;
char s[2][maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>(s[0]+1)>>(s[1]+1);
        for(int i=0;i<2;i++){
            for(int j=1;j<=n;j++)if(s[i][j]!='?')s[i][j]^=j&1;
        }
        for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)for(int k=0;k<3;k++)f[i][j][k]=g[i][j][k]=0;
        f[0][0][0]=1;
        g[0][0][0]=0;
        for(int i=0;i<=n;i++)for(int j=0;j<=n;j++){
            if(i==0&&j==0)continue;
            if(i&&(s[0][i]!='1')){
                f[i][j][0]=(f[i-1][j][0]+f[i-1][j][2])%mdn,g[i][j][0]=(g[i-1][j][0]+g[i-1][j][2])%mdn;
            }
            if(j&&(s[1][j]!='1')){
                f[i][j][1]=(f[i][j-1][0]+f[i][j-1][1]+f[i][j-1][2])%mdn,g[i][j][1]=(g[i][j-1][0]+g[i][j-1][1]+g[i][j-1][2])%mdn;
            }
            if(i&&j&&s[0][i]!='0'&&s[1][j]!='0'){
                f[i][j][2]=(f[i-1][j-1][0]+f[i-1][j-1][1]+f[i-1][j-1][2])%mdn;
                g[i][j][2]=((g[i-1][j-1][0]+g[i-1][j-1][1]+g[i-1][j-1][2])+
                (f[i-1][j-1][0]+f[i-1][j-1][1]+f[i-1][j-1][2])*(unsigned long long)abs(i-j))%mdn;
            }
        }
        cout<<(g[n][n][0]+g[n][n][1]+g[n][n][2])%mdn<<'\n';
    }
    return 0;
}