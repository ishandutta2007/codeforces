#include <bits/stdc++.h>

using namespace std;

struct Fenwick {
  int n;
  vector<int> data;

  Fenwick(int n) : n(n), data(n + 1, 0) {}

  void Add(int pos) {
    //cerr << "ADD(" << pos + 1 << ")" << endl;
    for (++pos; pos <= n; pos += (pos & -pos))
      data[pos] += 1;
  }

  int Get(int k) {
    //cerr << "GET(" << k << ")" << endl;
    int ans = 0;
    for (int step = (1 << 20); step; step /= 2) {
      if (ans + step <= n && data[ans + step] <= k) {
        ans += step;
        k -= data[ans];
      }
    }
    //cerr << "> " << ans << endl;
    return ans;
  }
};

int main() {
  int n; cin >> n;

  vector<pair<int, int>> w(n);
  vector<int> v(n);

  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    w[i] = make_pair(x, -i);
    v[i] = x;
  }
  sort(w.rbegin(), w.rend());
  
  int q; cin >> q;
  vector<tuple<int, int, int>> qrs;
  for (int i = 0; i < q; ++i) {
    int k, pos; cin >> k >> pos; --pos;
    qrs.emplace_back(k, pos, i);
  }

  Fenwick fw(n);
  sort(qrs.begin(), qrs.end());
  vector<int> ans(q, -1);

  int at = 0;
  
  for (int i = 0; i < n; ++i) {
    fw.Add(-w[i].second);
    while (at < (int)qrs.size()) {
      int k, pos, j; tie(k, pos, j) = qrs[at];
      if (k == i + 1) {
        int res = fw.Get(pos);
        //cerr << "ANSWER TO " << j << ": " << res + 1 << endl;
        ans[j] = v[res];
        ++at;
      } else break;
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << '\n';
  }

  return 0;
}