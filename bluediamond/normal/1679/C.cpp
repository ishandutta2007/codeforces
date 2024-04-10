#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

  int n,q;
  cin>>n>>q;
  vector<vector<int>> on(2,vector<int> (n+1,0));
  vector<set<int>> s(2);
  for (int i=1;i<=n;i++) {
    s[0].insert(i);
    s[1].insert(i);
  }
  while (q--) {
    int t;
    cin>>t;
    assert(1<=t&&t<=3);
    if (t==1) {
      int x,y;
      cin>>x>>y;
      if (on[0][x]==0) s[0].erase(x);
      if (on[1][y]==0) s[1].erase(y);
      on[0][x]++;
      on[1][y]++;
    }
    if (t==2) {
      int x,y;
      cin>>x>>y;
      on[0][x]--;
      on[1][y]--;
      if (on[0][x]==0) s[0].insert(x);
      if (on[1][y]==0) s[1].insert(y);
    }
    if (t==3) {
      int x1,y1,x2,y2;
      bool ok1=1,ok2=1;
      cin>>x1>>y1>>x2>>y2;
      auto it=s[0].lower_bound(x1);
      ok1&=(it==s[0].end()||*it>x2);

      it=s[1].lower_bound(y1);
      ok2&=(it==s[1].end()||*it>y2);
      cout<<((ok1==0&&ok2==0)?("No"):("Yes"))<<"\n";
    }
  }

  return 0;
}