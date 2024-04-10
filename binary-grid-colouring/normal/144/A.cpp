#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int maxx,minn=110;
int id1,id2;

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> a(n+1);
  for(int i=1;i<=n;i++) {
    std::cin >> a[i];
    if(a[i] > maxx ) {
      id1 = i;
      maxx = a[i];
    }
    if(a[i] <= minn ) {
      id2 = i;
      minn = a[i];
    }
  }
  // std::cout << id2 << '\n';
  // std::cout << id1 << '\n';
  int ans = 0;
  if(id1 < id2) {
    ans = (id1 - 1) + (n - id2);
  }else {
    ans = (id1 - 1) + (n - id2) - 1;
  }
  std::cout << ans << '\n';
  return 0;
}