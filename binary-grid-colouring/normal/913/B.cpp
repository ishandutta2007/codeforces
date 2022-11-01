#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1000000;
ll n , m;
int fa[maxn];
int in[maxn];
int res[maxn];
int main(int argc, char const *argv[]) {
  std::cin >> n;
  for(int i=2;i<=n;i++) {
    std::cin >> fa[i];
    in[fa[i]]++;
  }
  for(int i=2;i<=n;i++) {
    if(in[i]==0) {
      res[fa[i]]++;
    }
  }
  for(int i=1;i<=n;i++) {
    if(in[i]) {
      if(res[i] < 3) {
        std::cout << "No" << '\n';
        exit(0);
      }
    }
  }
  std::cout << "Yes" << '\n';
  cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  return 0;
}