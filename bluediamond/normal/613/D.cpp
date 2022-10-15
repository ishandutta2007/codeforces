#include <bits/stdc++.h>

bool home=1;
using namespace std;

typedef long double ld;

const int N=(int)1e5+7;
const int INF=(int)1e9+7;
const int K=20;
int n;
int top;
int parrent[N];
pair<int, int> rmq[K][2*N];
int lg[2*N];
int dep[N];
int first[N];
int last[N];
vector<int> g[N];

void build(int a,int p=0){
  parrent[a]=p;
  {
    rmq[0][++top]={dep[a], a};
    first[a]=last[a]=top;
    vector<int> kids;
    for (auto &b:g[a]){
      if(b!=p){
        kids.push_back(b);
        dep[b]=1+dep[a];
        build(b,a);
        rmq[0][++top]={dep[a], a};
        last[a]=top;
      }
    }
    g[a]=kids;
  }
}

int get_lca(int a,int b){
  if(first[a]>last[b]) swap(a,b);

  a=first[a];
  b=last[b];
  int k=lg[b-a+1];

  return min(rmq[k][a],rmq[k][b-(1<<k)+1]).second;
}

bool cmpVertsFirst(int a,int b){
  return first[a]<first[b];
}

bool is[N];
vector<int> gaux[N];
int dpzero[N];
int dpone[N];

void solve(int a){
  dpzero[a]=dpone[a]=INF;
  for (auto &b:gaux[a]){
    solve(b);
  }
  if(is[a]==1){
    dpone[a]=0;
    for (auto &b:gaux[a]){
      dpone[a]+=dpzero[b];
    }
    dpzero[a]=1+dpone[a];
  }else {
    dpzero[a]=0;
    for (auto &b:gaux[a]){
      dpzero[a]+=dpzero[b];
    }
    for (auto &b:gaux[a]){
      dpone[a]=min(dpone[a],dpzero[a]-dpzero[b]+dpone[b]);
    }
    int cur=0;
    for (auto &b:gaux[a]){
      cur+=min(dpzero[b],dpone[b]);
    }
    dpzero[a]=min(dpzero[a],1+cur);
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

  cin>>n;
  for (int i=1;i<n;i++) {
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }


  build(1);

  for (int i=2;i<=top;i++) lg[i]=1+lg[i/2];

  for(int k=1;(1<<k)<=top;k++){
    for(int i=1;i+(1<<k)-1<=top;i++){
      rmq[k][i]=min(rmq[k-1][i],rmq[k-1][i+(1<<(k-1))]);
    }
  }
  int q;
  cin>>q;

  for(int iq=1;iq<=q;iq++){
    int k;
    cin>>k;
    vector<int> verts(k);
    for (auto &v:verts){
      cin>>v;
      is[v]=1;
    }
    bool is_bad=0;
    for (auto &v:verts){
      if(is[parrent[v]]) is_bad=1;
    }
    if(is_bad){
      for (auto &v:verts){
        is[v]=0;
      }
      cout<<"-1\n";
      continue;
    }
    verts.push_back(1);
    sort(verts.begin(),verts.end(),cmpVertsFirst);

    {
      int dim=(int)verts.size();
      for (int i=1;i<dim;i++){
        verts.push_back(get_lca(verts[i-1],verts[i]));
      }
      sort(verts.begin(),verts.end(),cmpVertsFirst);
      vector<int> nw_verts;
      nw_verts.push_back(verts[0]);
      for (int i=1;i<(int)verts.size();i++){
        if(verts[i]!=verts[i-1]){
          nw_verts.push_back(verts[i]);
        }
      }
      verts=nw_verts;
    }

    vector<int> dfs_stack;
    dfs_stack.push_back(1);

    for (int i=1;i<(int)verts.size();i++){
      int v=verts[i];
      while(1){
        if(get_lca(v,dfs_stack.back())!=dfs_stack.back()){
          dfs_stack.pop_back();
        }else{
          break;
        }
      }
      gaux[dfs_stack.back()].push_back(v);
      dfs_stack.push_back(v);
    }
    solve(1);
    int sol=min(dpone[1],dpzero[1]);
    cout<<sol<<"\n";
    for (auto &v:verts){
      is[v]=0;
      gaux[v].clear();
    }
  }
}