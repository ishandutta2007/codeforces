#include<bits/stdc++.h>
#define LL long long
#define lowbit(x) x&-x
using namespace std;
const int N=1e6+50;
int n,c[N],m,x1,x2,p[N*4],r2;LL mx[N*4],lz[N*4],r1,ans=-1e18;
struct node{
    int x,y,c;
    bool friend operator <(node a,node b){return a.y>b.y;}
}a[N];
void build(int x,int l,int r){
    if(l==r){mx[x]=-c[l];p[x]=l;return;}
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    if(mx[x<<1]>mx[x<<1|1])mx[x]=mx[x<<1],p[x]=p[x<<1];
    else mx[x]=mx[x<<1|1],p[x]=p[x<<1|1];
}
void change(int x,int l,int r,int ql,LL d){
    if(l>=ql){mx[x]+=d;lz[x]+=d;return;}
    int mid=(l+r)>>1;
    if(lz[x]){
        change(x<<1,l,mid,1,lz[x]);
        change(x<<1|1,mid+1,r,1,lz[x]);
        lz[x]=0;
    }
    if(ql<=mid)change(x<<1,l,mid,ql,d);
    change(x<<1|1,mid+1,r,ql,d);
    if(mx[x<<1]>mx[x<<1|1])mx[x]=mx[x<<1],p[x]=p[x<<1];
    else mx[x]=mx[x<<1|1],p[x]=p[x<<1|1];
}
void query(int x,int l,int r,int ql){
    if(l>=ql){if(mx[x]>r1)r1=mx[x],r2=p[x];return;}
    int mid=(l+r)>>1;
    if(lz[x]){
        change(x<<1,l,mid,1,lz[x]);
        change(x<<1|1,mid+1,r,1,lz[x]);
        lz[x]=0;
    }
    query(x<<1|1,mid+1,r,ql);
    if(ql<=mid)query(x<<1,l,mid,ql);
}
int main(){
    scanf("%d",&n);
    for(int i=1,x,y;i<=n;i++){
        scanf("%d%d%d",&x,&y,&a[i].c);
        if(x<y)swap(x,y);c[i]=x;c[i+n]=y;
        a[i].x=x;a[i].y=y;
    }
    sort(c+1,c+n*2+1);m=unique(c+1,c+n*2+1)-c-1;
    for(int i=1;i<=n;i++)a[i].x=lower_bound(c+1,c+m+1,a[i].x)-c;
    for(int i=1;i<=n;i++)a[i].y=lower_bound(c+1,c+m+1,a[i].y)-c;
    sort(a+1,a+n+1);build(1,1,m);
    for(int i=1,j;i<=n;i++){
        j=i;
        while(j<=n&&a[j+1].y==a[j].y)j++;
        for(int k=i;k<=j;k++)change(1,1,m,a[k].x,a[k].c);
        r1=-1e18;
        query(1,1,m,a[i].y);r1+=c[a[i].y];
        if(r1>ans)ans=r1,x2=r2,x1=a[i].y;
        i=j;
    }
    if(ans<0){
        puts("0");x1=x2=2e9;
        printf("%d %d %d %d\n",x1,x1,x2,x2);
        return 0;
    }
    cout<<ans<<endl;
    printf("%d %d %d %d\n",c[x1],c[x1],c[x2],c[x2]);
    return 0;
}