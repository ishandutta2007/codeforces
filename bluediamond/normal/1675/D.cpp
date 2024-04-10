#include <bits/stdc++.h>

bool home = 1;

using namespace std;
#define int long long
typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;
int n;
int inds;
vector<int> g[N];
vector<int> reps[N];
bool v[N];

void dfs(int a,int p=-1,int id=1) {
  reps[id].push_back(a);
  bool f=1;
  for (auto &b:g[a]) {
    if (b!=p) {
      dfs(b,a,(f==1)?id:++inds);
      f=0;
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  home=0;

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int t;
  cin>>t;
  while (t--) {
    cin>>n;
    for (int i=1;i<=n;i++) {
      g[i].clear();
      v[i]=0;
      reps[i].clear();
    }
    int root=-1;
    for (int i=1;i<=n;i++) {
      int p;
      cin>>p;
      if (p==i) {
        root=i;
        continue;
      }
      int a=i;
      int b=p;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    inds=1;
    dfs(root);
    cout<<inds<<"\n";
    for (int i=1;i<=inds;i++) {
      cout<<(int)reps[i].size()<<"\n";
      for (auto &x:reps[i]) {
        cout<<x<<" ";
      }
      cout<<"\n";
    }
  }

}