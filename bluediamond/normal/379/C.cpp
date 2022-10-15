#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,first_free=1;
  cin>>n;
  vector<pair<int, int>> a(n);
  vector<int> sol(n);
  for (int i=0;i<n;i++) {
    cin>>a[i].first;
    a[i].second=i;
  }
  sort(a.begin(), a.end());
  for (auto &x:a){
    sol[x.second]=max(first_free,x.first);
    first_free=max(first_free,x.first)+1;
  }
  for (auto &x:sol){
    cout<<x<<" ";
  }
  cout<<"\n";
}