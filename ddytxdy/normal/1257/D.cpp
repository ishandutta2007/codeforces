#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
namespace ZBK{
const int N=2e5+50;
int t,n,m,a[N],c[N*2],tot,dat[N*2],ans;
struct node{int p,s;bool friend operator <(node a,node b){return a.p>b.p;}}b[N];
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+(c^48),c=getchar();
    return x;
}
void solve(){
    n=read();ans=0;
    for(int i=1;i<=n;i++)c[i]=a[i]=read();
    m=read();
    for(int i=1;i<=m;i++)c[i+n]=b[i].p=read(),b[i].s=read();
    sort(c+1,c+n+m+1);tot=unique(c+1,c+n+m+1)-c-1;
    for(int i=1;i<=n;i++)a[i]=lower_bound(c+1,c+tot+1,a[i])-c;
    for(int i=1;i<=m;i++)b[i].p=lower_bound(c+1,c+tot+1,b[i].p)-c;
    sort(b+1,b+m+1);
    for(int i=tot,j=1,mx=0;i;i--){
        while(j<=m&&b[j].p==i)mx=max(mx,b[j++].s);
        dat[i]=mx;
    }
    if(!dat[tot]){puts("-1");return;}
    for(int i=1,j,mx;i<=n;i++){
        j=i;mx=a[i];ans++;
        while(j<n&&dat[max(mx,a[j+1])]>=j+1-i+1)mx=max(mx,a[++j]);
        i=j;
    }
    printf("%d\n",ans);
}
void main(){
    t=read();
    while(t--)solve();
}
}
int main(){ZBK::main();return 0;}