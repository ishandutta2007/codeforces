#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<a[0];i++){
    cout<<"PRL";
  }
  for(int i=1;i<n;i++){
    cout<<"R";
    for(int j=0;j<a[i];j++) {
      cout<<"PLR";
    }
  }
  cout<<"\n";
}