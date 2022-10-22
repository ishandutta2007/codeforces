/*
 * @Author: BilyHurington
 * @Date: 2020-09-30 22:35:11
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-10-01 01:02:35
 */
#include<bits/stdc++.h>
using namespace std;
struct Union_Set{
    vector<int> Fa,Siz;
    void Init(int N){
        Fa.resize(N+1);Siz.resize(N+1);
        for(int i=0;i<=N;i++) Fa[i]=i,Siz[i]=1;
    }
    int Find(int x){return Fa[x]==x?x:Fa[x]=Find(Fa[x]);}
    void Link(int x,int y){
        int fx=Find(x),fy=Find(y);
        if(x==y) return;
        if(Siz[fx]>Siz[fy]) swap(fx,fy);
        Fa[fx]=fy;Siz[fy]+=Siz[fx];
    }
}US;
int n,m,a[100010],b[100010],tag[100010];
struct node{
    int val,st_id,nd_id;
    bool operator < (const node &P) const {return val>P.val;}
}N[200010];int tot;
int main(){
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    long long ans=0;
    for(int i=1;i<=m;i++){
        int M,x;scanf("%d",&M);
        while(M--){
            scanf("%d",&x);
            N[++tot]=node{a[i]+b[x],i,x};
            ans+=a[i]+b[x];
        }
    }
    sort(N+1,N+tot+1);US.Init(n);
    for(int i=1;i<=tot;i++){
        if(!tag[N[i].st_id]) tag[N[i].st_id]=US.Find(N[i].nd_id),ans-=N[i].val;
        else{
            if(US.Find(tag[N[i].st_id])!=US.Find(N[i].nd_id)){
                US.Link(tag[N[i].st_id],N[i].nd_id);
                ans-=N[i].val;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}