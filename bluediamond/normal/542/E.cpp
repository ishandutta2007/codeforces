#include <bits/stdc++.h>

using namespace std;

bool home = 1;
///#define int ll

typedef long long ll;
typedef long double ld;

const int N=1000+7;
int n;
int m;
int c[N],dis[N];
vector<int> g[N];
vector<int> nos;
bool bip;

void clr(int a){
  nos.push_back(a);
  for (auto &b:g[a]){
    if(c[b]==-1){
      c[b]=1^c[a];
      clr(b);
    }else{
      bip&=(c[b]==(1^c[a]));
    }
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
  for (int i=1;i<=n;i++) c[i]=-1;
  for (int i=1; i<=m; i++) {
    int foo,bar;
    cin>>foo>>bar;
    g[foo].push_back(bar);
    g[bar].push_back(foo);
  }
  int sol=0;

  for (int i=1;i<=n;i++){
    if (c[i]==-1){
      int mx=0;
      nos.clear();
      c[i]=0;
      bip=1;
      clr(i);
      if (!bip){
        cout<<"-1\n";
        return 0;
      }
      for (auto &a:nos){
        for (auto &b:nos)dis[b]=-1;
        queue<int>q;
        q.push(a);
        dis[a]=0;
        while(!q.empty()){
          int a=q.front();
          q.pop();
          for (auto &b:g[a]){
            if(dis[b]==-1){
              dis[b]=1+dis[a];
              mx=max(mx,dis[b]);
              q.push(b);
            }
          }
        }
      }
      sol+=mx;
    }
  }
  cout<<sol<<"\n";

  return 0;
}