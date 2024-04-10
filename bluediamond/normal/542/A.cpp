#include <bits/stdc++.h>

using namespace std;

bool home = 1;
///#define int ll

typedef long long ll;
typedef long double ld;

#define int ll

const int N=(int)2e5+7;
int n,m,print,si,sj;

struct S{
  int l,r,i;
};

bool operator < (S a,S b){
  if(a.l!=b.l) return a.l<b.l;
  return a.r>b.r;
}

struct T{
  int l,r,c,i;
};

bool operator < (T a,T b){
  if(a.l!=b.l) return a.l<b.l;
  return a.r<b.r;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ///
  }

  cin>>n>>m;
  vector<S>segs;
  for (int i=1;i<=n;i++){
    int l,r;
    cin>>l>>r;
    segs.push_back({l,r,i});
  }
  {
    sort(segs.begin(),segs.end());
    vector<S> nsegs;
    for (auto &it:segs){
      if(nsegs.empty()||it.r>nsegs.back().r)nsegs.push_back(it);
    }
    segs=nsegs;
    for (int i=1;i<(int)segs.size();i++){
      assert(segs[i-1].l<segs[i].l);
      assert(segs[i-1].r<segs[i].r);
    }
  }
  vector<T> ofs;

  for (int i=1;i<=m;i++){
    int l,r,c;
    cin>>l>>r>>c;
    ofs.push_back({l,r,c,i});
  }
  sort(ofs.begin(),ofs.end());

  vector<int>inds(4*((int)segs.size()+7));

  function<void(int,int,int)>build=[&](int v,int tl,int tr){
    if(tl==tr) inds[v]=tl;
    else {
      int tm=(tl+tr)/2;
      build(2*v,tl,tm);
      build(2*v+1,tm+1,tr);
      if (segs[inds[2*v]].r-segs[inds[2*v]].l>segs[inds[2*v+1]].r-segs[inds[2*v+1]].l)inds[v]=inds[2*v];
      else inds[v]=inds[2*v+1];
    }
  };

  function<int(int,int,int,int,int)>get=[&](int v,int tl,int tr,int l,int r){
    if(tr<l||r<tl)assert(0);
    if(l<=tl&&tr<=r)return inds[v];
    int tm=(tl+tr)/2;
    if(r<=tm)return get(2*v,tl,tm,l,r);
    if(l>=tm+1)return get(2*v+1,tm+1,tr,l,r);
    int ff=get(2*v,tl,tm,l,r),ss=get(2*v+1,tm+1,tr,l,r);
    if(segs[ff].r-segs[ff].l>segs[ss].r-segs[ss].l)return ff;
    return ss;
  };

  build(1,0,(int)segs.size()-1);

  vector<int>guy((int)segs.size());
  for (int i=(int)segs.size()-1;i>=0;i--){
    guy[i]=i;
    if(i+1<(int)segs.size()&&segs[guy[i+1]].l<segs[guy[i]].l)guy[i]=guy[i+1];
  }

  int fbig=0,bigr=-1;

  for (auto &it:ofs){
    int who=-1,best=0;
    while (fbig<(int)segs.size()&&segs[fbig].l<=it.l)if(bigr==-1||segs[fbig].r>segs[bigr].r)bigr=fbig,fbig++;
    if (bigr!=-1) {
      auto sg=segs[bigr];
      int cur=min(sg.r,it.r)-it.l;
      if (cur>best){
        best=cur;
        who=sg.i;
      }
    }
    int sbig=(int)segs.size();
    {
      int l=fbig,r=(int)segs.size()-1;
      while(l<=r){
        int m=(l+r)/2;
        if (segs[m].r>it.r){
          sbig=m;
          r=m-1;
        }else {
          l=m+1;
        }
      }
    }
    if(fbig<sbig){
      int j=get(1,0,(int)segs.size()-1,fbig,sbig-1);
      auto sg=segs[j];
      int cur=sg.r-sg.l;
      if (cur>best){
        best=cur;
        who=sg.i;
      }
    }
    if(sbig<(int)segs.size()){
      int j=guy[sbig];
      auto sg=segs[j];
      int cur=it.r-sg.l;
      if (cur>best){
        best=cur;
        who=sg.i;
      }
    }
    if(it.c*best>print){
      print=it.c*best;
      si=who;
      sj=it.i;
    }
  }
  cout<<print<<"\n";
  if (print){
    cout<<si<<" "<<sj<<"\n";
  }

  return 0;
}