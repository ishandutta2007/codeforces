#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;


std::map<int, int> mp;

int main(int argc, char const *argv[]) {

  ll n,m;
  ll ans = 0;
  std::cin >> n >> m;
  ll nm = n+m;
  std::cout << min(min(nm / 3,n), m) << '\n';
  return 0;
}