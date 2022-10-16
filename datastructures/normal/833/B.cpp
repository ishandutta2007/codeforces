#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 100000
using namespace std;
int n,k,a[1000005],book[1000005],pre[1000005],f[1000005];
struct SGT{
    int tree[1000005],tag[1000005];
    inline void mem(){
        memset(tree,0,sizeof(tree));
        memset(tag,0,sizeof(tag));
    }
    inline void pushdown(int now){
        tree[now*2]+=tag[now],tree[now*2+1]+=tag[now];
        tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
        tag[now]=0;
        return;
    }
    inline void pushup(int now){
        tree[now]=max(tree[now*2],tree[now*2+1]);
        return;
    }
    inline void update(int now,int nowl,int nowr,int lt,int rt,int val){
        pushdown(now);
        if (nowl>=lt&&nowr<=rt){
            tree[now]+=val;
            tag[now]+=val;
            return;
        }
        int mid=(nowl+nowr)/2;
        if (mid>=lt)update(now*2,nowl,mid,lt,rt,val);
        if (mid+1<=rt)update(now*2+1,mid+1,nowr,lt,rt,val);
        pushup(now);
        return;
    }
    inline int query(int now,int nowl,int nowr,int lt,int rt){
        pushdown(now);
        if (nowl>=lt&&nowr<=rt)return tree[now];
        int mid=(nowl+nowr)/2,s=0;
        if (mid>=lt)s=max(s,query(now*2,nowl,mid,lt,rt));
        if (mid+1<=rt)s=max(s,query(now*2+1,mid+1,nowr,lt,rt));
        return s;
    }
    inline void add(int l,int r,int val){
        update(1,1,maxn,l+1,r+1,val);
        return;
    }
    inline int ask(int l,int r){
        return query(1,1,maxn,l+1,r+1);
    }
}sgt;
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        pre[i]=book[a[i]];
        book[a[i]]=i;
    }
    sgt.mem();
    for (int i=1;i<=k;i++){
        for (int j=1;j<=n;j++){
            sgt.add(pre[j],j-1,1);
            f[j]=sgt.ask(0,j-1);
        }
        sgt.mem();
        for (int j=1;j<=n;j++)sgt.add(j,j,f[j]);
    }
    cout<<f[n]<<endl;
    return 0;
}