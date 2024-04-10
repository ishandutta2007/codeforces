#include <bits/stdc++.h>

using namespace std;

int t;

signed main() {
  cin>>t;
  for (int i=1;i<=t;i++) {
    int n,m;
    cin>>n>>m;
    if(n>m)swap(n,m);
    /// n<=m
    if(m==1){
      cout<<"0\n";
      continue;
    }
    if (n==1){
      cout<<"1\n";
      continue;
    }
    if (n==2){
      cout<<"2\n";
      continue;
    }
    cout<<"2\n";
  }

  return 0;
}