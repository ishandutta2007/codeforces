#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=(int)1e5+7;
int n,m;
set<pair<int,int>>g1[N];
set<pair<int,int>>g2[N];
map<int,int>sol;

void pg(){
 /** for (int i=1;i<=n;i++){
    for (auto &j:g1[i])if(sol[j.second]==i)cout<<i<<" "<<j.first<<" 1\n";
    for (auto &j:g2[i])if(sol[j.second]==i)cout<<i<<" "<<j.first<<" 2\n";
  }**/
}

void del(int x,int y,int i,int w){
  assert(w==1||w==2);
  if(w==1){
    assert(g1[x].count({y,i}));
    assert(g1[y].count({x,i}));
    g1[x].erase({y,i});
    g1[y].erase({x,i});
  }else{
    assert(g2[x].count({y,i}));
    assert(g2[y].count({x,i}));
    g2[x].erase({y,i});
    g2[y].erase({x,i});
  }
}

void add(int x,int y,int i,int w){
  assert(w==1||w==2);
  if(w==1){
    assert(!g1[x].count({y,i}));
    assert(!g1[y].count({x,i}));
    g1[x].insert({y,i});
    g1[y].insert({x,i});
  }else{
    assert(!g2[x].count({y,i}));
    assert(!g2[y].count({x,i}));
    g2[x].insert({y,i});
    g2[y].insert({x,i});
  }
}

bool deja[N];

void dfs(int a,int cur=1){
  cur=1;
  if(deja[a])return;
  //cout<<"v = "<<a<<"\n";
  deja[a]=1;
  for (auto &it:g1[a]){
    int b=it.first,i=it.second;
    //cout<<"\t\t\t\t"<<a<<" "<<b<<" : "<<i<<"\n";
    if(!sol.count(i)){
      if(cur)sol[i]=a;else sol[i]=b;
      dfs(b,cur^1);
    }
  }
  for (auto &it:g2[a]){
    int b=it.first,i=it.second;

  // cout<<"\t\t\t\t"<<a<<" "<<b<<" : "<<i<<"\n";
    if(!sol.count(i)){
      if(cur)sol[i]=a;else sol[i]=b;
      dfs(b,cur^1);
    }
  }
}

int kek[N];

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);

 // freopen ("input","r",stdin);


  vector<pair<int,int>>init;
  vector<int>ws;
  cin>>n>>m;
  int minit=m;
  for (int i=1;i<=m;i++){
    int x,y,w;
    cin>>x>>y>>w;
    kek[x]^=w;
    kek[y]^=w;
    add(x,y,i,w);
    ws.push_back(w);
    init.push_back({x,y});
  }

  int verts=0;

  for (int i=1;i<=n;i++){
    if(kek[i]&1)verts++;
  }

  queue<int>potential;
  for (int i=1;i<=n;i++){
    potential.push(i);
  }

  vector<vector<int>>lol;

  while (!potential.empty()){
    int v=potential.front();

    potential.pop();
    while ((int)g1[v].size()>=2){
      auto x=*g1[v].begin();g1[v].erase(g1[v].begin());
      auto y=*g1[v].begin();g1[v].insert(x);

      del(x.first,v,x.second,1);
      del(y.first,v,y.second,1);
      add(x.first,y.first,++m,1);

      init.push_back({x.first,y.first});
      lol.push_back({x.second,y.second,m,v,x.first,y.first});
      ws.push_back(1);

      potential.push(x.first);
      potential.push(y.first);
    }
    while ((int)g2[v].size()>=2){
      auto x=*g2[v].begin();g2[v].erase(g2[v].begin());
      auto y=*g2[v].begin();g2[v].insert(x);

      del(x.first,v,x.second,2);
      del(y.first,v,y.second,2);
      add(x.first,y.first,++m,2);

      init.push_back({x.first,y.first});
      lol.push_back({x.second,y.second,m,v,x.first,y.first});
      ws.push_back(2);

      potential.push(x.first);
      potential.push(y.first);
    }
  }


  for (int i=1;i<=n;i++){
    if((int)g1[i].size()+(int)g2[i].size()==1)
      dfs(i);
  }


  for (int i=1;i<=n;i++){
    dfs(i);
  }


  pg();

  reverse(lol.begin(),lol.end());


  for (auto &it:lol){
    int x=it[0],y=it[1],z=it[2],v=it[3],node1=it[4],node2=it[5];
    assert(sol.count(z));
    assert(sol[z]==node1||sol[z]==node2);
    if(sol[z]==node1){
      sol[x]=node1;
      sol[y]=v;
    }else{
      sol[x]=v;
      sol[y]=node2;
    }
  }

  m=minit;

  cout<<verts<<"\n";

  for (int i=1;i<=m;i++){
    int x=init[i-1].first,y=init[i-1].second;


    assert(sol.count(i));
    assert(sol[i]==x||sol[i]==y);

    /**
    if (sol[i]==x){
      cout<<x<<" "<<y<<"\n";
    }else{
      cout<<y<<" "<<x<<"\n";
    }
    continue;**/

    if (sol[i]==y){
      cout<<1;
    }else{
      cout<<2;
    }
  }
  cout<<"\n";

  //pg();cout<<"\n\n";
  return 0;
}