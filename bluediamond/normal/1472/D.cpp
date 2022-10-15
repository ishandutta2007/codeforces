#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);

  //freopen ("input", "r", stdin);

  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    vector<int> par,imp;
    for (int i=1;i<=n;i++) {
      int x;
      cin>>x;
      if (x&1) imp.push_back(x);
      else par.push_back(x);
    }
    sort(imp.begin(),imp.end());
    sort(par.begin(),par.end());
    int dif=0;///alice-bob
    for (int i=1;i<=n;i++) {
      if (i%2==1) {
        if (imp.empty()) {dif+=par.back(); par.pop_back(); continue;}
        if (par.empty()) {imp.pop_back(); continue;}
        if (par.back()>imp.back()) {dif+=par.back(); par.pop_back(); continue;}
        else {imp.pop_back(); continue;}
      } else {
        if (imp.empty()) {par.pop_back(); continue;}
        if (par.empty()) {dif-=imp.back(); imp.pop_back(); continue;}
        if (par.back()>imp.back()) {par.pop_back(); continue;}
        else {dif-=imp.back();imp.pop_back(); continue;}
      }
    }
    if (dif>0) cout<<"Alice\n";
    else if (dif==0) cout << "Tie\n"; else cout << "Bob\n";
  }

}