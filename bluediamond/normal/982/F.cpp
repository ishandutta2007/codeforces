#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long double ld;
typedef long long ll;

/**
a vertex is on all cycles => if we remove it there are no cycles left

plan : find a random cycle

**/


mt19937 rng((long long) (new char));

time_t bg,nd;

double getElapsed(){
  nd=clock();
  return (double)(nd-bg)/CLOCKS_PER_SEC;
}

const int N=(int)1e5+7;
int n;
int m;
int tt;
int turningPoint;
bool passed;
vector<int> g[N],verts,cycle;
int act[N];

bool dfs(int vertex){
  act[vertex]=tt;
  for(auto&B:g[vertex]){
    if(abs(act[B])<tt){
      if(dfs(B)){
        if(!passed){
          cycle.push_back(vertex);
        }
        if(vertex==turningPoint){
          passed=1;
        }
        return 1;
      }
    }else{
      if(act[B]==tt){
        turningPoint=B;
        cycle.push_back(vertex);
        return 1;
      }
    }
  }
  act[vertex]=-tt;
  return 0;
}

void fndCycle(int deletedVertex=0){
  cycle.clear();
  passed=0;
  tt++;
  act[deletedVertex]=-tt;
  for(auto&v:verts){
    if(abs(act[v])<tt){
      dfs(v);
      if(!cycle.empty()){
        break;
      }
    }
  }
}

void print(vector<int> v){
  cout<<"---->";
  for(auto&x:v){
    cout<<x<<" ";
  }
  cout<<"\n";
}

bool vis[N];
bool visnow[N];
bool has;

void DFS(int v){
  vis[v]=1;
  visnow[v]=1;
  for(auto&x:g[v]){
    if(visnow[x])has=1;
    if(!vis[x]){
      DFS(x);
    }
  }
  visnow[v]=0;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  bg=clock();

  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin>>n>>m;
  verts.resize(n);
  iota(verts.begin(),verts.end(),1);
  shuffle(verts.begin(),verts.end(),rng);
  for(int i=1;i<=m;i++){
    int A,B;
    cin>>A>>B;
    g[A].push_back(B);
  }

  int multi=0;
  for(int i=1;i<=n;i++){
    if(!vis[i]){
      has=0;
      DFS(i);
      multi+=has;
    }
  }
  if(multi>=2){
    cout<<"-1\n";
    return 0;
  }

  fndCycle();

  if(cycle.empty()){
    assert(0);
    cout<<"1\n";
    exit(0);
  }


  vector<int> P=cycle;

  while(1){
    if(P.empty()){
      cout<<"-1\n";
      return 0;
    }
    if(getElapsed()>0.9){
      int V=P[0];
      fndCycle(V);
      if(cycle.empty()){
        cout<<V<<"\n";
        return 0;
      }
      cout<<"-1\n";
      return 0;
    }
    shuffle(P.begin(),P.end(),rng);
    int V=P[0];
    fndCycle(V);

    if(cycle.empty()){
      cout<<V<<"\n";
      return 0;
    }

    set<int>Joint;
    for(auto&x:cycle){
      Joint.insert(x);
    }

    cycle.clear();
    for(auto&x:P){
      if(Joint.count(x)){
        Joint.erase(x);
        cycle.push_back(x);
      }
    }

    P=cycle;


  }

  return 0;
}