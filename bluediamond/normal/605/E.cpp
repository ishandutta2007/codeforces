#include <bits/stdc++.h>

using namespace std;

bool home = 1;

//#define int ll

typedef long long ll;
typedef long double ld;

const int N=1000+7;
int n;
ld p[N][N];
ld value[N],kek[N],prod[N];
bool ok[N][N];
vector<int>g[N];
int id[N];
bool reach[N];
vector<int>verts;

void dfs(int a){if(reach[a])return;
  reach[a]=1;
  verts.push_back(a);
  for (auto &b:g[a])dfs(b);
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
  for (int i=1;i<=n;i++){
    for (int j=1;j<=n;j++){
      int pp;
      cin>>pp;

      if(pp)g[j].push_back(i),ok[i][j]=1;
      p[i][j]=pp*0.01;
    }
    prod[i]=1;
    kek[i]=0;
  }
  dfs(n);


  vector<int>guys={n};
  int ids=1;
  id[n]=1;
  int it=n;
    for (auto &i:verts){
      if (id[i])continue;
      if(!ok[i][it])continue;
      kek[i]+=value[it]*p[i][it]*prod[i];
      prod[i]*=(1-p[i][it]);
    }
  while(!id[1]){
    int who=-1;
    for (auto &i:verts){
      if(id[i])continue;
      ld simu=0,produ=1;

      ld allbef=prod[i];
      value[i]=kek[i];



      value[i]++;
      allbef=1-allbef;
      value[i]/=allbef;
      if (who==-1||value[i]<value[who]){
        who=i;
      }
    }
    id[who]=++ids;
    guys.push_back(who);
    int it=who;
    for (auto &i:verts){
      if (id[i])continue;
      if(!ok[i][it])continue;
      kek[i]+=value[it]*p[i][it]*prod[i];
      prod[i]*=(1-p[i][it]);
    }
  }

  cout<<fixed<<setprecision(6)<<value[1]<<"\n";
  return 0;
}