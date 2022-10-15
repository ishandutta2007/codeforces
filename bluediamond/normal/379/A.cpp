#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b;
  cin>>a>>b;
  cout<<a+(a>=b)*((a-b)/(b-1)+1)<<"\n";
}