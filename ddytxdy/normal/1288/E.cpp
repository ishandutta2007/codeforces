#include<bits/stdc++.h>
using namespace std;
const int N=6e5+50;
int n,m,a[N],mn[N],mx[N],p[N],f[N];
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x;
}
void add(int x,int k){for(;x<=n+m;x+=x&-x)f[x]+=k;}
int ask(int x){int y=0;for(;x;x-=x&-x)y+=f[x];return y;}
int main(){
    // freopen("test.in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)mn[i]=mx[i]=i;
    for(int i=m;i;i--)a[i]=read();
    for(int i=1;i<=n;i++)p[i]=i+m,add(i+m,1);
    for(int i=m;i;i--){
        int pp=p[a[i]];mx[a[i]]=max(mx[a[i]],ask(pp));
        mn[a[i]]=1;p[a[i]]=i;
        add(i,1);add(pp,-1);
    }
    for(int i=1;i<=n;i++)mx[i]=max(mx[i],ask(p[i]));
    for(int i=1;i<=n;i++)printf("%d %d\n",mn[i],mx[i]);
}