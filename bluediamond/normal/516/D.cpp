#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long long ll;
typedef long double ld;

const int N=(int)1e5+7;
int n,par[N];
ll dis[N];
vector<pair<int,int>>gg[N];
vector<int>g[N];

void build(int a){
  for (auto &it:gg[a]){
    int b=it.first,c=it.second;
    if(dis[b]==-1){
      par[b]=a;
      dis[b]=c+dis[a];
      build(b);
    }
  }
}


int getf(int a){
  for (int i=1;i<=n;i++)dis[i]=-1;
  dis[a]=0;
  build(a);
  for (int i=1;i<=n;i++)if(dis[i]>dis[a])a=i;
  return a;
}

ll getmx(int a){
  ll sol=dis[a];
  for (auto &b:g[a]){
    sol=max(sol,getmx(b));
  }
  return sol;
}


void bu(int a,ll cur){
 // cout<<a<<" ";
  dis[a]=cur;
  for (auto &it:gg[a]){
    if(it.first==par[a])continue;
    bu(it.first,cur+it.second);
    //cout<<a<<" -> "<<it.first<<"\n";
  }
}

vector<int>order;
vector<int>verts;

bool need;
ll lim;
int gulag[N];

void dfs(int a){
  if(need)order.push_back(a);
  gulag[a]=0;
  verts.push_back(a);
  int lgood=(int)verts.size()-1;
  int l=0,r=(int)verts.size()-1;
  while(l<=r){
    int m=(l+r)/2;
    int x=verts[m];
    if(abs(dis[x]-dis[a])<=lim)lgood=m,r=m-1;
    else l=m+1;
  }
  gulag[par[verts[lgood]]]--;
  gulag[a]++;
  for (auto &b:g[a]){
    dfs(b);
  }
  verts.pop_back();
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
  for (int i=1;i<n;i++){
    int x,y,w;
    cin>>x>>y>>w;

    gg[x].push_back({y,w});
    gg[y].push_back({x,w});
  }

  int a=getf(1);
  int b=getf(a);

  ll total=dis[b];

  function<ll(int)>eval=[&](int vert){
    return max(total-dis[vert],dis[vert]);
  };

  while(b!=a&&eval(par[b])<eval(b))b=par[b];


  int root=b;

  par[root]=0;
  getf(root);

  for (int i=1;i<=n;i++){
    for (auto &it:gg[i]){
      if(it.first!=par[i])g[i].push_back(it.first);
    }
  }


  ll mx1=0,mx2=0;

  vector<ll>memo(n+1);

  for (auto &i:g[root]){
    ll cur=getmx(i);
    //cout<<"\t\t\t"<<i << " : "<<cur<<"\n";
    memo[i]=cur;
    if(cur>mx1){
      mx2=mx1;
      mx1=cur;
    }else{
      mx2=max(mx2,cur);
    }
  }


  for (auto &it:gg[root]){
  //  cout<<"K "<< it.second+((mx1==memo[it.first])?mx2:mx1) <<" verts : ";
    bu(it.first,it.second+((mx1==memo[it.first])?mx2:mx1));
  //  cout<<"\n";
  }

//  cout<<" root = " <<root<<"\n";
  dis[root]=mx1;

  /**
  cout<<"root = "<<root<<"\n";

  for (int i=1;i<=n;i++){
    cout<<i<<" : "<<dis[i]<<"\n";
  }

**/
  for (int i=1;i<=n;i++){
    if(i!=root){
      assert(dis[par[i]]<=dis[i]);
  //    if(dis[par[i]]>dis[i]){
  //      cout<<"bad : "<<i<<"\n";
  //    }
    }
  }

  int q;
  cin>>q;
need=1;

  while(q--){
    cin>>lim;
    dfs(root);
    if(need)reverse(order.begin(),order.end());
    need=0;
    for (auto &x:order){
      for (auto &y:g[x])gulag[x]+=gulag[y];
    }
    int seniorita=0;
    for (int x=1;x<=n;x++){
      seniorita=max(seniorita,gulag[x]);
      gulag[x]=0;
    }

    cout<<seniorita<<"\n";
  }



  return 0;
}