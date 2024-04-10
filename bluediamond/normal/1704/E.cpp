#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int M=998244353;
int add(int a,int b){
  a+=b;
  if(a>=M)return a-M;
  if(a<0)return a+M;
  return a;
}
int mul(int a,int b){
  return a*(ll)b%M;
}
int add(int a,int b,int c){
  return add(add(a,b),c);
}
int mul(int a,int b,int c){
  return mul(mul(a,b),c);
}
int add(int a,int b,int c,int d){
  return add(add(a,b,c),d);
}
int mul(int a,int b,int c,int d){
  return mul(mul(a,b,c),d);
}
int add(int a,int b,int c,int d,int e){
  return add(add(a,b,c,d),e);
}
int mul(int a,int b,int c,int d,int e){
  return mul(mul(a,b,c,d),e);
}
int add(int a,int b,int c,int d,int e,int f){
  return add(add(a,b,c,d,e),f);
}
int mul(int a,int b,int c,int d,int e,int f){
  return mul(mul(a,b,c,d,e),f);
}
int add(int a,int b,int c,int d,int e,int f,int g){
  return add(add(a,b,c,d,e,f),g);
}
int mul(int a,int b,int c,int d,int e,int f,int g){
  return mul(mul(a,b,c,d,e,f),g);
}
int add(int a,int b,int c,int d,int e,int f,int g,int h){
  return add(add(a,b,c,d,e,f,g),h);
}
int mul(int a,int b,int c,int d,int e,int f,int g,int h){
  return mul(mul(a,b,c,d,e,f,g),h);
}
int pw(int a,int b){
  int r=1;
  while(b){
    if(b&1)r=mul(r,a);
    a=mul(a,a);
    b/=2;
  }
  return r;
}
int dv(int a,int b){
  return mul(a,pw(b,M-2));
}
void addup(int &a,int b){
  a=add(a,b);
}
void mulup(int &a,int b){
  a=mul(a,b);
}
void dvup(int &a,int b){
  a=dv(a,b);
}
const int N=1000+7;
int n,m,init[N],dp[N];
bool vis[N];
vector<int> g[N],order,rev_order;

void place(int a){
  if(vis[a])return;
  vis[a]=1;
  for(auto&b:g[a]){
    place(b);
  }
  order.push_back(a);
}

void simul() {
  for(auto&a:rev_order){
    if(init[a]){
      for(auto&b:g[a]){
        init[b]++;
      }
      init[a]--;
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt","r",stdin);
#endif // ONLINE_JUDGE

  int tests;
  cin>>tests;
  for(int tc=1;tc<=tests;tc++){
    cin>>n>>m;
    order.clear();
    for(int i=1;i<=n;i++){
      cin>>init[i];
      g[i].clear();
      vis[i]=0;
    }
    for(int i=1;i<=m;i++){
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
    }
    for(int i=1;i<=n;i++)place(i);
    rev_order=order;
    reverse(order.begin(), order.end());


    int sol=-1;
    for(int iter=0;iter<=n;iter++){
      if(*max_element(init+1,init+n+1)==0){
        sol=iter;
        break;
      }
      simul();
    }
    if(sol!=-1){
      cout<<sol<<"\n";
      continue;
    }
    for(auto&v:rev_order){
      if(v==rev_order[0]){
        dp[v]=1;
        continue;
      }
      dp[v]=0;
      for(auto&oth:g[v]){
        addup(dp[v],dp[oth]);
      }
    }
    sol=n+1;
    for(int i=1;i<=n;i++){
      addup(sol,mul(init[i]%M,dp[i]));
    }
    cout<<sol<<"\n";
  }

}