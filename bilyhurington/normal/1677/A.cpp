#include<bits/stdc++.h>
using namespace std;
int T,n,p[5010],sum1[5010][5010],sum2[5010][5010];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    long long ans=0;
    for(int i=0;i<=n;i++) sum1[0][i]=0,sum2[n+1][i]=0;
    for(int i=1;i<=n;i++){
        memcpy(sum1[i],sum1[i-1],sizeof(sum1[i]));
        for(int j=p[i];j<=n;j++) sum1[i][j]++;
        // for(int j=0;j<=n;j++) printf("%d ",sum1[i][j]);puts("");
    }
    for(int i=n;i>=1;i--){
        memcpy(sum2[i],sum2[i+1],sizeof(sum2[i]));
        for(int j=p[i];j<=n;j++) sum2[i][j]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans+=1ll*sum1[i-1][p[j]]*sum2[j+1][p[i]];
            // printf("%d %d %lld\n",i,j,1ll*sum1[i-1][p[j]]*sum2[j+1][p[i]]);
        }
    }
    printf("%lld\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}