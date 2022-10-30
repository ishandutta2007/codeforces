#include <bits/stdc++.h>
using namespace std;



int n;
string s;
vector<int> v,k,x;
int dp[100][100][100][2];

inline int solve(int xx,int y,int z,int zz){
    int res=0;
    for (int i=y;i<v.size() && v[i]<xx;++i) ++res;
    for (int i=z;i<k.size() && k[i]<xx;++i) ++res;
    for (int i=zz;i<x.size() && x[i]<xx;++i) ++res;
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    for (int i=1;i<=n;++i) {
        if (s[i-1]=='V') v.push_back(i);
        else if (s[i-1]=='K') k.push_back(i);
        else x.push_back(i);
    }
    for (int i=0;i<=v.size();++i)
        for (int j=0;j<=k.size();++j)
            for (int ii=0;ii<=x.size();++ii)
                for (int zz=0;zz<2;++zz)
                    dp[i][j][ii][zz]=1e9;
    dp[0][0][0][0]=0;
    for (int i=0;i<=v.size();++i) {
        for (int j=0;j<=k.size();++j) {
            for (int ii=0;ii<=x.size();++ii) {
                for (int jj=0;jj<2;++jj) if (dp[i][j][ii][jj]!=1e9) {
                    int res=dp[i][j][ii][jj];
                    if (i<v.size()) dp[i+1][j][ii][1]=min(dp[i+1][j][ii][1],res+solve(v[i],i,j,ii));
                    if (j<k.size() && !jj) dp[i][j+1][ii][0]=min(dp[i][j+1][ii][0],res+solve(k[j],i,j,ii));
                    if (ii<x.size()) dp[i][j][ii+1][0]=min(dp[i][j][ii+1][0],res+solve(x[ii],i,j,ii));
                }
            }
        }
    }
    int ans=dp[v.size()][k.size()][x.size()][0];
    ans=min(ans,dp[v.size()][k.size()][x.size()][1]);
    cout<<ans;
}