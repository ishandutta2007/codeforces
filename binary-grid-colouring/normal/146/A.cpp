#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[123];
int main(int argc, char const *argv[]) {

  int n;

  std::cin >> n;
  for(int i=0;i<n;i++) {
    std::cin >> s[i];
    if(s[i]=='4' || s[i] =='7') {
      continue;
    }
    else {
      std::cout << "NO" << '\n';
      return 0;
    }
  }

  if(n&1) {
    std::cout << "NO" << '\n';
  }
  else
  {

    int sum1 = 0,sum2 = 0;
    for(int i = 0;i< n/2;i++) {
      sum1 += (s[i]-'0');
    }
    for(int i=n/2;i<n;i++) {
      sum2 += (s[i]-'0');
    }
    // std::cout << sum1 << " " << sum2 << '\n';
    if(sum1==sum2) {
      std::cout << "YES" << '\n';
    }
    else std::cout << "NO" << '\n';
  }

  return 0;
}