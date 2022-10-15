#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const int N=(int)2e5+7;
const ll INF=(ll)1e18+7;
int n;
ll a[N];
ll s[N];
ll f[N];
ll v[N];
vector<int> inds;

struct P{
  ll x;
  ll y;
} pts[N];

ld split(P a,P b){
  ld a1=a.x,a2=b.x;
  ld b1=a.y,b2=b.y;
  assert(a.x!=b.x);
  return (b2-b1)/(a1-a2);
}

bool isdel(P p1,P p2,P p3){
  return split(p2,p3)>split(p1,p2);
}

#define upd(i) {if(inds[i]<r)big=max(big,v[inds[i]]-inds[i]*s[r]);}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input.txt", "r", stdin);

  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    s[i]=s[i-1]+a[i];
    f[i]=f[i-1]+a[i]*i;
    v[i]=v[i-1]+s[i-1];
  }

  for(int i=0;i<=n;i++){
    pts[i]={-i,v[i]};
  }
  for(int i=0;i<=n;i++){
    while((int)inds.size()>=2&&isdel(pts[inds[(int)inds.size()-2]],pts[inds[(int)inds.size()-1]],pts[i])) {
      inds.pop_back();
    }
    inds.push_back(i);
  }
  vector<ld> splits;
  splits.push_back(1e18);
  for(int i=0;i<(int)inds.size()-1;i++){
    splits.push_back(split(pts[inds[i]],pts[inds[i+1]]));
  }
  splits.push_back(-1e18);


  assert((int)splits.size()==1+(int)inds.size());
  assert(!inds.empty());

  int pt=0;
  ll bestprint=0;
  for(int r=1;r<=n;r++){
    ll big=-INF;

    int sol=-1,low=0,high=(int)inds.size()-1;
    while(low<=high){
      int i=(low+high)/2;
      if(splits[i+1]<=s[r]){
        sol=i;
        high=i-1;
      }else{
        low=i+1;
      }
    }

    if(sol!=-1){
      upd(sol);
    }

    while(pt+1<(int)inds.size()&&inds[pt+1]<r) pt++;
    if(inds[pt]<r) {
      upd(pt);
    }

    bestprint=max(bestprint,big+f[r]);
  }

  cout<<bestprint<<"\n";

  return 0;
}