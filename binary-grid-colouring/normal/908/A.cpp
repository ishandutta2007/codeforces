#include<bits/stdc++.h>

using namespace std;
const int maxn = 200100;
const double eps = 1e-9;

int main(int argc, char const *argv[]) {
  /* code */
  string Stirng = "aeiou13579";
  set<int> v;
  v = {
    Stirng.begin(),Stirng.end()
  };
  std::cin >> Stirng;
  int ans = 0;
  for(auto x : Stirng)
  {
    ans += v.count(x);
  }
  std::cout << ans << '\n';
  return 0;
}