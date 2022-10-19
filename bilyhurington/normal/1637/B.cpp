#include<bits/stdc++.h>
using namespace std;
int T,n,a[110],cnt[110],val[110][110],f[110];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]=min(a[i],n+1);
    }
    for(int i=1;i<=n;i++){
        memset(cnt,0,sizeof(cnt));
        int mex=0;
        for(int j=i;j<=n;j++){
            cnt[a[j]]++;
            while(cnt[mex]) mex++;
            val[i][j]=mex;
        }
    }long long sum=0;
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof(f));
        for(int j=i;j<=n;j++){
            for(int k=i-1;k<j;k++) f[j]=max(f[j],f[k]+val[k+1][j]+1);
            sum+=f[j];
        }
    }printf("%lld\n",sum);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}