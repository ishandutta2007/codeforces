#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin>>t;
  while (t--){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<min(1,abs(a+c-2*b)%3)<<"\n";

  }

  return 0;
}
/**

**/