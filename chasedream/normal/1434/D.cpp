#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define rep(i,l,r) for(rint i=l;i<=r;i++)
#define per(i,l,r) for(rint i=l;i>=r;i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define fir first
#define sec second
#define mset(s,t) memset(s,t,sizeof(s))
template<typename T1,typename T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}
template<typename T1,typename T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
int read(){
  int x=0,f=0;
  char ch=getchar();
  while(!isdigit(ch))f|=ch=='-',ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return f?-x:x;
}

const int N=1000005;
const int inf=1e8;

struct Edge{
  int to,nxt,val;
}edge[N<<1];
int head[N],tot;
void add(int u,int v,int w){
  edge[++tot]={v,head[u],w},head[u]=tot;
}
int dfn[N<<1],pos[N],idx;
int dep[N],wdep[N],tin[N],tout[N];
void dfs(int u,int fa){
  dfn[++idx]=u,tin[u]=idx;
  for(int i=head[u];i;i=edge[i].nxt){
    int v=edge[i].to;
    if(v==fa)continue;
    pos[(i+1)>>1]=v;
    dep[v]=dep[u]+1;
    wdep[v]=wdep[u]+edge[i].val;
    dfs(v,u);
    dfn[++idx]=u;
  }
  tout[u]=idx;
}

int n;

#define ls (u<<1)
#define rs (u<<1|1)
int W[N<<2][2],M[N<<2],LM[N<<2][2],MR[N<<2][2],LMR[N<<2][2];
int lzy[N<<2];
void pushup(int u){
  M[u]=max(M[ls],M[rs]);
  for(int k=0;k<2;k++){
    W[u][k]=max(W[ls][k],W[rs][k]);
    LM[u][k]=max(LM[ls][k],LM[rs][k]);
    MR[u][k]=max(MR[ls][k],MR[rs][k]);
    LMR[u][k]=max(LMR[ls][k],LMR[rs][k]);
    LM[u][k]=max(LM[u][k],W[ls][k]+M[rs]);
    MR[u][k]=max(MR[u][k],M[ls]+W[rs][k]);
  }
  for(int k1=0;k1<2;k1++){
    for(int k2=0;k2<2;k2++){
      ckmax(LMR[u][k1^k2],max(LM[ls][k1]+W[rs][k2],W[ls][k1]+MR[rs][k2]));
    }
  }
}
void build(int u,int l,int r){
  if(l==r){
    int k=wdep[dfn[l]];
    if(k%2==0)k=0;else k=1;
    W[u][k]=dep[dfn[l]],M[u]=-2*dep[dfn[l]];
    LM[u][k]=MR[u][k]=-dep[dfn[l]];
    W[u][k^1]=-inf,LM[u][k^1]=MR[u][k^1]=-inf;
    return;
  }
  int mid=l+r>>1;
  build(ls,l,mid),build(rs,mid+1,r);
  pushup(u);
}
void rot(int u){
  swap(W[u][0],W[u][1]);
  swap(LM[u][0],LM[u][1]);
  swap(MR[u][0],MR[u][1]);
  lzy[u]^=1; 
}
void pushdown(int u){
  if(lzy[u]){
    rot(ls),rot(rs);
    lzy[u]=0;
  }
}
void update(int u,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr){
    rot(u);return;
  }
  int mid=l+r>>1;
  pushdown(u);
  if(ql<=mid)update(ls,l,mid,ql,qr);
  if(qr>mid)update(rs,mid+1,r,ql,qr);
  pushup(u);
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<n;i++){
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    add(u,v,w),add(v,u,w);
  }
  dfs(1,0);
  build(1,1,idx);
  //cerr<<"ok!\n";
  int q=read();
  while(q--){
    int d=read();
    //printf("update %d %d\n", tin[pos[d]],tout[pos[d]]);
    update(1,1,idx,tin[pos[d]],tout[pos[d]]);
    printf("%d\n",LMR[1][0]);
  }
  return 0;
}