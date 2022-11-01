#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
std::map<int, int> mp;

int main(int argc, char const *argv[]) {
  string s,ss;
  std::cin >> s;
  std::cin >> ss;
  reverse(s.begin(),s.end());
  if(ss == s) {
    std::cout << "YES" << '\n';
  }
  else std::cout << "NO" << '\n';
  return 0;
}