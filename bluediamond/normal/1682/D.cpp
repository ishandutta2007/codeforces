#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;
int n,a[N];

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
    string str;
    cin>>str;
    assert((int)str.size()==n);
    int sum=0;
    for (int i=1;i<=n;i++) {
      a[i]=str[i-1]-'0';
      assert(0<=a[i]&&a[i]<=1);
      sum+=a[i];
    }
    if (sum%2==1) {
      cout << "NO\n";
      continue;
    }
    vector<pair<int, int>> edges;
    vector<int> stk;
    for (int it_add=1;it_add<=n;it_add++) {
      stk.push_back(it_add);
      while ((int)stk.size()>=2) {
        int i1=stk.back(); stk.pop_back();
        int i2=stk.back(); stk.pop_back();
        if (a[i1]==a[i2]) {
          stk.push_back(i2);
          stk.push_back(i1);
          break;
        }
        if (a[i1]==0) swap(i1,i2);
        assert(a[i1]==1);
        assert(a[i2]==0);
        edges.push_back({i1, i2});
        a[i1]^=1;
        a[i2]^=1;
        stk.push_back(i2);
        assert(a[i2]==1);
      }
    }
   /// cout<<" = "<<(int)stk.size()<<", edges = "<<(int)edges.size()<<"\n";
    if (!stk.empty()) {
      int val=a[stk[0]];
      for (auto &i:stk) {
        assert(a[i]==val);
      }
      if (val==0&&(int)stk.size()>1){
        cout<<"NO\n";
        continue;
      }
      for (int i=1;i<(int)stk.size();i++) {
        edges.push_back({stk[0],stk[i]});
      }
    }
    assert((int)edges.size()==n-1);
    cout<<"YES\n";
    for (auto &it:edges){
      cout<<it.first<<" "<<it.second<<"\n";
    }
  }

}