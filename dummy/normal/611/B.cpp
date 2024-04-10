#include <bits/stdc++.h>

using namespace std;

long long a, b;

int main() {
  cin >> a >> b;
  int ans = 0;
  for(int i = 1; i<=63; i++) {
    long long now = (1LL<<i) - 1;
    for(int j = 0; j+1<i; j++) {
      long long y = now ^ (1LL<<j);
      if(y >= a && y <= b)
        ans++;
    }
  }
  cout << ans << endl;
  return 0;
}