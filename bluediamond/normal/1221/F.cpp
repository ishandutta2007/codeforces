#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long long ll;

struct Pt {
  int x,y,c;
  int mn;
  int mx;
};

bool operator < (Pt a,Pt b) {
  return a.mn<b.mn;
}

const int N=(int)5e5+7;
int dim;
Pt pts[N];
pair<ll,int>t[4*N];
ll lazy[4*N];

void build(int v,int tl,int tr){
  if(tl==tr){
    t[v]={0,tl};
  }else{
    int tm=(tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    t[v]=max(t[2*v],t[2*v+1]);
  }
}

void push(int v,int tl,int tr){
  if(lazy[v]){
    t[v].first+=lazy[v];
    if(tl<tr){
      lazy[2*v]+=lazy[v];
      lazy[2*v+1]+=lazy[v];
    }
    lazy[v]=0;
  }
}

void add(int v,int tl,int tr,int l,int r,ll x){
  push(v,tl,tr);
  if(tr<l||r<tl) return;
  if(l<=tl&&tr<=r){
    lazy[v]+=x;
    push(v,tl,tr);
    return;
  }
  int tm=(tl+tr)/2;
  add(2*v,tl,tm,l,r,x);
  add(2*v+1,tm+1,tr,l,r,x);
  t[v]=max(t[2*v],t[2*v+1]);
}

pair<ll, int> get(int v,int tl,int tr,int l, int r){
  push(v,tl,tr);
  if(tr<l||r<tl) return make_pair(-(ll)1e18,0);
  if(l<=tl&&tr<=r) return t[v];
  int tm=(tl+tr)/2;
  return max(get(2*v,tl,tm,l,r),get(2*v+1,tm+1,tr,l,r));
}

void add(int l,int r,ll x){
  add(1,0,dim-1,l,r,x);
}

pair<ll,int> get(int l,int r){
  return get(1,0,dim-1,l,r);
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif


  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0);
    cin.tie(0);
  }

  int n;
  cin>>n;
  set<int> smx;
  for(int i=1; i<=n; i++) {
    cin>>pts[i].x>>pts[i].y>>pts[i].c;
    pts[i].mn=min(pts[i].x,pts[i].y);
    pts[i].mx=max(pts[i].x,pts[i].y);
    smx.insert(pts[i].mx);
  }
  sort(pts+1,pts+n+1);
  vector<int> mx;
  vector<ll> smaller;
  for(auto&it:smx) {
    mx.push_back(it);
    smaller.push_back(0);
  }
  int sz=(int)mx.size();
  function<int(int)>fnd=[&](int value) {
    int pos=sz;
    int l=0,r=sz-1;
    while(l<=r) {
      int m=(l+r)/2;
      if(value<=mx[m]) {
        pos=m;
        r=m-1;
      } else {
        l=m+1;
      }
    }
    return pos;
  };
  dim=sz;
  build(1,0,dim-1);
  for(int i=0;i<dim;i++){
    add(i,i,-mx[i]);
  }

  ll sol=0;
  int ff=(int)2e9,ss=(int)2e9;
  int position=n;
  while(position>=1) {

    int F=position;

    while(F-1>=1&&pts[F-1].mn==pts[F].mn) {
      F--;
    }

    int mn=pts[F].mn;

    for(int i=F; i<=position; i++) {
      int pos=fnd(pts[i].mx);
      if(pos<sz){
        add(pos,sz-1,pts[i].c);
      }
    }

    int pos=fnd(mn);
/*
    for(int j=pos; j<sz; j++) {

      ll current=smaller[j]-mx[j];
      if(current+mn>sol) {
        sol=current+mn;
        ff=mn;
        ss=mx[j];
      }

    }
*/
    if(pos<sz){
      auto it=get(pos,sz-1);
      ll current=it.first;
      if(current+mn>sol) {
        sol=current+mn;
        ff=mn;
        ss=mx[it.second];
      }

    }

    position=F-1;
  }
  cout<<sol<<"\n";
  cout<<ff<<" "<<ff<<" ";
  cout<<ss<<" "<<ss<<"\n";

  return 0;
}