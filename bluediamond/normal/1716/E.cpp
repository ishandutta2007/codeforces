#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct T{
  vector<ll> sol;
  vector<ll> pref;
  vector<ll> suf;
  ll sum;
};

T solve(int n,vector<ll> v) {
  if (n==0)return {{max(v[0],0LL)},{max(v[0],0LL)},{max(v[0],0LL)},v[0]};
  vector<ll> j1(v.begin(),v.begin()+(1<<(n-1)));
  vector<ll> j2(v.begin()+(1<<(n-1)),v.end());
  ll sum1=0,sum2=0;
  vector<ll> sol1,pref1,suf1,sol2,pref2,suf2,sol((1<<n),0LL),pref((1<<n),0LL),suf((1<<n),0LL);
  T it=solve(n-1,j1);
  sol1=it.sol;
  pref1=it.pref;
  suf1=it.suf;
  sum1=it.sum;
  it=solve(n-1,j2);
  sol2=it.sol;
  pref2=it.pref;
  suf2=it.suf;
  sum2=it.sum;
  for (int m=0;m<(1<<n);m++){
    if(m==(1<<(n-1))) swap(sol1,sol2), swap(pref1,pref2), swap(suf1,suf2),swap(sum1,sum2);
    int mask=(m|(1<<(n-1)))-(1<<(n-1));
    sol[m]=max({sol1[mask],sol2[mask],suf1[mask]+pref2[mask]});
    pref[m]=max({pref1[mask],sum1+pref2[mask]});
    suf[m]=max({suf2[mask],sum2+suf1[mask]});
  }
  return {sol,pref,suf,sum1+sum2};
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n,q,mask=0,k;
  cin>>n;
  vector<ll> a((1<<n)),sol;
  for(auto&x:a){
    cin>>x;
  }
  sol=solve(n,a).sol;
  cin>>q;
  for(int iq=1;iq<=q;iq++) {
    cin>>k;
    mask^=(1<<k);
    cout<<sol[mask]<<"\n";
  }

}