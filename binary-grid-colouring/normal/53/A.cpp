#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]) {
  string s,a,b="z";
  int n ;
  std::cin >> s;
  std::cin >> n;
  for(int i=1;i<=n;i++) {
    std::cin >> a;
    if((a.substr(0,s.size())==s )&& (a < b)) {
      b = a;
    }
  }
  if(b=="z") {
    std::cout << s << '\n';
  }
  else
   std::cout << b << '\n';
  return 0;
}