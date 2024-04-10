#include <bits/stdc++.h>

using namespace std;

#define int ll
typedef long long ll;
typedef long double ld;

int d(pair<int,int>a,pair<int,int>b){
  return abs(a.first-b.first)+abs(a.second-b.second);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  int tt;
  cin>>tt;
  while (tt--){
    int n,m;
    cin>>n>>m;
    vector<int>cnt(2*(max(n,m)+7),0);
    vector<pair<int,int>>all;
    all.push_back({1,1});
    all.push_back({n,m});
    all.push_back({1,m});
    all.push_back({n,1});
    for (int i=1;i<=n;i++){
      for (int j=1;j<=m;j++){
        pair<int,int>c={i,j};
        int dmax=0;
        for (auto &kek:all)dmax=max(dmax,d(c,kek));
        cnt[dmax]++;
      }
    }
    int done=0;
    for (int i=0;i<(int)cnt.size();i++){
      for (int j=1;done<n*m&&j<=cnt[i];j++){
        done++;
        cout<<i<<" ";
      }
    }
    cout<<"\n";
  }

  return 0;
}