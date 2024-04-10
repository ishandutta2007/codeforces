#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int a[100005];

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  int sm = 0;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    sm += a[i];
  }
  int more = sm - (sm / n)*n;
  sort(a, a + n);
  reverse(a, a + n);
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    int tgt = sm / n;
    if(i < more) ++tgt;
    ans += abs(a[i]- tgt);
  }
  cout << ans/2 << "\n";
  return 0;
}