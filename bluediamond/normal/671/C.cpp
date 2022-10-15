#include <bits/stdc++.h>

using namespace std;

bool home=1;
typedef long long ll;


const int N=(int)2e5+7;
int n,a[N],emax;
ll cnt[N];

int pref[N],suf[N];

struct T{
  int mn;
  int mx;
  int smn;
  int smx;
  T(int mn,int mx,int smn,int smx):mn(mn),mx(mx),smn(smn),smx(smx) {
  }
  T() {
    mn=smn=N;
    mx=smx=-N;
  }
};

T operator + (T a, T b){

  if (a.mn==N&&b.mn==N)return {N,-N,N,-N};
  int mn=min(a.mn,b.mn);
  int mx=max(a.mx,b.mx);
  int smn=N,smx=-N;

  if (a.mn>mn) smn=min(smn,a.mn);
  if (a.smn>mn) smn=min(smn,a.smn);
  if (b.mn>mn) smn=min(smn,b.mn);
  if (b.smn>mn) smn=min(smn,b.smn);


  if (a.mx<mx) smx=max(smx,a.mx);
  if (a.smx<mx) smx=max(smx,a.smx);
  if (b.mx<mx) smx=max(smx,b.mx);
  if (b.smx<mx) smx=max(smx,b.smx);


  return {mn,mx,smn,smx};
}

T kek[N];

int rmin[N];



ll sum[4*N];
int mx[4*N];
int lazy[4*N];

void push(int v,int tl,int tr){
  if (!lazy[v])return;
  sum[v]=(ll)lazy[v]*(tr-tl+1);
  mx[v]=lazy[v];
  if (tl<tr){
    lazy[2*v]=lazy[v];
    lazy[2*v+1]=lazy[v];
  }
  lazy[v]=0;
}

void force(int v,int tl,int tr,int l,int r,int x){
  push(v,tl,tr);
  if (tr<l||r<tl)return;
  if (l<=tl&&tr<=r){
    lazy[v]=x;
    push(v,tl,tr);
    return;
  }
  int tm=(tl+tr)/2;
  force(2*v,tl,tm,l,r,x);
  force(2*v+1,tm+1,tr,l,r,x);
  sum[v]=sum[2*v]+sum[2*v+1];
  mx[v]=max(mx[2*v],mx[2*v+1]);
}

ll getsum(int v,int tl,int tr,int l,int r) {
  push(v,tl,tr);
  if (tr<l||r<tl)return 0;
  if (l<=tl&&tr<=r)return sum[v];
  int tm=(tl+tr)/2;
  return getsum(2*v,tl,tm,l,r)+getsum(2*v+1,tm+1,tr,l,r);
}

int getmx(int v,int tl,int tr,int l,int r) {
  push(v,tl,tr);
  if (tr<l||r<tl)return 0;
  if (l<=tl&&tr<=r)return mx[v];
  int tm=(tl+tr)/2;
  return max(getmx(2*v,tl,tm,l,r),getmx(2*v+1,tm+1,tr,l,r));
}


void force(int l,int r,int x){
  force(1,1,n,l,r,x);
}

ll getsum(int l,int r){
  return getsum(1,1,n,l,r);
}

int getmx(int l,int r){
  return getmx(1,1,n,l,r);
}

int last=-1;

void fnd(int v,int tl,int tr,int limit,int x){
  push(v,tl,tr);

  if (last!=-1)return;
  if (mx[v]<x)return;
  if (tr<limit)return;

  if (tl==tr){
    last=tl;
    return;
  }

  int tm=(tl+tr)/2;
  fnd(2*v,tl,tm,limit,x);
  fnd(2*v+1,tm+1,tr,limit,x);
}

void maxegal(int l,int r,int x){
  last=-1;
  fnd(1,1,n,l,x);

  last--;



  last=min(last,r);
  if (l<=last){
    force(l,last,x);
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin>>n;

  for (int i=1;i<=n;i++){
    cin>>a[i];
    emax=max(emax,a[i]);
    kek[a[i]]=kek[a[i]]+T{i,i,N,-N};
  }
  for (int i=emax;i>=1;i--) {
    for (int j=2*i;j<=emax;j+=i){
      kek[i]=kek[i]+kek[j];
    }
  }

  for (int i=1;i<=emax;i++) {
    if (kek[i].smn<=n)pref[kek[i].smn]=max(pref[kek[i].smn],i);
    if (kek[i].smx>=1){
      suf[kek[i].smx]=max(suf[kek[i].smx],i);
    }
  }


  for (int i=1;i<=n;i++)pref[i]=max(pref[i-1],pref[i]);
  for (int i=n;i>=1;i--)suf[i]=max(suf[i+1],suf[i]);

  for (int i=1;i<=n;i++)rmin[i]=i,force(i,i,i);


  for (int g=emax;g>=0;g--){
    int last=0,first=n+1,low=1,high=n;
    while (low<=high){
      int mid=(low+high)/2;
      if (pref[mid-1]<=g){
        last=mid;
        low=mid+1;
      }else{
        high=mid-1;
      }
    }
    low=1,high=n;
    while (low<=high){
      int mid=(low+high)/2;
      if (suf[mid+1]<=g){
        first=mid;
        high=mid-1;
      }else{
        low=mid+1;
      }
    }
    maxegal(1,n,first);
    cnt[g]=(ll)(n+1)*(last)-getsum(1,last);
    maxegal(kek[g].mn+1,n,kek[g].mx);
  }
  ll sol=0;
  for (int i=1;i<=emax;i++){
    sol+=(ll)i*(cnt[i]-cnt[i-1]);
  }
  cout<<sol<<"\n";

  return 0;
}