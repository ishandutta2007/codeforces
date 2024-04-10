#include <bits/stdc++.h>

bool home=1;

using namespace std;

typedef long long ll;
const int N=(int)2e5+7;
int n;
int degs[N];
int parof[N];
bool dp[N][2];
vector<int> g[N];

void buildg(int a,int p=-1){
  parof[a]=p;
  degs[a]=(int)g[a].size();
  {
    vector<int> kids;
    for(auto&b:g[a]){
      if(b==p) continue;
      buildg(b,a);

      kids.push_back(b);
    }
    g[a]=kids;
  }
}

void solve(int a){
  if(g[a].empty()){
    dp[a][1]=1;
    dp[a][0]=0;

    return;
  }
  assert(!g[a].empty());

  for(auto &b:g[a]){
    solve(b);
  }

  for(auto&b:g[a]){

    if(dp[b][0]==0&&dp[b][1]==0){
      dp[a][0]=0;
      dp[a][1]=0;
      return;
    }
  }

  int kids=(int)g[a].size();

  int my=(kids+1)%2;


  for (int u=0;u<=1;u++){
    int places_my,places_not_my;
    if(u==my){ /// or inv?
      if(kids%2==0){
        places_my=kids/2;
        places_not_my=kids-places_my;

        assert(places_my==places_not_my);
      }else{
        places_my=kids/2;
        places_not_my=kids-places_my;

        assert(places_my==places_not_my-1);
      }
    }else{
      if(kids%2==0){

        places_my=kids/2+1;
        places_not_my=kids-places_my;

        assert(places_my==places_not_my+2);
      }else{
        places_my=kids/2+1;
        places_not_my=kids-places_my;

        assert(places_my==places_not_my+1);
      }
    }


    for (auto &b:g[a]){
      if(dp[b][0]&&dp[b][1]) continue;
      assert(dp[b][0]||dp[b][1]);

      if(dp[b][my]) places_my--;
      else places_not_my--;
    }

    dp[a][u]=(places_my>=0&&places_not_my>=0);
  }
}

vector<pair<int, int>> sol;

void print(int a,int u){
  assert(dp[a][u]);

  if(g[a].empty()){
    assert(u==1);
    sol.push_back({a, parof[a]});
    return;
  }

  assert(!g[a].empty());

  int kids=(int)g[a].size();
  int my=(kids+1)%2;

  int places_my,places_not_my;
  if(u==my){ /// or inv?
    if(kids%2==0){
      places_my=kids/2;
      places_not_my=kids-places_my;

      assert(places_my==places_not_my);
    }else{
      places_my=kids/2;
      places_not_my=kids-places_my;

      assert(places_my==places_not_my-1);
    }
  }else{
    if(kids%2==0){

      places_my=kids/2+1;
      places_not_my=kids-places_my;

      assert(places_my==places_not_my+2);
    }else{
      places_my=kids/2+1;
      places_not_my=kids-places_my;

      assert(places_my==places_not_my+1);
    }
  }


  for (auto &b:g[a]){
    if(dp[b][0]&&dp[b][1]) continue;
    assert(dp[b][0]||dp[b][1]);

    if(dp[b][my]) places_my--;
    else places_not_my--;
  }

  vector<int> kids_my,kids_not_my;

  for(auto&b:g[a]){
    if(dp[b][0]&&dp[b][1]){
      if(places_my>0){
        places_my--;
        kids_my.push_back(b);
      }else{
        assert(places_not_my--);
        kids_not_my.push_back(b);
      }
      continue;
    }
    if(dp[b][my]){
      kids_my.push_back(b);
    }else{
      kids_not_my.push_back(b);
    }
  }

  assert(places_my==0);
  assert(places_not_my==0);


  bool deja=0;
  int acum=my;


  for(int step=1;step<=(int)g[a].size();step++){
    if(acum==u&&!deja){
      sol.push_back({a, parof[a]});
      acum^=1;
      deja=1;
    }
    if(acum==my){
      print(kids_my.back(),acum);
      kids_my.pop_back();
    }else{
      print(kids_not_my.back(),acum);
      kids_not_my.pop_back();
    }
    acum^=1;
  }

  if(!deja){
    sol.push_back({a, parof[a]});
  }

}

void solve_task(){
  buildg(1);

  for (auto &b:g[1]){
    solve(b);
  }

  int deg=degs[1];
  int my=deg%2;
  int pl1=deg/2,pl2=(deg+1)/2;
  int places_my=max(pl1,pl2),places_not_my=min(pl1,pl2);


  for(auto&b:g[1]){
    if(dp[b][0]==0&&dp[b][1]==0){
      cout<<"NO\n";
      return;
    }
  }

  for (auto &b:g[1]){
    if(dp[b][0]&&dp[b][1]) continue;
    if(dp[b][my]) places_my--;
    else places_not_my--;
  }

  if(places_my<0||places_not_my<0){
    cout<<"NO\n";
    return;
  }
  sol.clear();

  vector<int> kids_my,kids_not_my;

  cout<<"YES\n";


  for (auto &b:g[1]){
    if(dp[b][0]&&dp[b][1]){
      assert(places_my>0||places_not_my>0);
      if(places_my>0){
        places_my--;
        kids_my.push_back(b);
      }else{
        assert(places_not_my>0);
        places_not_my--;
        kids_not_my.push_back(b);
      }
      continue;
    }
    if(dp[b][my]){
      kids_my.push_back(b);
    }else{
      kids_not_my.push_back(b);
    }
  }



  for(int step=1;step<=(int)g[1].size();step++){
    if(step%2==1){
      assert(!kids_my.empty());
      print(kids_my.back(),my);
      kids_my.pop_back();
    }else{
      assert(!kids_not_my.empty());
      print(kids_not_my.back(),my^1);
      kids_not_my.pop_back();
    }
  }


  assert(places_my==0);
  assert(places_not_my==0);
  assert(kids_my.empty());
  assert(kids_not_my.empty());

  for (auto &it:sol){
    cout<<it.first<<" "<<it.second<<"\n";
  }

}

signed main() {
#ifdef ONLINE_JUDGE
  home=0;
#endif


  if(home) {
    freopen("I_am_iron_man","r",stdin);
   /// freopen ("output.txt","w",stdout);
  }
  else{
    ios::sync_with_stdio(0);cin.tie(0);
  }

  int tests;
  cin>>tests;
  for(int tc=1;tc<=tests;tc++){
    cin>>n;
    for(int i=1;i<n;i++){
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    solve_task();
    for(int i=1;i<=n;i++) g[i].clear();
  }

}