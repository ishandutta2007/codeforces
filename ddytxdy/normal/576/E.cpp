#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50,K=52;
int n,m,k,q,x[N],y[N],id[N],e[N],c[N],f[K][N],s[K][N],tp;bool fl[N],g[K][N],h[K][N];
struct node{int x,p;}st[N];
vector<int>v[N*4];
void change(int x,int l,int r,int ql,int qr,int id){
    if(l>=ql&&r<=qr){v[x].push_back(id);return;}
    int mid=(l+r)>>1;
    if(ql<=mid)change(x<<1,l,mid,ql,qr,id);
    if(qr>mid)change(x<<1|1,mid+1,r,ql,qr,id);
}
int find(int p,int x){
    if(f[p][x]==x){g[p][x]=0;return x;}
    int ff=find(p,f[p][x]);
    g[p][x]=g[p][f[p][x]]^h[p][x];
    return ff;
}
void merge(int x,int y,int p){
    int xx=x,yy=y;
    x=find(p,x),y=find(p,y);
    if(x==y){assert(g[p][xx]^g[p][yy]);return;}
    if(s[p][x]>s[p][y])swap(x,y);
    f[p][x]=y;s[p][y]+=s[p][x];
    h[p][x]=g[p][xx]^g[p][yy]^1;
    st[++tp]=(node){x,p};
}
void undo(int x){
    while(tp>x){
        int x=st[tp].x,p=st[tp].p,y=f[p][x];
        s[p][y]-=s[p][x];f[p][x]=x;tp--;
    }
}
void solve(int id,int l,int r){
    int tt=tp;
    for(int i=0;i<v[id].size();i++){
        int z=v[id][i];
        if(c[z])merge(x[e[z]],y[e[z]],c[z]);
    }
    if(l==r){
        puts(fl[l]?"NO":"YES");
        if(!fl[l])::id[e[l]]=l;
        if(r!=q){
            int xx=x[e[l+1]],yy=y[e[l+1]],cc=c[l+1];
            int fx=find(cc,xx),fy=find(cc,yy);
            if(fx==fy&&!(g[cc][xx]^g[cc][yy]))
                fl[l+1]=1,c[l+1]=c[::id[e[l+1]]];
        }
        undo(tt);return;
    }
    int mid=(l+r)>>1;
    solve(id<<1,l,mid);
    solve(id<<1|1,mid+1,r);
    undo(tt);
}
int main(){
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(int i=1;i<=m;i++)scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=q;i++){
        scanf("%d%d",&e[i],&c[i]);
        if(id[e[i]])change(1,1,q,id[e[i]],i-1,id[e[i]]);
        id[e[i]]=i;
    }
    for(int i=1;i<=m;i++)if(id[i])change(1,1,q,id[i],q,id[i]),id[i]=0;
    for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)f[i][j]=j,s[i][j]=1;
    solve(1,1,q);
    return 0;
}
// 3 3 1 3
// 1 2
// 1 3
// 2 3
// 1 1
// 2 1
// 3 1