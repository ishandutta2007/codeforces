#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
string s;
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::cin >> s;
  int cnt = 0;
  int len = s.length();
  for(int i=0;i<len-1;i++) {
    if((s[i]=='U' && s[i+1] =='R') || (s[i]=='R' && s[i+1] =='U'))
    {
      cnt++;
      i++;
    }
  }
  std::cout << cnt + len - (2 * cnt) << '\n';
  return 0;
}