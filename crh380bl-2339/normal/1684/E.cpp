#include<bits/stdc++.h>
using namespace std;
int a[100005];
struct node{
    int val;
    int num;
    node(){
        num=0;
    }
}b[100005];
bool cmp1(node x,node y){
    return x.val<y.val;
}
bool cmp2(node x,node y){
    return x.num<y.num;
}
struct treenode{
    int num;
    int times;
    treenode(){
        times=0;
    }
    treenode operator +(const treenode z)const{
        treenode res;
        res.num=num+z.num;
        res.times=times+z.times;
        return res;
    }
}t[800005];
void up(int i){
    t[i].num=t[i<<1].num+t[i<<1|1].num;
    t[i].times=t[i<<1].times+t[i<<1|1].times;
}
void init(int i,int l,int r){
    t[i].times=0;
    t[i].num=0;
    if(l==r)return;
    int mid=(l+r)>>1;
    init(i<<1,l,mid);
    init(i<<1|1,mid+1,r);
}
void add(int i,int l,int r,int x,int dn,int dt){
    if(l==r){
        t[i].num+=dn;
        t[i].times+=dt;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)add(i<<1,l,mid,x,dn,dt);
    else add(i<<1|1,mid+1,r,x,dn,dt);
    up(i);
}
treenode query(int i,int l,int r,int x,int y){
    if(x<=l&&r<=y)return t[i];
    treenode res;
    res.num=res.times=0;
    int mid=(l+r)>>1;
    if(x<=mid)res=res+query(i<<1,l,mid,x,y);
    if(y>mid)res=res+query(i<<1|1,mid+1,r,x,y);
    return res;
}
int calc(int k,int m){
    int L=1,R=m,mid,ans=0;
    while(L<=R){
        mid=(L+R)>>1;
        treenode tmp=query(1,1,m,1,mid);
        //printf("%d:*%d %d*\n",mid,tmp.num,tmp.times);
        if(tmp.num<=k){
            ans=tmp.times;
            L=mid+1;
        }
        else R=mid-1;
    }
    return ans;
}
void work(){
    map<int,int>M;
    int n,k,i,j,x,m=0;scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for(i=1;i<=n;++i){
        if(i==1||a[i]!=a[i-1]){
            b[++m].num=1;
            b[m].val=a[i];
        }
        else b[m].num++;
    }
    sort(b+1,b+1+m,cmp2);
    for(i=1;i<=m;++i)M[b[i].val]=i;
    init(1,1,m);
    for(i=1;i<=m;++i){
        add(1,1,m,M[b[i].val],b[i].num,1);
    }
    sort(b+1,b+1+m,cmp1);
    //printf("*%d*",calc(k,m));
    int mex,ans=n+5;
    for(mex=0,j=1;mex<=n+1;++mex){
        while(j<=m&&b[j].val<mex){
            add(1,1,m,M[b[j].val],-b[j].num,-1);
            ++j;
        }
        int k1=mex-j+1;
        if(k1>k)continue;
        //printf("<%d %d><%d,%d>\n",mex,k1,m-j+1,calc(k,m));
        ans=min(ans,m-j+1-calc(k,m));
    }
    printf("%d\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}