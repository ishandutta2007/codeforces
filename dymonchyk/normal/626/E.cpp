#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[200005];
long long s[200005];

long long get(int l, int r) {
  return s[r] - (l > 0 ? s[l - 1] : 0);
}

pair<long long, long long> calc1(int n, int i, int m) {
  long long big = get(n - 1 - m + 1, n - 1);
  long long small = get(i - 1 - m + 1, i - 1);

  return {(big + small + arr[i]) - 1LL * (2 * m + 1) * arr[i], (2 * m + 1)};
}

pair<long long, long long> calc2(int n, int i, int m) {
  long long big = get(n - 1 - m + 1, n - 1);
  long long small = get(i - 2 - m + 1, i - 2);

  return {(big + small + arr[i] + arr[i - 1]) - 1LL * (2 * m + 2) * (arr[i] + arr[i - 1]) / 2, (2 * m + 2)};
}

bool ls(const pair<long long, long long> &a, const pair<long long, long long> &b) {
  return 1LL * a.first * b.second < 1LL * b.first * a.second;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);

  for (int i = 0; i < n; ++i) {
    s[i] = arr[i];
    if (i) s[i] += s[i - 1];
  }

  pair<long long, long long> ba = {-1, 1};
  int ind = -1, k = -1, tp = -1;

  for (int i = 0; i < n; ++i) {
    int mx = min(i, n - 1 - i);
    int l = 0, r = mx;
    while (r - l > 2) {
      int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
      pair<long long, long long>  v1 = calc1(n, i, m1), v2 = calc1(n, i, m2);
      if (ls(v2, v1)) r = m2;
      else l = m1;
    }

    for (int j = l; j <= r; ++j) {
      pair<long long, long long>  cur = calc1(n, i, j);
      // cout << j << "  " << cur << endl;
      if (ls(ba, cur)) {
        ba = cur;
        ind = i; k = j; tp = 1;
      }
    }
  }

  for (int i = 1; i < n; ++i) {
    int mx = min(i - 1, n - 1 - i);
    int l = 0, r = mx;
    while (r - l > 2) {
      int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
      pair<long long, long long>  v1 = calc2(n, i, m1), v2 = calc2(n, i, m2);
      if (ls(v2, v1)) r = m2;
      else l = m1;
    }

    for (int j = l; j <= r; ++j) {
      pair<long long, long long>  cur = calc2(n, i, j);
      // cout << j << "  " << cur << endl;
      if (ls(ba, cur)) {
        ba = cur;
        ind = i; k = j; tp = 2;
      }
    }
  }

  if (tp == 1) {
    printf("%d\n", 2 * k + 1);
    for (int i = 0; i < k; ++i) {
      printf("%d %d ", arr[ind - 1 - i], arr[n - 1 - i]);
    }
    printf("%d\n", arr[ind]);
  } else {
    printf("%d\n", 2 * k + 2);
    for (int i = 0; i < k; ++i) {
      printf("%d %d ", arr[ind - 2 - i], arr[n - 1 - i]);
    }
    printf("%d %d\n", arr[ind], arr[ind - 1]);
  }

  // cout << calc1(3, 1, 1) << " " << ba << endl;

  return 0;
}