#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

///#define int ll

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

///freopen ("input", "r", stdin);

  int t;
  cin>>t;
  while (t--) {
    int n,k;
    cin>>n>>k;
    vector<int> g;
    for (int i=1;i<=n;i+=2){
      g.push_back(i);
    }
    if ((int)g.size()<k){
      cout<<"-1\n";
      continue;
    }
    g.resize(k);
    assert((int)g.size()==k);
    set<pair<int,int>>all;
    for (auto &x:g)all.insert({x,x});
    for (int i=1;i<=n;i++){
      for (int j=1;j<=n;j++){
        if(all.count({i,j})){
          cout<<"R";
        }else{
          cout<<".";
        }
      }
      cout<<"\n";
    }
  }

  return 0;
}