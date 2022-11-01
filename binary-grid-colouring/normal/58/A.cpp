#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]) {
  string s;
  std::cin >> s;
  string ss = "hello";
  if(s.size() < 5) {
    std::cout << "NO" << '\n';return 0;
  }
  int k = 0;
  for(int i=0;i<(int)s.size();i++) {
    if(s[i] == ss[k]) {
      k++;
    }
    if(k>=5) {
      std::cout << "YES" << '\n';return 0;
    }
  }
  std::cout << "NO" << '\n';
  return 0;
}