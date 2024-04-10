#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long double ld;
typedef long long ll;

void no(bool ok){
  if(ok)return;
  if(home)cout<<"NO\n";else
  cout<<"-1\n";
  exit(0);
}


void yes(vector<pair<int,int>>edges){
  if(home)cout<<"YES\n";
  for (auto &it:edges)cout<<it.first<<" "<<it.second<<"\n";
  exit(0);
}
const int N=30000+7;
const int K=200+7;
int n,k,dist[K][N],roots[K],par[N];
bool use[N];
vector<int> paths[K],verts[N];

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

  cin>>n>>k;
  for (int it=1;it<=k;it++){
    int ze=0,some;
    for (int i=1;i<=n;i++){
      cin>>dist[it][i];
      if(dist[it][i]==0){
        ze++;
        some=i;
      }
    }
    no(ze==1);
    roots[it]=some;
    for (int j=1;j<it;j++){
      no(roots[it]!=roots[j]);
    }
    vector<int> dists;
    for (int i=1;i<=n;i++)dists.push_back(dist[it][i]);
    sort(dists.begin(),dists.end());
    for (int i=1;i<n;i++){
      if (dists[i]!=dists[i-1]){

        no(dists[i]-dists[i-1]==1);
      }
    }
  }

  vector<pair<int,int>>sol;

  int root=roots[1];

  for (int it=2;it<=k;it++){
    int currentroot=roots[it];

    no(dist[1][currentroot]==dist[it][root]);
    vector<pair<int,int>>ys;

    for (int v=1;v<=n;v++){
      bool onpath=(dist[it][v]+dist[1][v]==dist[1][currentroot]);
      if(onpath){
        ys.push_back({dist[1][v],v});
      }
    }
    sort(ys.begin(),ys.end());

    no(ys.size()==dist[1][currentroot]+1);
    no(ys[0].second==root);
    paths[it].push_back(root);

    for (int i=1;i<ys.size();i++){
      paths[it].push_back(ys[i].second);
      no(par[ys[i].second]==0||par[ys[i].second]==ys[i-1].second);
      par[ys[i].second]=ys[i-1].second;
    }
    no(ys.back().second==currentroot);
  }

  for (int i=1;i<=n;i++){
    if (par[i]){
      sol.push_back({par[i],i});
      use[i]=use[par[i]]=1;
    }
  }

  use[root]=1;

  vector<pair<int,int>>unused;

  for (int i=1;i<=n;i++){
    if(!use[i])unused.push_back({dist[1][i],i});
  }
  sort(unused.begin(),unused.end());

  for (auto &it:unused){
    int v=it.second;
    if(home){
      cout<<v<<" : ";
    }

    int where=roots[1];


    for (int it=2;it<=k;it++){
      int dif=dist[1][v]-dist[it][v]-(-dist[1][roots[it]]);
      no(dif%2==0);
      no(-dist[1][roots[it]]<=dist[it][v]-dist[1][v]&&dist[it][v]-dist[1][v]<=dist[1][roots[it]]);
      dif/=2;


      assert(0<=dif&&dif<paths[it].size());
      int who=paths[it][dif];

      if(home){
        cout<<who<<" ";
      }
      if(dist[1][who]>dist[1][where])where=who;

    }
    if(home){
      cout<<": "<<where<<"\n";
    }

    //cout<<where<<" -> "<<v<<"\n";
    verts[where].push_back(v);

  }



  for (int i=1;i<=n;i++){
    if(use[i]){
      vector<int> kek={i};
      for (auto &j:verts[i])kek.push_back(j);
/**
      cout<<"\t\t\t"<<verts[i].size()<<":";
      for (auto &x:kek){
        cout<<x<<" ";
      }
      cout<<"\n";
**/
      int pt=0;

      for (auto &j:verts[i]){
        while (dist[1][kek[pt]]<dist[1][j]-1){
          pt++;
        }


        assert(0<=pt&&pt<kek.size());
        no(dist[1][kek[pt]]==dist[1][j]-1);
        sol.push_back({kek[pt],j});
      }
    }
  }

  yes(sol);


  return 0;
}