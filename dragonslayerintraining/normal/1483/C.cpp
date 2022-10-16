#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using ll = long long;
const int INF=1e9+7;

int N;
int hs[300005];
int bs[300005];

int ls[300005];
int rs[300005];

ll st[600005];

void pull(int i){
  st[i]=std::max(st[i<<1],st[i<<1|1]);
}

void update(int i,ll v){
  for(st[i+=N]=v;i>0;i>>=1){
    pull(i>>1);
  }
}

ll query(int l,int r){
  ll res=-INF;
  for(l+=N,r+=N;l<r;l>>=1,r>>=1){
    if(l&1) res=std::max(res,st[l++]);
    if(r&1) res=std::max(res,st[--r]);
  }
  return res;
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&hs[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&bs[i]);
  }
  for(int i=0;i<N;i++){
    int k=i-1;
    while(k>=0&&hs[k]>hs[i]){
      k=ls[k];
    }
    ls[i]=k;
  }
  for(int i=N-1;i>=0;i--){
    int k=i+1;
    while(k<N&&hs[k]>hs[i]){
      k=rs[k];
    }
    rs[i]=k;
  }
  std::multiset<ll> set;
  update(0,0);
  std::vector<std::vector<ll>> expire(N+1);
  for(int i=0;i<N;i++){
    ll val=query(ls[i]+1,i+1)+bs[i];
    set.insert(val);
    expire[rs[i]].push_back(val);
    for(ll v:expire[i]){
      set.erase(set.find(v));
    }
    update(i+1,*set.rbegin());
  }
  printf("%lld\n",*set.rbegin());
}