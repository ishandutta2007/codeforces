#include <bits/stdc++.h>
using namespace std;

int n;
long double x[1005],y[1005],r[1005];
long double dp[1005][2][2];
long double ans;
vector<int> v[1005],q;
inline bool check(int xx,int yy){
    long double z=sqrt((x[xx]-x[yy])*(x[xx]-x[yy])+(y[xx]-y[yy])*(y[xx]-y[yy]));
    long double rr=r[xx];
    return z<=rr;
}
void dfs(int xx){
    long long dp2[2][2];
    for (int i=0;i<=1;++i)
        for (int j=0;j<=1;++j)
            dp2[i][j]=0;
    long double s=r[xx]*r[xx];
    for (int i=0;i<v[xx].size();++i) {
        int to=v[xx][i];
        dfs(to);
        for (int j=0;j<=1;++j)
        for (int k=0;k<=1;++k){
            dp2[j][k]+=dp[to][j][k];
        }
    }
    for (int i=0;i<=1;++i)
    for (int j=0;j<=1;++j) {
        dp[xx][i][j]=dp2[1-i][j]+s*(i==0 ? -1 : 1);
        dp[xx][i][j]=max(dp[xx][i][j],dp2[i][1-j]+s*(j==0 ? -1 : 1));
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x[i]>>y[i]>>r[i];
    }
    for (int i=1;i<=n;++i) {
        int p=-1;
        for (int j=1;j<=n;++j) if (i!=j && r[j]>=r[i] && check(j,i)) {
            if (p==-1 || r[p]>r[j]) p=j;
        }
        if (p==-1) q.push_back(i); else
        v[p].push_back(i);
    }
    for (int i=0;i<q.size();++i) {
        dfs(q[i]);
        int xx=q[i];
        long double qq=0;
        for (int j=0;j<=1;++j)
            for (int k=0;k<=1;++k)
                qq=max(qq,dp[xx][j][k]);
        ans+=qq;
    }
    long double pi=3.14159265359;
    ans=ans*pi;
    cout<<fixed<<setprecision(10)<<ans;
}