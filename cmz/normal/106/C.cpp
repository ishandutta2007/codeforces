#include<bits/stdc++.h>
using namespace std;
int n,m,k1,k2;
int a[21],b[20],c[20],d[20];
int f[2010];
int main(){
    scanf("%d%d%d%d",&m,&n,&k1,&k2);
    for (int i=1;i<=n;++i) scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    for (int i=k1;i<=m;++i) f[i]=max(f[i],f[i-k1]+k2);
    for (int i=1;i<=n;++i){
        for (int k=m;k>=c[i];--k)
            for (int j=(a[i]/b[i]);j>=1;--j)
            if (k>=j*c[i]) f[k]=max(f[k],f[k-j*c[i]]+d[i]*j);
    }
    int ans=0;
    for (int i=1;i<=m;++i) ans=max(ans,f[i]);
    printf("%d",ans);
}