#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
struct BIT{
    int tree[300005],maxn;
    BIT(){
        memset(tree,0,sizeof(tree));
        maxn=300000;
        return;
    }
    int lowbit(int x){
        return x&(-x);
    }
    void add(int l,int r){
        while(l<=maxn)tree[l]++,l+=lowbit(l);
        r++;
        while(r<=maxn)tree[r]--,r+=lowbit(r);
        return;
    }
    int ask(int pos){
        int ans=0;
        while(pos)ans+=tree[pos],pos-=lowbit(pos);
        return ans;
    }
}bit;
int n,m,x[500005],y[500005],z[500005];
int dsu[300005],totm,u[600005],v[600005],w[600005],first[300005],nxt[600005];
int fa[300005][25],depth[300005],val[300005],idx,l[300005],r[300005];
int dsu_find(int x){
    if (x==dsu[x])return x;
    return dsu[x]=dsu_find(dsu[x]);
}
void add(int a,int b,int c){
    int i=++totm;
    u[i]=a,v[i]=b,w[i]=c;
    nxt[i]=first[u[i]],first[u[i]]=i;
    return;
}
void dfs(int now,int f,int d,int s){
    fa[now][0]=f,depth[now]=d,val[now]=s;
    for (int i=1;i<=20;i++)fa[now][i]=fa[fa[now][i-1]][i-1];
    l[now]=++idx;
    for (int i=first[now];i;i=nxt[i])
        if (v[i]!=f)dfs(v[i],now,d+1,s^w[i]);
    r[now]=idx;
    return;
}
int lca(int a,int b){
    if (depth[a]<depth[b])swap(a,b);
    for (int i=20;i>=0;i--)
        if (depth[fa[a][i]]>=depth[b])a=fa[a][i];
    if (a==b)return a;
    for (int i=20;i>=0;i--)
        if (fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
    return fa[a][0];
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++)dsu[i]=i;
    for (int i=1;i<=m;i++){
        x[i]=read(),y[i]=read(),z[i]=read();
        if (dsu_find(x[i])==dsu_find(y[i]))continue;
        add(x[i],y[i],z[i]);
        add(y[i],x[i],z[i]);
        dsu[dsu_find(y[i])]=dsu_find(x[i]);
    }
    for (int i=1;i<=n;i++)
        if (l[i]==0)dfs(i,0,0,0);
    for (int i=1;i<=n;i++)dsu[i]=i;
    for (int i=1;i<=m;i++){
        if (dsu_find(x[i])!=dsu_find(y[i])){
            puts("YES");
            dsu[dsu_find(y[i])]=dsu_find(x[i]);
        }
        else{
            if (bit.ask(l[x[i]])+bit.ask(l[y[i]])-2*bit.ask(l[lca(x[i],y[i])])>0){
                puts("NO");
                continue;
            }
            if ((val[x[i]]^val[y[i]]^z[i])!=1){
                puts("NO");
                continue;
            }
            puts("YES");
            int a=x[i],b=y[i],c=lca(x[i],y[i]);
            while(depth[a]>depth[c]){
                bit.add(l[a],r[a]);
                a=fa[a][0];
            }
            while(depth[b]>depth[c]){
                bit.add(l[b],r[b]);
                b=fa[b][0];
            }
        }
    }
    return 0;
}