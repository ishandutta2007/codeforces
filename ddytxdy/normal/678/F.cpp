#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+50;
int n,cnt,x[N],y[N],s[N],t[N],q[N],m,p[N],L[N*4],R[N*4],tt[N],num;LL d,ans[N];
vector<int>v[N*4];
int read(){
    int x=0,f=1;char c=getchar();
    while(!isdigit(c))c=='-'?f=-1:0,c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x*f;
}
void write(LL x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
bool cmp(int a,int b){return x[a]<x[b];}
bool cmpp(int a,int b){return q[a]<q[b];}
bool cmp1(int a,int b,int c){
    int x1=x[b]-x[a],x2=x[c]-x[b],y1=y[b]-y[a],y2=y[c]-y[b];
    return 1ll*y1*x2<=1ll*y2*x1;
}
bool cmp2(int a,int b,int k){return y[b]-y[a]>=1ll*(x[b]-x[a])*k;}
LL calc(int a,int q){return 1ll*x[a]*q+y[a];}
void change(int x,int l,int r,int ql,int qr,int id){
    if(l>=ql&&r<=qr){
        while(L[x]+1<=R[x]&&cmp1(v[x][R[x]-1],v[x][R[x]],id))R[x]--,v[x].pop_back();
        R[x]++;v[x].push_back(id);return;
    }
    int mid=(l+r)>>1;
    if(ql<=mid)change(x<<1,l,mid,ql,qr,id);
    if(qr>mid)change(x<<1|1,mid+1,r,ql,qr,id);
}
void query(int x,int l,int r,int p,int k){
    while(L[x]+1<=R[x]&&cmp2(v[x][L[x]],v[x][L[x]+1],k))L[x]++;
    if(L[x]<=R[x])d=max(d,calc(v[x][L[x]],-k));
    if(l==r)return;int mid=(l+r)>>1;
    p<=mid?query(x<<1,l,mid,p,k):query(x<<1|1,mid+1,r,p,k);
}
int main(){
    n=read();
    for(int i=1,op,id;i<=n;i++){
        op=read();
        if(op==1)x[i]=read(),y[i]=read(),s[i]=i;
        else x[i]=1e9+1;
        if(op==2)id=read(),t[id]=i-1;
        if(op==3)q[++m]=read(),tt[m]=i;
    }
    for(int i=1;i<=n;i++)if(x[i]<=1e9&&!t[i])t[i]=n;
    for(int i=1;i<=n;i++)p[i]=i;
    sort(p+1,p+n+1,cmp);for(int i=1;i<=n*4;i++)R[i]=-1;
    for(int i=1;i<=n;i++)if(x[p[i]]<=1e9)change(1,1,n,s[p[i]],t[p[i]],p[i]);
    for(int i=1;i<=m;i++)p[i]=i;
    sort(p+1,p+m+1,cmpp);
    for(int i=1;i<=m;i++){
        d=-2e18;
        query(1,1,n,tt[p[i]],-q[p[i]]);
        ans[p[i]]=d;
    }
    for(int i=1;i<=m;i++){
        if(ans[i]==-2e18)puts("EMPTY SET");
        else write(ans[i]),putchar('\n');
    }
    return 0;
}