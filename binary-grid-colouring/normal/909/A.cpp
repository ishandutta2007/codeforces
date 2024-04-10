#include<bits/stdc++.h>
#include <set>

using namespace std;
typedef long long ll;
const int maxn = 100010;
const int mod = 1e9+7;
#define  pii pair<int,int>
#define fi first
#define se second

int n,m;
string tmp;
int main(int argc, char const *argv[]) {
  string s1,s2;
  std::cin >> s1 >> s2;
  std::vector<string> v;
  for (size_t i = 0; i < s1.length(); i++) {
    for (size_t j = 0; j < s2.length(); j++) {
      tmp = s1.substr(0,i+1)+s2.substr(0,j+1);
      v.push_back(tmp);
    }
  }
  sort(v.begin(),v.end());
  std::cout << v[0] << '\n';
  return 0;
}