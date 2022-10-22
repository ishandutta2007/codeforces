#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back

using namespace std;

int t,n,a,b,p[200010],in[200010],lim,len,ls[7900010],rs[7900010],lnk1[7900010],lnk2[7900010],
head[8000010],nxt[8000010],tt[8000010],cur=0;
vector <pii> v;
struct Deque{
  const int N=7900005;
  int s,t;
  void clear(){s=t=0;}
  void push_front(int x){s=(s+N-1)%N,ls[s]=x;}
  void push_back(int x){ls[t]=x,t=(t+1)%N;}
  void pop_front(){s=(s+1)%N;}
  void pop_back(){t=(t+N-1)%N;}
  bool empty(){return s==t;}
  int front(){return ls[s];}
}q;

void Clear(vector <int> &vv)
{
  vector <int> tmp;
  tmp.swap(vv);
}

void Clear(list <int> &vv)
{
  list <int> tmp;
  tmp.swap(vv);
}

void ae(int x,int y)
{
  if(lnk1[x]==-1) lnk1[x]=y;
  else lnk2[x]=y;
}
void ae2(int x,int y)
{
  int cc=cur++;
  tt[cc]=y;
  nxt[cc]=head[x];
  head[x]=cc;
  //cout<<cc<<' '<<x<<' '<<y<<" ajsdkfjaksld\n";
}
struct hjt
{
  int n2,root;
  void initl(int N)
  {
    n2=1;while(n2<N) n2*=2;
    root=0;
    rep(i,lim) ls[i]=rs[i]=0;
  }
  int upd(int k,int lb,int ub,int to,int ty)
  {
    if(k==0) k=++len;
    else
    {
      int kk=++len;
      if(ty==0) ae(kk,k);else ae(k,kk);
      ls[kk]=ls[k];rs[kk]=rs[k];
      k=kk;
    }
    if(lb==ub)
    {
      //if(ty==1&&to==0) cout<<" ??????????????"<<' '<<k<<endl;
      if(ty==0) ae(k,in[lb]);else ae(in[lb],k);
      return k;
    }
    int mid=(lb+ub)/2;
    if(to<=mid)
    {
      ls[k]=upd(ls[k],lb,mid,to,ty);
      if(ty==0) ae(k,ls[k]);else ae(ls[k],k);
    }
    else
    {
      rs[k]=upd(rs[k],mid+1,ub,to,ty);
      if(ty==0) ae(k,rs[k]);else ae(rs[k],k);
    }
    return k;
  }
  void addEdge(int k,int lb,int ub,int tlb,int tub,int nd,int ty)
  {
    if(k==0||ub<tlb||tub<lb) return;
    if(tlb<=lb&&ub<=tub)
    {
      if(ty==0) ae2(nd,k);else ae2(k,nd);
      return;
    }
    addEdge(ls[k],lb,(lb+ub)/2,tlb,tub,nd,ty);addEdge(rs[k],(lb+ub)/2+1,ub,tlb,tub,nd,ty);
  }
}I,O;

void relax(int x,int d,int e)
{
  if(rs[x]>d)
  {
    rs[x]=d;
    if(e==0) q.push_front(x);
    else q.pb(x);
  }
}
int bfs(int x,int y)
{
  rep(i,lim) rs[i]=1e9;
  rs[x]=0;q.pb(x);
  while(!q.empty())
  {
    int f=q.front();q.pop_front();
    //cout<<f.se<<'p'<<endl;
    int e=(f<=n ? 1:0);
    if(lnk1[f]>-1) relax(lnk1[f],rs[f]+e,e);
    if(lnk2[f]>-1) relax(lnk2[f],rs[f]+e,e);
    int xx=head[f];
    while(xx>-1)
    {
      relax(tt[xx],rs[f]+e,e);
      xx=nxt[xx];
    }
  }
  return rs[y];
}

int main()
{
  cin>>t;
  rep(tn,t)
  {
    scanf("%d%d%d",&n,&a,&b);
    rep(i,n) scanf("%d",&p[i]);
    lim=n*39+6;
    rep(i,lim) lnk1[i]=lnk2[i]=-1;
    len=0;
    rep(i,n) in[i]=++len;
    I.initl(n);O.initl(n);
    v.clear();
    rep(i,n) v.pb(mpr(p[i],i));
    sort(v.begin(),v.end());reverse(v.begin(),v.end());
    
    cur=0;
    rep(i,n*2*20+3) head[i]=nxt[i]=-1;

    rep(i,v.size())
    {
      int u=v[i].se;
      //if(u==1||u==3) continue;
      I.root=I.upd(I.root,0,I.n2-1,u,0);
      O.root=O.upd(O.root,0,O.n2-1,u,1);
      int lb=max(0,u-v[i].fi),ub=min(n-1,u+v[i].fi);
      //cout<<u<<' '<<lb<<' '<<ub<<endl;
      I.addEdge(I.root,0,I.n2-1,lb,ub,in[u],0);
      O.addEdge(O.root,0,O.n2-1,lb,ub,in[u],1);
    }
    //cout<<len<<' '<<lim<<" ???????????\n";
    int ans=bfs(in[a-1],in[b-1]);
    printf("%d\n",ans);
  }
  //cout<<g[out[0]].size()<<' '<<g[14].size()<<' '<<g[13].size()<<endl;
  //cout<<g[out[0]][0]<<' '<<g[14][0]<<' '<<g[13][0]<<endl;
	return 0;
}