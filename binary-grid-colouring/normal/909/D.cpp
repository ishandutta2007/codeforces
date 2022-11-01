#include<bits/stdc++.h>
#include <set>

using namespace std;
typedef long long ll;
const int maxn = 100010;
const int mod = 1e9+7;
#define pii pair<int,int>
#define fi first
#define se second

int n,m;
string tmp;

int main(int argc, char const *argv[]) {
  string s;
  std::cin >> s;
  std::vector<pair<char,int>> v;
  for(auto ch:s){
    if(v.empty() || v.back().first != ch) {
      v.push_back({ch,1});
    }
    else
    {
      v.back().second++;
    }
  }
  int ans = 0;
  // for(auto x:v){
  //   std::cout << x.first <<" "<<x.second <<'\n';
  // }
//  std::cout << v.size() << '\n';
  while(v.size() > 1) {
    v[0].second -- ;
    v.back().second --;
    for(int i=1;i < v.size() - 1;i++) {
      v[i].second -= 2;
    }

    std::vector<pair<char,int>> v2;
    for(auto x: v)
    {
      if(x.second > 0) {
        if(v2.empty() || v2.back().first != x.first) {
          v2.push_back(x);
        }
        else
        {
          v2.back().second += x.second;
        }
      }
    }
    v = v2;
    ans++;
  }
  std::cout << ans << '\n';
  return 0;
}