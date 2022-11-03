#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

long long win1[5005], win2[10002];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (v[i] > v[j]) {
        win1[v[i] - v[j]]++;
        // cout << v[i] - v[j] << endl;
      }
    }
  }

  for (int i = 0; i <= 5000; ++i) {
    if (win1[i])
      for (int j = 0; j <= 5000; ++j) {
        win2[i + j] += win1[i] * win1[j];
      }
  }

  long long ans = 0;
  for (int i = 0; i <= 5000; ++i) {
    if (win2[i])
      for (int j = i + 1; j <= 5000; ++j) {
        ans += win2[i] * win1[j];
      }
  }

  int T = n * (n - 1) / 2;
  printf("%.10lf\n", 1.0 * ans / T / T / T);

  return 0;
}