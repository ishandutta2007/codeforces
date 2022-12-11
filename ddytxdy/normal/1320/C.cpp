#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50,M=1e6+1;
int n,m,p,mx[M*4+10],laz[M*4+10],dat[M+10],ans=-2e9;
struct node{int a,c;bool friend operator <(node a,node b){return a.a<b.a;}}a[N],b[N];
struct node1{
    int x,y,z;
    bool friend operator <(node1 a,node1 b){return a.x<b.x;}
}Q[N];
void build(int x,int l,int r){
    if(l==r){mx[x]=dat[l];return;}
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    mx[x]=max(mx[x<<1],mx[x<<1|1]);
}
void change(int x,int l,int r,int ql,int qr,int d){
    if(l>=ql&&r<=qr){mx[x]+=d;laz[x]+=d;return;}
    int mid=(l+r)>>1;
    if(laz[x]){
        change(x<<1,l,mid,1,M,laz[x]);
        change(x<<1|1,mid+1,r,1,M,laz[x]);
        laz[x]=0;
    }
    if(ql<=mid)change(x<<1,l,mid,ql,qr,d);
    if(qr>mid)change(x<<1|1,mid+1,r,ql,qr,d);
    mx[x]=max(mx[x<<1],mx[x<<1|1]);
}
int main(){
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].a,&a[i].c);
    for(int i=1;i<=m;i++)scanf("%d%d",&b[i].a,&b[i].c);
    for(int i=1;i<=p;i++)scanf("%d%d%d",&Q[i].x,&Q[i].y,&Q[i].z);
    sort(a+1,a+n+1);sort(b+1,b+m+1);sort(Q+1,Q+p+1);
    for(int i=1;i<=M;i++)dat[i]=-1.5e9;
    for(int i=1;i<=m;i++)dat[b[i].a]=max(dat[b[i].a],-b[i].c);
    build(1,1,M);
    for(int i=1,j=0;i<=n;i++){
        while(j<p&&Q[j+1].x<a[i].a)
            j++,change(1,1,M,Q[j].y+1,M,Q[j].z);
        ans=max(ans,mx[1]-a[i].c);
    }
    cout<<ans;
    return 0;
}