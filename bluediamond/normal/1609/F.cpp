#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

int cntbits(ll x){
  int sol=0;
  while (x){
    sol++;
    x-=x&(-x);
  }
  return sol;
}

const int N=(int)1e6+7;
int n,l1[N],r1[N],l2[N],r2[N],cnt[N],cur[N];
ll a[N];
vector<int> who[77];

struct rect{
  int x1,x2,y1,y2;
};

struct event{
  int type;
  int l,r;
};

vector<event> events[N];

struct node{
  int c0,c1,c2;
};

node operator+(node a,node b){
  a.c0+=b.c0;
  a.c1+=b.c1;
  a.c2+=b.c2;
  return a;
}

int lazy[4*N];
node t[4*N];

void push(int v,int tl,int tr){
  if (lazy[v]){
    if(tl<tr)lazy[2*v]+=lazy[v],lazy[2*v+1]+=lazy[v];
    if(lazy[v]==-2)t[v].c0=t[v].c2,t[v].c1=t[v].c2=0;
    if(lazy[v]==2)t[v].c2=t[v].c0,t[v].c0=t[v].c1=0;
    if(lazy[v]==1)t[v].c2=t[v].c1,t[v].c1=t[v].c0,t[v].c0=0;
    if(lazy[v]==-1)t[v].c0=t[v].c1,t[v].c1=t[v].c2,t[v].c2=0;
    lazy[v]=0;
  }
}

void add(int v,int tl,int tr,int l,int r,int x){
  push(v,tl,tr);
  if(tr<l||r<tl)return;
  if(l<=tl&&tr<=r){
    lazy[v]+=x;
    push(v,tl,tr);
    return;
  }
  int tm=(tl+tr)/2;
  add(2*v,tl,tm,l,r,x);
  add(2*v+1,tm+1,tr,l,r,x);
  t[v]=t[2*v]+t[2*v+1];
}

void build(int v,int tl,int tr){
  t[v].c0=tr-tl+1;
  if(tl<tr){
    int tm=(tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
  }
}


signed main(){
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input","r",stdin);

  cin>>n;
  build(1,1,n);
  vector<int>s1,s2;
  for (int i=1;i<=n;i++){
    cin>>a[i];
    cnt[i]=cntbits(a[i]);
    who[cnt[i]].push_back(i);
    while (!s1.empty()&&a[i]>=a[s1.back()])s1.pop_back();
    while (!s2.empty()&&a[i]<=a[s2.back()])s2.pop_back();
    if(s1.empty())l1[i]=1;else l1[i]=s1.back()+1;
    if(s2.empty())l2[i]=1;else l2[i]=s2.back()+1;
    s1.push_back(i);
    s2.push_back(i);
  }

  s1.clear();
  s2.clear();
  for (int i=n;i>=1;i--){
    cnt[i]=cntbits(a[i]);
    while (!s1.empty()&&a[i]>a[s1.back()])s1.pop_back();
    while (!s2.empty()&&a[i]<a[s2.back()])s2.pop_back();
    if(s1.empty())r1[i]=n;else r1[i]=s1.back()-1;
    if(s2.empty())r2[i]=n;else r2[i]=s2.back()-1;
    s1.push_back(i);
    s2.push_back(i);
  }

  ll sol=0;
  for (int bit=0;bit<70;bit++){
    if (who[bit].empty())continue;

    for (int i=1;i<=n+1;i++)events[i].clear(),cur[i]=0;

    vector<rect>rects;
    for (auto &i:who[bit]){
      rects.push_back({l1[i],i,i,r1[i]});
      rects.push_back({l2[i],i,i,r2[i]});
    }

    for (auto &rect:rects){
      int x1=rect.x1,y1=rect.y1;
      int x2=rect.x2,y2=rect.y2;
      events[x1].push_back({+1,y1,y2});
      events[x2+1].push_back({-1,y1,y2});
    }

    int last=0;

    for (int i=1;i<=n+1;i++){
      if (!events[i].empty()){
        for (auto &e:events[i]){
          int adding=e.type;
          int l=e.l,r=e.r;
          add(1,1,n,l,r,adding);
        }
      }

      sol+=t[1].c2;
    }

  }
  cout<<sol<<"\n";


  return 0;
}