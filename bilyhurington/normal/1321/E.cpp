/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-01 22:47:06
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int n,m,p;
long long csta[1000010],cstb[1000010],ans=-5e18;
struct monster{
    int x,y,z;
}mons[200010];
struct Segment_Tree{
    long long maxn[4000010],tag[4000010];
    void build(int k,int l,int r){
        if(l==r){maxn[k]=cstb[l];return;}
        int mid=(l+r)>>1;
        build(k<<1,l,mid);
        build(k<<1|1,mid+1,r);
        maxn[k]=max(maxn[k<<1],maxn[k<<1|1]);
    }
    void push_down(int k){
        if(!tag[k]) return;
        maxn[k<<1]+=tag[k];
        maxn[k<<1|1]+=tag[k];
        tag[k<<1]+=tag[k];
        tag[k<<1|1]+=tag[k];
        tag[k]=0;
    }
    void modify(int k,int l,int r,int x,int y,int ad){
        if(y<x) return;
        if(x<=l&&r<=y){tag[k]+=ad;maxn[k]+=ad;return;}
        int mid=(l+r)>>1;
        push_down(k);
        if(x<=mid) modify(k<<1,l,mid,x,y,ad);
        if(mid<y) modify(k<<1|1,mid+1,r,x,y,ad);
        maxn[k]=max(maxn[k<<1],maxn[k<<1|1]);
    }
    long long ask(){return maxn[1];}
}ST;
bool cmp(monster x,monster y){
    return x.x<y.x;
}
int main(){
    long long x,y;
    scanf("%d %d %d",&n,&m,&p);
    for(int i=1;i<=1000000;i++) csta[i]=-1e18;
    for(int i=1;i<=1000000;i++) cstb[i]=-1e18;
    for(int i=1;i<=n;i++) scanf("%lld %lld",&x,&y),csta[x]=max(csta[x],-y);
    for(int i=1;i<=m;i++) scanf("%lld %lld",&x,&y),cstb[x]=max(cstb[x],-y);
    ST.build(1,1,1000000);
    for(int i=1;i<=p;i++) scanf("%d %d %d",&mons[i].x,&mons[i].y,&mons[i].z);
    sort(mons+1,mons+p+1,cmp);
    int tot=1;
    for(int ti=1;ti<=1000000;ti++){
        while(tot<=n&&mons[tot].x==ti-1) ST.modify(1,1,1000000,mons[tot].y+1,1000000,mons[tot].z),tot++;
        ans=max(ans,csta[ti]+ST.ask());
    }
    printf("%lld",ans);
    return 0;
}