#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N=(int) 2e5+7;
int n,a[N],b[N];
int indeg[N];
set<pair<int,int>> s;
vector<int> ord;
int sol;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>n;
  for (int i=1;i<=n;i++) {
    cin>>a[i];
  }
  for (int i=1;i<=n;i++) {
    cin>>b[i];
    if (b[i]!=-1) {
      indeg[b[i]]++;
    }
  }
  for (int i=1;i<=n;i++) {
    s.insert({indeg[i],i});
  }
  vector<int> rev;
  for (int it=1;it<=n;it++) {
    int i=s.begin()->second;
    s.erase(s.begin());
    if (a[i]>=0) {
      sol+=a[i];
      ord.push_back(i);
      if (b[i]!=-1) {
        s.erase({indeg[b[i]],b[i]});
        indeg[b[i]]--;
        s.insert({indeg[b[i]],b[i]});
        a[b[i]]+=a[i];
      }
    } else {
      rev.push_back(i);
      if (b[i]!=-1) {
        s.erase({indeg[b[i]],b[i]});
        indeg[b[i]]--;
        s.insert({indeg[b[i]],b[i]});
      }
    }
  }
  reverse(rev.begin(),rev.end());
  for (auto &i : rev) {
    sol+=a[i];
    ord.push_back(i);
  }
  cout<<sol<<"\n";
  for (int i=0;i<n;i++) {
    cout<<ord[i]<<" ";
  }
  cout<<"\n";
  return 0;
}