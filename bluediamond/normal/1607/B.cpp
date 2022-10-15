#include <bits/stdc++.h>

using namespace std;

#define int long long


int get(int x,int n){
  if (x%2==0) {
    if (n%4==0)return x;
    if (n%4==1)return x-n;
    if (n%4==2)return x+1;
    if (n%4==3)return x+1+n;
  }else{
    if (n%4==0)return x;
    if (n%4==1)return n+x;
    if (n%4==2)return x-1;
    if (n%4==3)return x-(+1+n);
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);



  int t;
  cin>>t;
  while (t--){
    int x,n;
    cin>>x>>n;
    cout<<get(x,n)<<"\n";
  }

  return 0;
}