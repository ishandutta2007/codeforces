#include<bits/stdc++.h>

using namespace std;
const int maxn = 200100;
const double eps = 1e-9;
const double pi = 3.1415926536;


int main(int argc, char const *argv[]) {
  string s,t;
  std::cin >> s >> t;
  for(int i=0;i < t.size() - 1;i++) {
    s = '#' + s + '#';
  }
  int ans = 5000;
  for(int i = 0;i < s.size() - t.size() + 1;i++) {
    int cnt = 0;
    for(int j=0;j<t.size();j++) {
      if(s[i+j] != t[j])
        cnt += 1;
    }
    ans = min(ans,cnt);
  }
  std::cout << ans << '\n';
  return 0;
}