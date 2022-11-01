#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n,m;
  std::cin >> n >> m;
  std::vector<int> a(n+1);
  for (size_t i = 0; i < n; i++) {
    /* code */
    std::cin >> a[i];
  }
  sort(a.begin(),a.end());
  int ans = 0;
  for(int i=0;i<m;i++){
    if (a[i]<=0) {
      /* code */
      ans+=a[i]*-1;
    }
  }
  std::cout << ans << '\n';
}