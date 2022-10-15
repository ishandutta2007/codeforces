#include <bits/stdc++.h>

bool home = 1;

using namespace std;
#define int long long
typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;
int n, k, start, boi, sol;
int sub[N];
int dp[N];
bool has[N];
vector<int> g[N];

void dfs(int a,int p=-1) {
  has[a]=(a==boi);
  dp[a]=0;
  for (auto &b:g[a]) {
    if (b!=p) {
      dfs(b,a);
      has[a]|=has[b];
      sub[a]+=sub[b];
      if (sub[b]) {
        dp[a]+=2+dp[b];
      }

    }
  }

  if (a==boi) {
    for (auto &b:g[a]) {
      if (b!=p) {
        if (sub[b]) {
          sol+=2+dp[b];
        }
      }
    }
  }else{
    if (has[a]) {
      sol++;
      for (auto &b:g[a]) {
        if (b!=p&&!has[b]) {
          if (sub[b]) {
            sol+=2+dp[b];
          }
        }
      }
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
    sol=0;
    cin>>n>>k>>start>>boi;
    for (int i=1;i<=n;i++) {
      sub[i]=0;
      g[i].clear();
    }
    for (int i=1;i<=k;i++) {
      int a;
      cin>>a;
      sub[a]=1;
    }
    for (int i=1;i<n;i++) {
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    dfs(start);
    assert(has[start]);
    cout<<sol<<"\n";
  }

}