#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


string s,ss;
int ans[123];
int main(int argc, char const *argv[]) {
  std::cin >> s;
  std::cin >> ss;
  for(int i=0;i<s.size();i++) {
    ans[i]=(s[i]-'0')^(ss[i]-'0');
  }
  for(int i=0;i<s.size();i++) {
    std::cout << ans[i];
  }
  std::cout << '\n';
  return 0;
}