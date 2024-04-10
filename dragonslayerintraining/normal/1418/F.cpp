#include <cstdio>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>

using ll=long long;

std::vector<ll> factors[200005];

int main(){
  ll N,M,L,R;
  scanf("%lld %lld %lld %lld",&N,&M,&L,&R);
  for(ll i=1;i<=200000;i++){
    for(ll j=i;j<=200000;j+=i){
      factors[j].push_back(i);
    }
  }
  std::map<ll,ll> freq;
  ll lptr=M+1,rptr=M;
  auto add=[&](ll x,ll v){
    for(ll a:factors[x]){
      freq[a]+=v;
      if(freq[a]==0){
	freq.erase(a);
      }
    }
  };
  for(ll x1=1;x1<=N;x1++){
    ll y1low=std::max<ll>(1,(L+x1-1)/x1),y1high=std::min<ll>(M,R/x1);
    if(y1low>y1high){
      printf("-1\n");
      continue;
    }
    while(lptr>y1low) add(--lptr,1);
    while(rptr<y1high) add(++rptr,1);
    while(lptr<y1low) add(lptr++,-1);
    while(rptr>y1high) add(rptr--,-1);
    auto solve=[&](){
      for(ll a:factors[x1]){
	auto it=freq.upper_bound(a);
	if(it!=freq.end()){
	  ll b=it->first;
	  if(x1/a*b<=N){
	    ll y1=y1high/b*b;
	    printf("%lld %lld %lld %lld\n",x1,y1,x1/a*b,y1/b*a);
	    return;
	  }
	}
      }
      printf("-1\n");
    };
    solve();
  }

}