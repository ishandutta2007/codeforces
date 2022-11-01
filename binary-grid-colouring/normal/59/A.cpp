#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]) {
  string s;
  int cnt1=0,cnt2=0;
  std::cin >> s;
  for(int i=0;i<s.size();i++) {
    if(isupper(s[i])) {
      cnt1++;
    }
    else cnt2++;
  }
  if(cnt1>cnt2) {
    transform(s.begin(),s.end(),s.begin(),::toupper);
    std::cout << s << '\n';
  }
  else
  {
    transform(s.begin(),s.end(),s.begin(),::tolower);
    std::cout << s << '\n';
  }
  return 0;
}