#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e4 + 7;
int n, k, a[N], f[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      f[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      f[a[i]]++;
    }
    int cntd = 0;
    for (int i = 1; i <= n; i++) {
      cntd += (f[i] > 0);
    }
    if (cntd > k) {
      cout << "-1\n";
    } else {
      vector<int> nums;
      for (int i = 1; i <= n; i++) {
        if (f[i] > 0) {
          nums.push_back(i);
        }
      }
      for (int i = 1; i <= n; i++) {
        if (f[i] == 0 && (int) nums.size() < k) {
          nums.push_back(i);
        }
      }
      cout << n * k << "\n";
      for (int i = 1; i <= n; i++) {
        for (auto &x : nums) {
          cout << x << " ";
        }
      }
      cout << "\n";
    }
  }
  return 0;
}