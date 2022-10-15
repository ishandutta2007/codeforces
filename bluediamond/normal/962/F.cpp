#include <bits/stdc++.h>

using namespace std;

bool home = 1;
///#define int ll

typedef long long ll;
typedef long double ld;

//#define int ll

const int N=(int)1e5+7;
int n,m,dep[N],add[N],score[N];
pair<int,int>par[N];
vector<pair<int,int>>g[N];
vector<pair<int,int>>nr[N];
vector<pair<int,int>>bk[N];
vector<int>sol;
bool vis[N];
ll pref[N];
vector<pair<int,int>>cycs;

void dfs(int a){
  vis[a]=1;
  for (auto &it:g[a]){
    int b=it.first;
    int i=it.second;
    if(!vis[b]){

      dep[b]=1+dep[a];

      nr[a].push_back(it);
      par[b]={a,i};
      dfs(b);
     // cout<<"edge "<<a<<" "<<b<<"\n";
    }else{
      if(dep[b]<dep[a]-1){
        /// back edge
       // cout<<"\t\t\tback edge "<<a<<" "<<b<<"\n";
      //  cout<<a<<"->+1\n";
      //  cout<<b<<"->-1\n";
        cycs.push_back({a,b});
        add[a]++;
        add[b]--;
        bk[a].push_back(it);
      }
    }
  }
}

void nd(int a){
  score[a]=add[a];
  for (auto &it:nr[a]){
    nd(it.first);
    score[a]+=score[it.first];
  }
}

void tr(int a) {
  pref[a]+=score[a];
  for (auto &it:nr[a]){
    pref[it.first]+=pref[a];
    tr(it.first);
  }
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

  map<pair<int,int>,int>id;

  for (int i=1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    id[{a,b}]=id[{b,a}]=i;
    g[a].push_back({b,i});
    g[b].push_back({a,i});
  }

  for (int i=1;i<=n;i++){
    if(vis[i]) continue;
    cycs.clear();
    dfs(i);
    nd(i);
    tr(i);
    for (auto &itr:cycs){
      int a=itr.first,b=itr.second;
      //cout<<pref[a]-pref[b]<<" vs "<<dep[a]-dep[b]<<"\n";
      if(pref[a]-pref[b]!=dep[a]-dep[b])continue;
      sol.push_back(id[{a,b}]);
      swap(a,b);
      while(b!=a){
        //cout<<" current "<<b<<"\n";
        sol.push_back(par[b].second);
        b=par[b].first;
      }
      //cout<<"done\n";
    /**  if(pref[a]-pref[b]==dep[a]-dep[b]){
        cout<<"good cycle\n";
      }**/
    }

  }

  sort(sol.begin(),sol.end());
  cout<<(int)sol.size()<<"\n";
  for (auto &i:sol){
    cout<<i<<" ";
  }
  cout<<"\n";


  return 0;
}