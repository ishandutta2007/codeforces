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
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using LL = long long;

int n, k;

int AskToEnd(int s) {
  int ans = 0;
  while (true) {
    cout << "? ";
    for (int i = 0; i < k; ++i) {
      cout << s + 1 << " ";
      s = (s + 1) % n;
    }
    cout << endl;
    int temp;
    cin >> temp;
    ans ^= temp;
    if (s == 0) break;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  int m = 0;
  while (m < n) m += k;
  if ((m - n) & 1) m += k;
  if ((m - n) & 1) {
    cout << -1 << endl;
    return 0;
  }
  if (m == n) {
    int ans = AskToEnd(0);
    cout << "! " << ans << endl;  
    return 0;
  }
  int ans = 0;
  cout << "? ";
  for (int i = 0; i < k; ++i) {
    cout << i + 1 << " ";
  }
  cout << endl;
  cin >> ans;
  int s = k;
  bool over = false;
  if ((n - s) & 1) {
    cout << "? ";
    for (int i = 0; i < k; ++i) {
      cout << s + 1 << " ";
      s = (s + 1) % n;
      if (s == 0) over = true;
    }
    cout << endl;
    int temp;
    cin >> temp;
    ans ^= temp;
  }

  if (over) {
    while (k + s / 2 > n || (n - s) % 2 == 1) {
      cout << "? ";
      for (int i = 0; i < k; ++i) {
        cout << s + 1 << " ";
        s = (s + 1) % n;
      }
      cout << endl;
      int temp;
      cin >> temp;
      ans ^= temp;
    }
    int t = s / 2;
    cout << "? ";
    for (int i = 0; i < k - s / 2; ++i) cout << s + i + 1 << " ";
    for (int i = 0; i < s / 2; ++i) {
      cout << i + 1 << " ";
    }
    cout << endl;
    int temp;
    cin >> temp;
    ans ^= temp;

    cout << "? ";
    for (int i = 0; i < k - s / 2; ++i) cout << s + i + 1 << " ";
    for (int i = s / 2; i < s; ++i) {
      cout << i + 1 << " ";
    }
    cout << endl;
    cin >> temp;
    ans ^= temp;
    cout << "! " << ans << endl;
  } else {
    if ((n - s) / 2 >= k - (m - n) / 2) {
      cout << "? ";
      for (int i = 0; i < (m - n) / 2; ++i) cout << i + 1 << " ";
      for (int i = 0; i < k - (m - n) / 2; ++i) {
        cout << s + 1 << " ";
        s = (s + 1) % n;
      }
      cout << endl;
      int temp;
      cin >> temp;
      ans ^= temp;

      cout << "? ";
      for (int i = 0; i < (m - n) / 2; ++i) cout << i + 1 << " ";
      for (int i = 0; i < k - (m - n) / 2; ++i) {
        cout << s + 1 << " ";
        s = (s + 1) % n;
      }
      cout << endl;
      cin >> temp;
      ans ^= temp;
      if (s != 0) ans ^= AskToEnd(s);
      cout << "! " << ans << endl;
    } else {
      int t = (n - s) / 2;
      cout << "? ";
      for (int i = 0; i < k - t; ++i) cout << i + 1 << " ";
      for (int i = 0; i < t; ++i) {
        cout << s + 1 << " ";
        ++s;
      }
      cout << endl;
      int temp;
      cin >> temp;
      ans ^= temp;

      cout << "? ";
      for (int i = 0; i < k - t; ++i) cout << i + 1 << " ";
      for (int i = 0; i < t; ++i) {
        cout << s + 1 << " ";
        ++s;
      }
      cout << endl;
      cin >> temp;
      ans ^= temp;
      cout << "! " << ans << endl;
    }
  }
  return 0;
}