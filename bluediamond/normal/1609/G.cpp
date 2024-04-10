#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=100+7;
const int M=(int)1e5+7;
const ll INF=(ll)1e18;
int n,m,q;
ll a[N],b[M];

struct node{
  ll mn;
  ll mx;
  ll sum;
  ll sol;
  int len;
};

node operator + (node a, node b){
  ll mn=min(a.mn,b.mn);
  ll mx=max(a.mx,b.mx);
  ll sum=a.sum+b.sum;
  ll sol=a.sol+b.sol+a.sum*b.len;
  int len=a.len+b.len;
  return {mn,mx,sum,sol,len};
}

ll lazy[4*M];
node t[4*M];


void build(int v,int tl,int tr){
  t[v].len=tr-tl+1;
  if (tl<tr){
    int tm=(tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
  }
}

void add(int v,int tl,int tr,int l,int r,ll x){
  if (lazy[v]){
    t[v].mn+=lazy[v];
    t[v].mx+=lazy[v];
    t[v].sum+=lazy[v]*(tr-tl+1);
    t[v].sol+=lazy[v]*(tr-tl+1)*(tr-tl+2)/2; /// potential danger?

    if (tl<tr){
      lazy[2*v]+=lazy[v];
      lazy[2*v+1]+=lazy[v];
    }
    lazy[v]=0;
  }
  if (tr<l||r<tl)return;
  if (l<=tl&&tr<=r) {
    lazy[v]=x;
    t[v].mn+=lazy[v];
    t[v].mx+=lazy[v];
    t[v].sum+=lazy[v]*(tr-tl+1);
    t[v].sol+=lazy[v]*(tr-tl+1)*(tr-tl+2)/2; /// potential danger?

    if (tl<tr){
      lazy[2*v]+=lazy[v];
      lazy[2*v+1]+=lazy[v];
    }
    lazy[v]=0;

    return;
  }
  int tm=(tl+tr)/2;
  add(2*v,tl,tm,l,r,x);
  add(2*v+1,tm+1,tr,l,r,x);
  t[v]=t[2*v]+t[2*v+1];
}

node none={+INF,-INF,0,0,0};

node get(int v,int tl,int tr,int l,int r){
  if (lazy[v]){
    t[v].mn+=lazy[v];
    t[v].mx+=lazy[v];
    t[v].sum+=lazy[v]*(tr-tl+1);
    t[v].sol+=lazy[v]*(tr-tl+1)*(tr-tl+2)/2; /// potential danger?

    if (tl<tr){
      lazy[2*v]+=lazy[v];
      lazy[2*v+1]+=lazy[v];
    }
    lazy[v]=0;
  }
  if (tr<l||r<tl)return none;
  if (l<=tl&&tr<=r){
    return t[v];
  }
  int tm=(tl+tr)/2;
  return get(2*v,tl,tm,l,r)+get(2*v+1,tm+1,tr,l,r);
}

void add(int l,int r,ll x){
  add(1,1,m,l,r,x);
}

node get(int l,int r){
  return get(1,1,m,l,r);
}

int kek=-1;

void fnd(int v,int tl,int tr, ll smaller){
  if(kek!=-1)return;
  if (lazy[v]){
    t[v].mn+=lazy[v];
    t[v].mx+=lazy[v];
    t[v].sum+=lazy[v]*(tr-tl+1);
    t[v].sol+=lazy[v]*(tr-tl+1)*(tr-tl+2)/2; /// potential danger?

    if (tl<tr){
      lazy[2*v]+=lazy[v];
      lazy[2*v+1]+=lazy[v];
    }
    lazy[v]=0;
  }
  if (t[v].mn>=smaller)return;
  if(tl==tr){
    kek=tl;
    return;
  }
  int tm=(tl+tr)/2;
  fnd(2*v+1,tm+1,tr,smaller);
  if (kek==-1)fnd(2*v,tl,tm,smaller);
}

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);



  cin>>n>>m>>q;



  for (int i=1;i<=n;i++)cin>>a[i];
  for (int i=1;i<=m;i++)cin>>b[i];


  for (int i=0;i<n;i++)a[i]=a[i+1]-a[i];
  for (int i=0;i<m;i++)b[i]=b[i+1]-b[i];


  a[n]=INF;

  n--;
  m--;


  build(1,1,m);

  for (int i=1;i<=m;i++)add(i,i,b[i]);



  for (int iq=1;iq<=q;iq++){
    int type,pos;
    ll x;
    cin>>type>>pos>>x;
    if (type==1){
      pos=n+1-pos;
      for (int i=pos;i<=n;i++)a[i]+=x;
    }else{
      pos=m+1-pos;
      add(pos,m,x);
      b[0]+=(pos==0)*x;
    }

    ll cur=a[0]+b[0],sum=cur;

    int j=1;
    for (int i=1;i<=n+1;i++){
      int ff=j;
      ll cur2=0,init=sum,initcur=cur;

      kek=-1;

      fnd(1,1,m,a[i]);

      if(kek!=-1&&kek>=j){
        auto val=get(j,kek);
        sum+=val.sol+initcur*(kek-j+1);
        cur+=val.sum;
        j=kek+1;
      }
      if(i<=n){
        cur+=a[i];
        sum+=cur;
      }
    }
    cout<<sum<<"\n";

  }

  return 0;
}