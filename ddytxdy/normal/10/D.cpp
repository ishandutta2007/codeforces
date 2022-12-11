#include<bits/stdc++.h>
using namespace std;
const int N=501,K=(1<<16)-1;
int n,m,a[N],b[N],f[N],g[N],p,st[N],tp;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        for(int j=1,k=0;j<=m;j++)
            if(a[i]==b[j])f[j]=f[k]+1,g[j]=k;
            else if(a[i]>b[j]&&f[j]>f[k])k=j;
    for(int i=1;i<=m;i++)if(f[i]>f[p])p=i;
    printf("%d\n",f[p]);
    while(p)st[++tp]=b[p],p=g[p];
    while(tp)printf("%d ",st[tp--]);
    return 0;
}