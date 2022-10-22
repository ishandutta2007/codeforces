#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;
    int i = 0, j = 0, k = 0;
    string ans;
    int nn = n + n;
    while (i < nn && j < nn && k < nn) {
      int cnt0 = 0, cnt1 = 0;
      if (i < nn) {
        if (a[i] == '0') ++cnt0; else ++cnt1;
      }
      if (j < nn) {
        if (b[j] == '0') ++cnt0; else ++cnt1;
      } 
      if (k < nn) {
        if (c[k] == '0') ++cnt0; else ++cnt1;
      } 
      if (cnt0 > cnt1) {
        ans.push_back('0');
        if (i < nn && a[i] == '0') ++i;
        if (j < nn && b[j] == '0') ++j;
        if (k < nn && c[k] == '0') ++k;
      } else {
        ans.push_back('1');
        if (i < nn && a[i] == '1') ++i;
        if (j < nn && b[j] == '1') ++j;
        if (k < nn && c[k] == '1') ++k;
      }
      if (i == nn) {
        if (j < k) {
          for (; k < nn; ++k) ans.push_back(c[k]);
        } else {
          for (; j < nn; ++j) ans.push_back(b[j]);
        }
      } else
      if (j == nn) {
        if (i < k) {
          for (; k < nn; ++k) ans.push_back(c[k]);
        } else {
          for (; i < nn; ++i) ans.push_back(a[i]);
        }
      } else
      if (k == nn) {
        if (i < j) {
          for (; j < nn; ++j) ans.push_back(b[j]);
        } else {
          for (; i < nn; ++i) ans.push_back(a[i]);
        }
      }
    }
    while (ans.size() < n + n + n) ans.push_back('0');
    cout << ans << '\n';
  }
  return 0;
}