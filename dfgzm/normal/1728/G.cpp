#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=500010,maxm=20,mod=998244353;
int i,j,k,d,n,m,q,l[maxn],p[maxm];
ll sum[maxm][maxm],dp[maxm];
void init(){
    p[0]=-1e9;p[m+1]=1e9;
    for(int i=0;i<=m;i++)
        for(int j=i+1;j<=m+1;j++){
            sum[i][j]=1;
            for(int k=1;k<=n;k++)
                if(l[k]>p[i] && l[k]<p[j])sum[i][j]*=min(d+1,min(l[k]-p[i],p[j]-l[k])),sum[i][j]%=mod;
        }
}
int main(){
    cin>>d>>n>>m;
    for(i=1;i<=n;i++)scanf("%d",&l[i]);
    for(i=1;i<=m;i++)scanf("%d",&p[i]);
    sort(l+1,l+1+n);
    sort(p+1,p+1+m);
    init();
    cin>>q;
    for(i=1;i<=q;i++){
        int D;
        scanf("%d",&D);
        dp[0]=1;
        for(j=1;p[j]<D;j++)
            for(k=0;k<j;k++)
                dp[j]=(dp[j]-dp[k]*sum[k][j]%mod+mod)%mod;
        dp[m+1]=1;
        for(j=m;p[j]>D;j--)
            for(k=m+1;k>j;k--)
                dp[j]=(dp[j]-dp[k]*sum[j][k]%mod+mod)%mod;
        ll Ans=0;
        // for(j=0;j<=m+1;j++)cerr<<"j="<<j<<' '<<dp[j]<<endl;
        for(j=0;p[j]<D;j++)
            for(k=m+1;p[k]>D;k--){
                Ans+=dp[j]*dp[k]%mod*sum[j][k]%mod*min(d+1,min(D-p[j],p[k]-D))%mod;
                // cerr<<j<<' '<<k<<' '<<sum[j][k]<<endl;
            }
        Ans%=mod;
        printf("%lld\n",Ans);
        for(j=0;j<=m+1;j++)dp[j]=0;
    }
}
/*


 dp_{i}  i 

 j

 O(nm^2)

 O(m^2)




*/