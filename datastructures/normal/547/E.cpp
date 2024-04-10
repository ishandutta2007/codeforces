#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,T;
char t[200005],s[1000005];
int l[200005],r[200005],endpos[200005],len[200005],root[200005];
struct accept{
    int son[26],fail;
    accept(){
        memset(son,0,sizeof(son));
        return;
    }
}a[200005];
int cnt;
inline void build(int x){
    len[x]=strlen(t+1);
    int now=0;
    l[x]=m+1;
    for (int i=1;i<=len[x];i++)s[++m]=t[i];
    s[++m]='$';
    r[x]=m-1;
    for (int i=1;i<=len[x];i++){
        if (a[now].son[t[i]-'a']==0)a[now].son[t[i]-'a']=++cnt;
        now=a[now].son[t[i]-'a'];
        if (i==len[x])endpos[x]=now;
    }
    return;
}
int q[200005],head,tail;
int u[200005],v[200005],first[200005],nxt[200005];
inline void getfail(){
    head=1;
    for (int i=0;i<26;i++)
        if (a[0].son[i])q[++tail]=a[0].son[i];
    while(head<=tail){
        int now=q[head];
        head++;
        for (int i=0;i<26;i++)
            if (a[now].son[i]){
                a[a[now].son[i]].fail=a[a[now].fail].son[i];
                q[++tail]=a[now].son[i];
            }
            else a[now].son[i]=a[a[now].fail].son[i];
    }
    for (int i=1;i<=cnt;i++){
        u[i]=a[i].fail,v[i]=i;
        nxt[i]=first[u[i]],first[u[i]]=i;
    }
    return;
}
struct node{
    int l,r,cnt;
    node(){
        l=r=cnt=0;
        return;
    }
}tree[15000005];
int tree_cnt;
inline void tree_add(int &now,int nowl,int nowr,int pos){
    if (now==0)now=++tree_cnt;
    tree[now].cnt++;
    if (nowl==nowr)return;
    int mid=(nowl+nowr)/2;
    if (pos<=mid)tree_add(tree[now].l,nowl,mid,pos);
    else tree_add(tree[now].r,mid+1,nowr,pos);
    return;
}
inline void add(int &now,int pos){
    tree_add(now,1,m,pos);
    return;
}
inline int tree_query(int &now,int nowl,int nowr,int lt,int rt){
    if (nowl>=lt&&nowr<=rt)return tree[now].cnt;
    int mid=(nowl+nowr)/2,nowans=0;
    if (mid>=lt)nowans+=tree_query(tree[now].l,nowl,mid,lt,rt);
    if (mid+1<=rt)nowans+=tree_query(tree[now].r,mid+1,nowr,lt,rt);
    return nowans;
}
inline int query(int now,int nowl,int nowr){
    return tree_query(now,1,m,nowl,nowr);
}
inline int merge(int x,int y){
    if (x==0)return y;
    if (y==0)return x;
    int z=++tree_cnt;
    tree[z].cnt=tree[x].cnt+tree[y].cnt;
    tree[z].l=merge(tree[x].l,tree[y].l);
    tree[z].r=merge(tree[x].r,tree[y].r);
    return z;
}
inline void dfs(int now){
    for (int i=first[now];i;i=nxt[i]){
        dfs(v[i]);
        root[now]=merge(root[now],root[v[i]]);
    }
    return;
}
inline void calc(){
    int now=0;
    for (int i=1;i<=m;i++){
        if (s[i]!='$')now=a[now].son[s[i]-'a'];
        else now=0;
        if (now!=0)add(root[now],i);
    }
    dfs(0);
    return;
}
int main(){
    cin>>n>>T;
    for (int i=1;i<=n;i++){
        scanf("%s",t+1);
        build(i);
    }
    getfail();
    calc();
    while(T--){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        printf("%d\n",query(root[endpos[z]],l[x],r[y]));
    }
}