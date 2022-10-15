#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100+7;
int n;
int a[N];
int b[N];

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int tt;
  cin>>tt;
  while (tt--) {
    vector<pair<int, int>> sol;
    cin>>n;

    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];

    bool ok=1;

    while (n>1) {
      int mxa=*max_element(a+1,a+n+1), mxb=*max_element(b+1,b+n+1);
      if (a[n]==mxa&&b[n]==mxb) {
        n--;
        continue;
      }
      ok=0;
      for (int i=1;i<n;i++) {
        if (a[i]==mxa&&b[i]==mxb) {
          sol.push_back({i, n});
          ok=1;
          swap(a[i], a[n]);
          swap(b[i], b[n]);
          break;
        }
      }
      if (!ok) break;
      assert(a[n]==mxa);
      assert(b[n]==mxb);

      continue;
    }

    if (!ok) {
      cout<<"-1\n";
      continue;
    }
    cout<<(int)sol.size()<<"\n";
    for (auto &it : sol) {
      cout<<it.first<<" "<<it.second<<"\n";
    }
  }

}