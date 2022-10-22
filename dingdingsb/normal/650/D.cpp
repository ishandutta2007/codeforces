#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0;char c=getchar();bool f=0;
    for(;!isdigit(c);c=getchar())f^=c=='-';
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+c-'0';
    if(f)x=-x;return x;
}
void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)write(x/10);
    putchar(x%10+'0');
}
const int maxn=4e5+10;
namespace TREE{
    struct node{
        int l,r;
        int val;
    }tree[maxn<<3];
    void build(int x,int l,int r){
        tree[x].l=l,tree[x].r=r,tree[x].val=0;
        if(l==r)return;
        int mid=l+r>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
    }
    void change(int x,int pos,int val){
        tree[x].val=max(tree[x].val,val);
        if(tree[x].l==tree[x].r)
            return;
        int mid=tree[x].l+tree[x].r>>1;
        if(pos<=mid)change(x<<1,pos,val);
        else change(x<<1|1,pos,val);
    }
    int query(int x,int l,int r){
        if(l<=tree[x].l&&tree[x].r<=r)return tree[x].val;
        if(l>tree[x].r||r<tree[x].l)return 0;
        return max(query(x<<1,l,r),query(x<<1|1,l,r));
    }
}
using namespace TREE;
int n,m;
int a[maxn];
struct nnn{
    int  a,b;
    int ans;
}cmd[maxn];
vector<int>v[maxn];
set<int>S;map<int,int>M;
int tot=0;int pos[maxn];
int f[maxn],g[maxn];
signed main(){
    n=read();m=read();
    for(int i=1;i<=n;i++)
        a[i]=read(),S.insert(a[i]);
    for(int i=1;i<=m;i++)
        cmd[i].a=read(),cmd[i].b=read(),S.insert(cmd[i].b),v[cmd[i].a].push_back(i);
    for(set<int>::iterator it=S.begin();it!=S.end();it++)
        M[*it]=++tot;
    build(1,1,tot);
    int len=0;
    for(int i=1;i<=n;i++){
        f[i]=query(1,1,M[a[i]]-1)+1;
        for(int j=0;j<v[i].size();j++)
            cmd[v[i][j]].ans+=query(1,1,M[cmd[v[i][j]].b]-1);
        change(1,M[a[i]],f[i]);
        len=max(len,f[i]);
        //write(f[i]),putchar('\n');
    }
    build(1,1,tot);
    for(int i=n;i>=1;i--){
        g[i]=query(1,M[a[i]]+1,tot)+1;
        for(int j=0;j<v[i].size();j++)
            cmd[v[i][j]].ans+=query(1,M[cmd[v[i][j]].b]+1,tot);
        change(1,M[a[i]],g[i]);
    }
    for(int i=1;i<=n;i++)
        if(f[i]+g[i]==len+1)
            pos[f[i]]++;
    for(int i=1;i<=m;i++){
        int A=cmd[i].a,B=cmd[i].b,C=cmd[i].ans;
        if(f[A]+g[A]==len+1&&pos[f[A]]==1)
            write(max(len-1,C+1)),putchar('\n');
        else
            write(max(len,C+1)),putchar('\n');
    }
}