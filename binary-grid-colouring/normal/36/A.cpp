#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ss[1234];
int main(int argc, char const *argv[]) {
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  int n,m=0;
  string s;
  std::cin >> n;
  std::cin >> s;
  for(int i=0;i<n;i++) {
    if(s[i]=='1') {
      ss[m++] = i;
    }
  }
  for(int i=2;i<m;i++) {
    if(ss[i] - ss[i-1] != ss[i-1] - ss[i-2])
    {
      std::cout << "NO" << '\n';
      return 0;
    }
  }
  std::cout << "YES" << '\n';
  return 0;
}