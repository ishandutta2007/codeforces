#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];  
  }

  vector<int> b(n);
  vector<int> cnt(1 << 26);
  int ans = 0;

  for (int bit = 0; bit < 25; ++bit) {
    cerr << bit << endl;
    for (int i = 0; i < n; ++i) {
      b[i] = a[i] % (2 << bit);  
      cnt[b[i]] += 1;
    }

    for (int i = 1; i < (2 << bit); ++i)
      cnt[i] += cnt[i - 1];

    long long total = 0;
    int last = 0;
    for (int i = 0; i < (2 << bit); ++i) {
      if (cnt[i] == last) continue;
      int now = cnt[i] - last; last = cnt[i];
      
      if ((i + i) & (1 << bit)) {
        total += 1LL * now * (now - 1) / 2;
      }
      
      auto get = [&](int a, int b) {
        a = max(a, 0); b = min(b, i);
        if (a >= b) return 0;
        if (a > 0) 
          return cnt[b - 1] - cnt[a - 1];
        return cnt[b - 1];
      };
      
      total += 1LL * now * get((1 << bit) - i, (2 << bit) - i);
      total += 1LL * now * get((3 << bit) - i, (4 << bit) - i);
    }
    if (total % 2)
      ans |= (1 << bit);

    for (int i = 0; i < (2 << bit); ++i)
      cnt[i] = 0;
  }

  cout << ans << endl;

  return 0;
}