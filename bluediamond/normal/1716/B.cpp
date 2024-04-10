#include <bits/stdc++.h>

using namespace std;

void prn(vector<int> v){
  for(auto&x:v)cout<<x<<" ";
  cout<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    cout<<n<<"\n";
    vector<vector<int>> s;
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    prn(v);
    swap(v[0],v[1]);
    prn(v);
    for (int i=2;i<n;i++) {
      swap(v[i],v[0]);
      prn(v);
    }
  }
}