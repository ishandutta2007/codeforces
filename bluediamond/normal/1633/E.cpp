#include <bits/stdc++.h>


using namespace std;

#define int long long

bool home = 1;

const int N=300+7;
const int INF=(int)1e18+7;

struct edge{
  int a,b,c,i;
};

int n;
int m;
int t[N];
int cost[N];
vector<edge> edgesinit;

int root(int a){
  if(t[a]==a)return t[a];
  return t[a]=root(t[a]);
}

void unite(int a,int b){
  t[root(a)]=root(b);
}

bool operator<(edge a,edge b){
  return a.c<b.c;
}

vector<int> check;
vector<vector<int>> atcheck;
vector<vector<int>> vals;

int upd(int ind,int x){
  bool inside=(0<=ind&&ind<(int)atcheck.size());
  if(!inside){
    return INF;
  }
  int sol=0;
  int l=0,r=(int)atcheck[ind].size()-1,cntsm=0;
  while(l<=r){
    int m=(l+r)/2;
    if(atcheck[ind][m]<=x){
      cntsm=m+1;
      l=m+1;
    }else{
      r=m-1;
    }
  }
  sol=vals[ind][cntsm];
  sol+=x*cntsm;
  sol-=x*((int)atcheck[ind].size()-cntsm);
  return sol;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0), cin.tie(0);
  }

  cin>>n>>m;
  edgesinit.resize(m);
  {
    int yl=0;
    for (auto &it:edgesinit){
      cin>>it.a>>it.b>>it.c;
      cost[yl]=it.c;
      it.i=yl;
      yl++;
    }
  }


  {
    vector<int> eve;
    for (auto &x:edgesinit){
      for (auto &y:edgesinit){
        if(x.c<=y.c){
          eve.push_back((x.c+y.c)/2);
          eve.push_back((x.c+y.c)/2+1);
        }
      }
    }
    set<int> st;
    for (auto &x:eve){
      st.insert(x);
    }
    eve.clear();
    for (auto &x:st){
      eve.push_back(x);
    }
    check=eve;
  }

  for (auto &x:check){
    vector<edge> edges=edgesinit;
    for (auto &it:edges){
      it.c=abs(it.c-x);
    }
    sort(edges.begin(),edges.end());
    vector<int> now;
    for (int i=1;i<=n;i++){
      t[i]=i;
    }
    for (auto &it:edges){
      if(root(it.a)!=root(it.b)){
        unite(it.a,it.b);
        now.push_back(cost[it.i]);
      }
    }
    sort(now.begin(),now.end());
    int ttl=0;
    for (auto &x:now){
      ttl+=x;
    }
    vector<int>kek;
    kek.push_back(ttl);
    for (auto &it:now){
      ttl-=2*it;
      kek.push_back(ttl);
    }
    assert((int)now.size()==n-1);
    assert((int)kek.size()==n);
    atcheck.push_back(now);
    vals.push_back(kek);
  }

  int p,k,a,b,c,ask;
  cin>>p>>k>>a>>b>>c;
  int xr=0;
  for (int i=1;i<=k;i++){
    if(i<=p){
      cin>>ask;
    }else{
      ask=(ask*a+b)%c;
    }
    int cntunder=0,l=0,r=(int)check.size()-1;
    while(l<=r){
      int m=(l+r)/2;
      if(check[m]<=ask){
        cntunder=m+1;
        l=m+1;
      }else{
        r=m-1;
      }
    }
    int sol=INF;
    sol=min(sol,upd(cntunder-1,ask));
    sol=min(sol,upd(cntunder,ask));

    xr^=sol;
  }
  cout<<xr<<"\n";

  return 0;
}