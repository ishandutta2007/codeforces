#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n,m;
map<string ,int>mp;
int main(int argc, char const *argv[]) {

  string s;
  int n;
  std::cin >> n;
  for(int i=1;i<=n;i++) {
    std::cin >> s;
    mp[s]++;
  }
  int maxx = 0;
  for(auto it = mp.begin();it!=mp.end();it++)
  {
    maxx = max(maxx,it->second);
  }
  for(auto it = mp.begin();it!=mp.end();it++) {
    if(it->second == maxx) {
      std::cout << it->first << '\n';
    }
  }
  return 0;
}