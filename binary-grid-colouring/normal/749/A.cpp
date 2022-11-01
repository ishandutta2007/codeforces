#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;
std::vector<ll> a,b;
int vis[maxn];
int ans[maxn];
std::map<int, int> mp;
int main(int argc, char const *argv[]) {

  int n;
  std::cin >> n;
  if(n&1) {
    std::cout << (n-1)/2 << '\n';
    for(int i=1;i<=(n-1)/2-1;i++) {
      std::cout << "2" << " ";
    }
    std::cout << "3" << '\n';
  }
  else {
    std::cout << n / 2 << '\n';
    for(int i=1;i<=(n/2);i++) {
      std::cout << "2" << " ";
    }
    std::cout << '\n';
  }
  return 0;
}