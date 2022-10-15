#include <bits/stdc++.h>

bool home = 1;

using namespace std;

///#define int long long

const int N=(int)2e5+7;
int n,a[N],b[N],f[N],vis[N],act[N],ok;
vector<int> g[N];

void dfs(int a){
  act[a]=vis[a]=1;
  for(auto&b:g[a]){
    if(act[b]){
      ok=0;
    }
    if(!vis[b]){
      dfs(b);
    }
  }
  act[a]=0;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int tt;
  cin>>tt;
  while(tt--){
    cin>>n;
    for(int i=1;i<=n;i++) f[i]=vis[i]=act[i]=0, g[i].clear();
    for(int i=1;i<=n;i++) {cin>>a[i]; f[a[i]]++;}
    for(int i=1;i<=n;i++) {cin>>b[i]; f[b[i]]--;}
    ok=1;
    for(int i=1;i<=n;i++){
      ok&=(f[i]==0);
    }
    if(!ok){
      cout<<"WA\n";
      continue;
    }
    for(int i=1;i<=n;i++) f[a[i]]++;
    int mx=max_element(f+1,f+n+1)-f;
    for(int i=1;i<=n;i++){
      int x=a[i],y=b[i];
      if(x!=mx&&y!=mx){
        g[x].push_back(y);
      }
    }
    for(int i=1;i<=n;i++){
      if(!vis[i]) {
        dfs(i);
      }
    }
    if(ok) cout<<"AC\n"; else cout<<"WA\n";
  }

}