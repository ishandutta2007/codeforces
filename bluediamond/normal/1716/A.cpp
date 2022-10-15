#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    cout<<n/3+(n%3==1)*2/((n!=1)+1)+(n%3)/2<<"\n";
  }
}