#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e8;
ll n , m;
int main(int argc, char const *argv[]) {
  std::cin >> n >> m;
  if(n <= 30) {
    std::cout << m%(1<<n) << '\n';
  }
  else
  std::cout << m << '\n';
  cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  return 0;
}