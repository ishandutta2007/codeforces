#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128
lll a[300005],f[300005];
void out(lll x){
    if(x){
        out(x/10);
        printf("%d",(int)(x%10));
    }
}
void output(lll x){
    if(x==0)printf("0");
    else if(x<0){
        putchar('-');
        out(-x);
    }
    else out(x);
}
void work(){
    int n,m,i,j;ll x;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            scanf("%lld",&x);
            a[j]=(lll)x;
        }
        for(j=1;j<=m;++j)a[j]+=a[j-1];
        for(j=1;j<=m;++j)a[j]+=a[j-1];
        f[i]=a[m];
    }
    for(i=1;i<=n;++i){
        int pre=i-1,nxt=i%n+1;
        if(pre==0)pre=n;
        if(f[i]!=f[pre]&&f[i]!=f[nxt]){
            printf("%d ",i);
            output(f[nxt]-f[i]);puts("");
            return;
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}