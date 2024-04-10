#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
#define inf 1000000000
#define maxn 200000
using namespace std;
struct BIT{
    int tree[2000005];
    inline void mem(){
        memset(tree,0,sizeof(tree));
        return;
    }
    inline int lowbit(int x){
        return x&(-x);
    }
    inline void add(int pos,int val){
        pos++;
        while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
        return;
    }
    inline int query(int pos){
        pos++;
        int ans=0;
        while(pos)ans+=tree[pos],pos-=lowbit(pos);
        return ans;
    }
}bit;
int n,maxl,maxw,u[2000005],v[2000005],w[2000005],first[2000005],nxt[2000005];
int root,mn,sum,size[2000005],book[2000005];
int ans;
inline void getroot(int now,int fa){
    int mx=0;
    size[now]=1;
    for (int i=first[now];i;i=nxt[i]){
        if (v[i]==fa||book[v[i]]==1)continue;
        getroot(v[i],now);
        size[now]+=size[v[i]];
        mx=max(mx,size[v[i]]);
    }
    mx=max(mx,sum-size[now]);
    if (mx<mn)mn=mx,root=now;
    return;
}
struct node{
    int l,w;
}c[2000005];
bool cmp(node a,node b){
    return a.w<b.w;
}
int tot;
inline void get(int now,int fa,int nowl,int noww){
    if (nowl>maxl||noww>maxw)return;
    tot++;
    c[tot].l=nowl,c[tot].w=noww;
    for (int i=first[now];i;i=nxt[i]){
        if (v[i]==fa||book[v[i]]==1)continue;
        get(v[i],now,nowl+1,noww+w[i]);
    }
    return;
}
inline int calc(){
    sort(c+1,c+1+tot,cmp);
    int j=1,nowans=0;
    for (int i=tot;i>=1;i--){
        while(j>i)j--,bit.add(c[j].l,-1);
        while(c[i].w+c[j].w<=maxw&&j<i)bit.add(c[j].l,1),j++;
        nowans+=bit.query(maxl-c[i].l);
    }
    for (int i=1;i<j;i++)bit.add(c[i].l,-1);
    return nowans;
}
inline void dfs(int now){
    book[now]=1;
    tot=0;
    get(now,0,0,0);
    ans+=calc();
    for (int i=first[now];i;i=nxt[i]){
        if (book[v[i]]==1)continue;
        tot=0;
        get(v[i],now,1,w[i]);
        ans-=calc();
    }
    for (int i=first[now];i;i=nxt[i]){
        if (book[v[i]]==1)continue;
        root=0,mn=inf,sum=size[v[i]];
        getroot(v[i],0);
        sum=size[v[i]];
        getroot(root,0);
        dfs(root);
    }
    return;
}
signed main(){
    cin>>n>>maxl>>maxw;
    for (int i=2;i<=n;i++){
        int nowfa=0;
        scanf("%d%d",&nowfa,&w[i]);
        u[i]=i,v[i]=nowfa;
        nxt[i]=first[u[i]];
        first[u[i]]=i;
        u[i+n]=v[i],v[i+n]=u[i],w[i+n]=w[i];
        nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
    }
    bit.mem();
    root=0,mn=inf,sum=n;
    getroot(1,0);
    dfs(1);
    cout<<ans<<endl;
 //   return 0;
}