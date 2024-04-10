#include <bits/stdc++.h>
using namespace std;

template <typename T>
void read(T &x) {
  cin >> x;
}

long long b;

int main() {
  ios :: sync_with_stdio(false); cin.tie(0);
  read(b);
  long long ans = 1, sq = sqrt(b);
  for (long long i = 2; i <= sq; i++) {
    int cnt = 0;
    while (b % i == 0) {
      b /= i, cnt++;
    }
    ans *= (cnt + 1);
  } 
  if (b > 1) ans *= 2;
  cout << ans << '\n';
  return 0;
}