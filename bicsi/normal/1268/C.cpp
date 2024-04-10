#include <bits/stdc++.h>
#define int long long 

using namespace std;

struct Fenwick {
  int n;
  vector<int> data;
  Fenwick(int n) : n(n), data(n + 1, 0) {}

  void Add(int pos, int val) {
    for (++pos; pos <= n; pos += (pos & -pos))
      data[pos] += val;
  }
  int Get(int l, int r) {
    if (l != 0) {
      return Get(0, r) - Get(0, l - 1);
    }
    int ans = 0;
    for (++r; r > 0; r -= (r & -r))
      ans += data[r];
    return ans;
  }
  int Kth(int k) {
    int ans = 0;
    for (int step = (1 << 20); step; step /= 2) {
      if (ans + step <= n && data[ans + step] <= k) {
        k -= data[ans + step];
        ans += step;
      }
    }
    return ans;
  }
};

int Sum(int a, int b) {
  return b * (b + 1) / 2 - a * (a - 1) / 2;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n; cin >> n;
  vector<int> p(n), pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i]; --p[i];
    pos[p[i]] = i;
  }

  Fenwick fw(n), fw2(n);
  vector<int> inv(n, 0), ans(n, 0);
  for (int i = 0; i < n; ++i) {
    inv[i] = fw.Get(pos[i], n - 1);
    if (i > 0) inv[i] += inv[i - 1];
    fw.Add(pos[i], 1);
    fw2.Add(pos[i], pos[i]);
    int mid = fw.Kth(i / 2);
    int cnt_lo = fw.Get(0, mid);
    int cnt_hi = fw.Get(mid + 1, n - 1);
    int sum_lo = fw2.Get(0, mid);
    int sum_hi = fw2.Get(mid + 1, n - 1);
    ans[i] -= sum_lo;
    ans[i] += Sum(mid - cnt_lo + 1, mid);
    ans[i] += sum_hi;
    ans[i] -= Sum(mid + 1, mid + cnt_hi);
    // cerr << i << '\t' << mid << '\t' << inv[i] << '\t' << ans[i] << endl;
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] + inv[i] << ' ';
  }
  cout << endl;
  
  return 0;
}