#include <bits/stdc++.h>

using namespace std;

#define int long long


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);



  int q;
  cin>>q;
  while (q--){
    int n;
    cin>>n;
    vector<pair<int,int>>a(n);
    vector<int>sol(n);
    for (int i=0;i<n;i++){
      cin>>a[i].first;
      a[i].second=i;
    }
    sort(a.rbegin(),a.rend());
    int soll=0;
    for (int i=0;i<n;i++){
      soll+=a[i].first*((i+2)/2)*2;
      sol[a[i].second]=((i+2)/2)*((i%2==0)?1:-1);
    }
    cout<<soll<<"\n0 ";
    for (auto &x:sol)cout<<x<<" ";
    cout<<"\n";
  }


  return 0;
}