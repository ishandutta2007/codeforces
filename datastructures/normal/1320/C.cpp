#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define maxn 1000005
#define inf 10000000000
using namespace std;
int n,m,p,ans=-inf;
struct node{
    int a,b,val;
}a[200005],b[200005],c[200005];
bool cmp(node a,node b){
    return a.a<b.a;
}
int mx[1000010];
struct SGT{
    int tree[8000005],tag[8000005];
    inline void mem(){
        for (register int i=0;i<=8000000;i++)tree[i]=-inf,tag[i]=0;
        return;
    }
    inline void build(int now,int nowl,int nowr){
        if (nowl==nowr){
            tree[now]=mx[nowl];
            return;
        }
        int mid=(nowl+nowr)/2;
        build(now*2,nowl,mid);
        build(now*2+1,mid+1,nowr);
        pushup(now);
        return;
    }
    inline void pushup(int now){
        tree[now]=max(tree[now*2],tree[now*2+1]);
        return;
    }
    inline void pushdown(int now){
        tag[now*2]+=tag[now];
        tag[now*2+1]+=tag[now];
        tree[now*2]+=tag[now];
        tree[now*2+1]+=tag[now];
        tag[now]=0;
        return;
    }
    inline int query(int now,int nowl,int nowr,int lt,int rt){
        pushdown(now);
        if (nowl>=lt&&nowr<=rt)return tree[now];
        int mid=(nowl+nowr)/2,s=-2e9;
        if (mid>=lt)s=max(s,query(now*2,nowl,mid,lt,rt));
        if (mid+1<=rt)s=max(s,query(now*2+1,mid+1,nowr,lt,rt));
        return s;
    }
    inline void update(int now,int nowl,int nowr,int lt,int rt,int k){
        pushdown(now);
        if (nowl>=lt&&nowr<=rt){
            tag[now]+=k;
            tree[now]+=k;
            return;
        }
        int mid=(nowl+nowr)/2;
        if (mid>=lt)update(now*2,nowl,mid,lt,rt,k);
        if (mid+1<=rt)update(now*2+1,mid+1,nowr,lt,rt,k);
        pushup(now);
        return;
    }
}sgt;
signed main(){
    cin>>n>>m>>p;
    for (int i=1;i<=n;i++)scanf("%lld%lld",&a[i].a,&a[i].val);
    for (int i=1;i<=m;i++)scanf("%lld%lld",&b[i].a,&b[i].val);
    for (int i=1;i<=p;i++)scanf("%lld%lld%lld",&c[i].a,&c[i].b,&c[i].val);
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+m,cmp);
    sort(c+1,c+1+p,cmp);
    int j=m;
    mx[maxn+1]=-inf;
    for (int i=maxn;i>=0;i--){
        mx[i]=mx[i+1];
        while(b[j].a==i)mx[i]=max(mx[i],-b[j].val),j--;
    }
    sgt.mem();
    sgt.build(1,1,maxn);
    j=1;
    for (int i=1;i<=n;i++){
        while(a[i].a>c[j].a&&j<=p){
            sgt.update(1,1,maxn,c[j].b+1,maxn,c[j].val);
            j++;
        }
        ans=max(ans,sgt.query(1,1,n,1,maxn)-a[i].val);
    }
    cout<<ans<<endl;
    return 0;
}