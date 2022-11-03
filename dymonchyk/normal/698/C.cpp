#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

double prob[1<<20];

int main() {
  int n, k;
  int arr[22];
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    double x;
    cin >> x;
    arr[i] = int(100 * x + 0.5);
  }

  double what[102] = {0};
  for (int j = 0; j <= 100; ++j) {
    double x = 1.0;
    // what[i][j] = x;
    for (int it = 0; it <= 5000; ++it) {
      x = x * j / 100;
      what[j] += x;
    }
    // if (i == 2)
    //   cout << i << "  " << j << " " << what[i][j] << endl;
  }

  for (int mask = 0; mask < (1 << n); ++mask) {
    int s = 0, cnt = 0;
    for (int j = 0; j < n; ++j) {
      if (mask & (1 << j)) {
        s += arr[j];
        ++cnt;
      }
    }
    prob[mask] = what[s];
  }

  for (int i = 0; i < n; ++i) {
    for (int mask = 0; mask < (1 << n); ++mask) {
      if ((mask & (1 << i)) == 0) prob[mask | (1 << i)] -= prob[mask];
    }
  }

  // for (int mask = 0; mask < (1 << n); ++mask) {
  //   int s = 0, cnt = 0;
  //   for (int j = 0; j < n; ++j) {
  //     if (mask & (1 << j)) {
  //       s += arr[j];
  //       ++cnt;
  //     }
  //   }
  //   // prob[mask] = max(0.0, 2 * what[s] - prob[mask]);
  //   // cout << mask << " " << prob[mask] << endl;
  // }

  for (int i = 0; i < n; ++i) {
    double ans = 0;
    // if (n == k) ans = 1.0;
    // else
    for (int mask = 0; mask < (1 << n); ++mask) {
      if (mask & (1 << i)) continue;
      int s = 0, cnt = 0;
      double cur = 1.0;
      for (int j = 0; j < n; ++j) {
        if (mask & (1 << j)) {
          s += arr[j];
          ++cnt;
        }
      }
      if (cnt < k) {
        ans += arr[i] / 100.0 * cur * prob[mask];
        // cout << arr[i] << " " << cur << " " << prob[mask] << endl;
      }
    }
    printf("%.10lf ", ans + arr[i] / 100.0);
  }
  printf("\n");

  return 0;
}