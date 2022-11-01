#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,p,k;
int a[100005];
int tmp[100005][8];
int s[100005][7];
ll dp[100005][1<<7];

int main(){

    scanf("%d%d%d",&n,&p,&k);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)for(int j=0;j<p;j++)scanf("%d",s[i]+j);
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    sort(v.begin(),v.end(),[](int i,int j){
        return a[i]>a[j];
    });
    for(int i=1;i<=n;i++){
        int cur=v[i-1];
        tmp[i][0]=a[cur];
        for(int j=0;j<p;j++)tmp[i][j+1]=s[cur][j];
    }
    for(int i=1;i<=n;i++){
        a[i]=tmp[i][0];
        for(int j=0;j<p;j++)s[i][j]=tmp[i][j+1];
    }
    for(int i=0;i<=n;i++)for(int j=0;j<1<<p;j++)dp[i][j]=-1e18;
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int msk=0;msk<1<<p;msk++){
            int pc=__builtin_popcount(msk);
            if(i<pc)continue;
            dp[i][msk]=dp[i-1][msk]+(i-pc<=k)*a[i];
            for(int j=0;j<p;j++){
                if(msk>>j&1)dp[i][msk]=max(dp[i][msk],dp[i-1][msk^(1<<j)]+s[i][j]);
            }
        }
    }
    cout<<dp[n][(1<<p)-1]<<endl;

    return 0;
}