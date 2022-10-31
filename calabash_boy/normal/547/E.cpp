#include<bits/stdc++.h> 
using namespace std;
#define LL long long
const int Maxn=400010;
int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*f;
}
struct Seg{
    int l,r,lc,rc,c;
}tr[Maxn<<1];
int trlen=0;
void build(int l,int r) {
    int t=++trlen;
    tr[t].l=l;tr[t].r=r;tr[t].c=0;
    if(l<r) {
        int mid=l+r>>1;
        tr[t].lc=trlen+1;
        build(l,mid);
        tr[t].rc=trlen+1;
        build(mid+1,r);
    }
}
void add(int now,int p) {
    if(tr[now].l==tr[now].r){
        tr[now].c++;
        return;
    }
    int mid=tr[now].l+tr[now].r>>1,lc=tr[now].lc,rc=tr[now].rc;
    if(p<=mid)add(lc,p);
    else add(rc,p);
    tr[now].c=tr[lc].c+tr[rc].c;
}
LL query(int now,int l,int r) {
    if(tr[now].l==l&&tr[now].r==r)return tr[now].c;
    int mid=tr[now].l+tr[now].r>>1,lc=tr[now].lc,rc=tr[now].rc;
    if(r<=mid)return query(lc,l,r);
    else if(l>mid)return query(rc,l,r);
    return query(lc,l,mid)+query(rc,mid+1,r);
}
int tot=1,last=1;
int par[Maxn],son[Maxn][26],mx[Maxn];
int lim[200010];LL Right[Maxn];
void extend(int x) {
    int p=last,np=++tot;
    mx[np]=mx[p]+1;Right[np]=1;
    while(p&&!son[p][x])son[p][x]=np,p=par[p];
    if(!p)par[np]=1;
    else {
        int q=son[p][x];
        if(mx[p]+1==mx[q])par[np]=q;
        else {
            int nq=++tot;mx[nq]=mx[p]+1;
            for(int i=0;i<26;i++)son[nq][i]=son[q][i];
            par[nq]=par[q]; par[q]=par[np]=nq;
            while(son[p][x]==q)son[p][x]=nq,p=par[p];
        }
    }
    last=np;
}
struct Edge{
    int y,next;
}e[Maxn];
int Last[Maxn],Len=0;
void ins(int x,int y){
    int t=++Len;e[t].y=y;e[t].next=Last[x];Last[x]=t;
}
int dfn=0,in[Maxn],out[Maxn];
void dfs(int x) {
    in[x]=++dfn;
    for(int i=Last[x];i;i=e[i].next)dfs(e[i].y);
    out[x]=dfn;
}
struct Query{
    int p,x,id,f;
}q[1000010];
bool cmp(Query a,Query b){return a.p<b.p;}
LL ans[500010];
int n,Q;
string s[200010];
int len[200010];
int pos[200010];
int main() {
    n=read(),Q=read();
    lim[0]=1;
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        len[i]=s[i].size();
        last=1;
        for(int j=0;j<len[i];j++)extend(s[i][j]-'a');
        lim[i]=tot;
    }
    for(int i=2;i<=tot;i++)ins(par[i],i);
    dfs(1);
    build(1,dfn);
    for(int i=1;i<=n;i++) {
        int now=1;
        for(int j=0;j<len[i];j++) now=son[now][s[i][j]-'a'];
        pos[i]=now;
    }
    for(int i=1;i<=Q;i++) {
        q[(i<<1)-1].p=read()-1;
        q[i<<1].p=read();
        q[(i<<1)-1].x=q[i<<1].x=read();
        q[(i<<1)-1].id=q[i<<1].id=i;
        q[(i<<1)-1].f=-1,q[i<<1].f=1;
    }
    sort(q+1,q+1+(Q<<1),cmp);
    int now=1;
    while(!q[now].p)now++;
    for(int i=1;i<=n;i++) {
        for(int j=lim[i-1]+1;j<=lim[i];j++) if(Right[j])add(1,in[j]);
        while(now<=(Q<<1)&&q[now].p==i) ans[q[now].id]+=q[now].f*query(1,in[pos[q[now].x]],out[pos[q[now].x]]),now++;
    }
    for(int i=1;i<=Q;i++)printf("%lld\n",ans[i]);
}