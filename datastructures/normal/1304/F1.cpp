#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,k,a[55][20005],sum[55][20005],f[55][20005],ans;
int _a[20005],tree[200005],tag[200005];
inline int gets(int i,int l,int r){
    return sum[i][r]-sum[i][l-1];
}
inline void pushup(int now){
    tree[now]=max(tree[now*2],tree[now*2+1]);
    return;
}
inline void pushdown(int now){
    tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
    tree[now*2]+=tag[now],tree[now*2+1]+=tag[now];
    tag[now]=0;
    return;
}
inline void build(int now,int nowl,int nowr){
    if (nowl==nowr){
        tree[now]=_a[nowl];
        return;
    }
    int mid=(nowl+nowr)/2;
    build(now*2,nowl,mid);
    build(now*2+1,mid+1,nowr);
    pushup(now);
    return;
}
inline int query(){
    return max(0,tree[1]);
}
inline void update(int now,int nowl,int nowr,int lt,int rt,int k){
    pushdown(now);
    if (nowl>=lt&&nowr<=rt){
        tree[now]+=k;
        tag[now]+=k;
        return;
    }
    int mid=(nowl+nowr)/2;
    if (mid>=lt)update(now*2,nowl,mid,lt,rt,k);
    if (mid+1<=rt)update(now*2+1,mid+1,nowr,lt,rt,k);
    pushup(now);
    return;    
}
int main(){
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            sum[i][j]=sum[i][j-1]+a[i][j];
    for (int i=2;i<=n+1;i++){
        memset(tree,0,sizeof(tree));
        memset(tag,0,sizeof(tag));
        for (int j=1;j<=m;j++)
            _a[j]=f[i-1][j];
        build(1,1,m);
        for (int j=1;j<=m;j++){
            update(1,1,m,j,min(j+k-1,m),-a[i-1][j]);
            f[i][j]=gets(i-1,max(j-k+1,1),j)+gets(i,max(j-k+1,1),j)+query();
            ans=max(ans,f[i][j]);
            if (j-k+1>=1)update(1,1,m,j-k+1,j,a[i-1][j-k+1]);
        }
    }
    cout<<ans<<endl;
    return 0;
}