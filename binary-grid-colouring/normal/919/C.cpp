#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =2010;
int n,m;
int k;
int coloum[maxn],row[maxn];
int main(int argc, char const *argv[]) {

  int ans = 0;
  std::cin >> n >> m >> k;
  char ch;
  for(int i = 0;i < n;i++) {
    for(int j = 0;j < m;j++) {
      std::cin >> ch;
      if(ch=='.') {
        row[i] ++;
        coloum[j]++;
      }
      else {
        row[i] = 0;
        coloum[j] = 0;
      }
      if(row[i] >= k) ans ++;
      if(coloum[j] >= k) ans++;
    }
   }
   if(k==1) {
     ans /= 2;
   }
   std::cout << ans << '\n';
  return 0;
}