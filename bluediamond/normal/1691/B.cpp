#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int) 1e5+7;
int n, a[N];

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int t;
  cin>>t;
  while (t--) {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    map<int, vector<int>> w;
    for (int i=1;i<=n;i++) {
      w[a[i]].push_back(i);
    }
    bool ok=1;
    for (auto &it:w) {
      auto inds=it.second;
      ok&=((int)inds.size()>=2);
    }
    if (!ok) {
      cout<<"-1\n";
      continue;
    }
    for (auto &it:w) {
      auto inds=it.second;
      int k=(int)inds.size();
      assert(k>=2);
      for (int i=0;i<k;i++){
        a[inds[i]]=inds[(i+1)%k];
      }
    }
    for (int i=1;i<=n;i++) {
      cout<<a[i]<<" ";
    }
    cout<<"\n";
  }
}

/**
**/