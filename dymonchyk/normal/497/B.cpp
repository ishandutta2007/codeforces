#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[100005];
vector<pair<int, int>> ans;

int get(int l, int r) {
  return arr[r] - (l > 0 ? arr[l - 1] : 0);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]); arr[i] = 2 - arr[i];
    if (i) arr[i] += arr[i - 1];
    // cout << arr[i] << " ";
  }
  // cout << endl;
  for (int t = 1; t <= n; ++t) {
    int spos = 0, s[2] = {0}, ok = 1, lst = -1;
    while (spos < n) {
      int l = spos - 1, r = n - 1;
      while (r - l > 1) {
        int m = (l + r) >> 1;
        int val1 = get(spos, m), val2 = m - spos + 1 - val1;
        if (val1 >= t || val2 >= t) r = m;
        else l = m;
      }
      // cout << t << "  " << r << endl;
      int val1 = get(spos, r), val2 = r - spos + 1 - val1;
      if (val1 == t && get(r, r) == 1) ++s[0], lst = 0;
      else if (val2 == t && get(r, r) == 0) ++s[1], lst = 1;
      else ok = 0;
      spos = r + 1;
    }
    if (ok && s[0] != s[1] && (s[lst] > s[lst ^ 1])) {
      ans.push_back(make_pair(max(s[0], s[1]), t));
    }
  }
  printf("%d\n", (int) ans.size());
  sort(ans.begin(), ans.end());
  for (auto p : ans) {
    printf("%d %d\n", p.first, p.second);
  }

  // vector<pair<int, int>> ans2;
  // for (int s = 1; s <= n; ++s) {
  //   for (int t = 1; t <= n; ++t) {
  //     int sc[2] = {0}, v[2] = {0};
  //     for (int i = 0; i < n; ++i) {
  //       v[arr[i] - 1]++;
  //       if (v[0] == t) {
  //         ++sc[0];
  //         v[0] = v[1] = 0;
  //       } else if (v[1] == t) {
  //         ++sc[1];
  //         v[0] = v[1] = 0;
  //       }
  //     }
  //     if (sc[0] != sc[1] && max(sc[0], sc[1]) == s && v[0] == v[1] && v[0] == 0)
  //       ans2.push_back(make_pair(s, t));
  //   }
  // }

  // printf("%d\n", (int) ans2.size());
  // sort(ans2.begin(), ans2.end());
  // for (auto p : ans2) {
  //   printf("%d %d\n", p.first, p.second);
  // }
  return 0;
}