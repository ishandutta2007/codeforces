#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,c;
  cin>>a>>b>>c;
  cout<<(a / c + (bool)(a % c))*(b / c + (bool)(b % c));
}