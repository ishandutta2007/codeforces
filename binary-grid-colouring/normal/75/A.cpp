#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum(ll n)
{
  ll ans = 0;
  string s = to_string(n);
  for(int i=0;i<s.length();i++) {
    if(s[i]=='0')continue;
     ans = ans * 10 + (s[i]-'0');
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  int a,b;
  std::cin >> a >> b;
  ll c;
  c = a + b;
  if(sum(a) + sum(b) == sum(c)) {
    std::cout << "YES" << '\n';
  }
  else std::cout << "NO" << '\n';
  return 0;
}