#include <bits/stdc++.h>
using namespace std;

int n,a,b;
int h[100];
int dp[12][20][20][20];
int pred1[12][20][20][20];
int pred2[12][20][20][20];
int pred3[12][20][20][20];
int pred4[12][20][20][20];


inline void check(int i,int x,int y,int z,int xx,int yy,int zz,int r){
    if (xx) return;
    if (dp[i][x][y][z]+r>dp[i+1][yy][zz][h[i+2]]) return;
    dp[i+1][yy][zz][h[i+2]]=dp[i][x][y][z]+r;
    pred1[i+1][yy][zz][h[i+2]]=x;
    pred2[i+1][yy][zz][h[i+2]]=y;
    pred3[i+1][yy][zz][h[i+2]]=z;
    pred4[i+1][yy][zz][h[i+2]]=r;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b;
    for (int i=1;i<=n;++i) {
        cin>>h[i];
        ++h[i];
    }
    for (int i=1;i<=n;++i)
        for (int j=0;j<=17;++j)
            for (int k=0;k<=17;++k)
                for (int z=0;z<=17;++z)
                    dp[i][j][k][z]=1e9;
    dp[2][h[1]][h[2]][h[3]]=0;
    for (int i=2;i<n;++i) {
        for (int j=0;j<=17;++j)
        for (int k=0;k<=17;++k) {
        for (int z=0;z<=17;++z) if (dp[i][j][k][z]!=1e9) {
            for (int zz=0;zz<=17;++zz) {
                check(i,j,k,z,max(0,j-zz*b),max(0,k-a*zz),max(0,z-b*zz),zz);
            }
        }
        }
    }
    int res=1e9;
    int pos1=0,pos2=0,pos3=0;
    for (int i=0;i<=17;++i)
    for (int k=0;k<=17;++k) {
    for (int z=0;z<=17;++z) {
        if (i<=z*a && k<=z*b && res>dp[n][i][k][0]+z) {
            res=dp[n][i][k][0]+z;
            pos1=i;
            pos2=k;
            pos3=z;
        }
    }
    }
    cout<<res<<'\n';
    vector<int> ans;
    for (int j=1;j<=pos3;++j)
        ans.push_back(n-1);
    pos3=0;
    for (int i=n;i>0;--i) {
        for (int j=1;j<=pred4[i][pos1][pos2][pos3];++j)
        ans.push_back(i-1);
        int x,y,z;
        x=pred1[i][pos1][pos2][pos3];
        y=pred2[i][pos1][pos2][pos3];
        z=pred3[i][pos1][pos2][pos3];
        pos1=x; pos2=y; pos3=z;
    }
    for (int i=ans.size()-1;i>=0;--i)
        cout<<ans[i]<<" ";
}