#include <bits/stdc++.h>

using namespace std;

struct Fenwick {
  vector<int> data;
  Fenwick(int n) : data(n + 1, 0) {}
  void Add(int pos, int val) {
    for (++pos; pos > 0; pos -= (pos & -pos))
      data[pos] += val;
  }
  int Query(int pos) {
    int ans = 0;
    for (++pos; pos < (int)data.size(); pos += (pos & -pos))
      ans += data[pos];
    return ans;
  }
};

int main() {
  int n, m; cin >> n >> m;
  
  vector<int> minn(n), maxx(n);
  for (int i = 0; i < n; ++i) {
    minn[i] = maxx[i] = i;
  }

  vector<int> v;
  for (int i = n - 1; i >= 0; --i)
    v.push_back(i);
  for (int i = 0; i < m; ++i) {
    int x; cin >> x; --x;
    v.push_back(x);
    minn[x] = 0;
  }


  m += n;
  vector<int> last(n, -1), prv(m, -1), nxt(m, -1);
  for (int i = 0; i < m; ++i) {
    int now = v[i];
    prv[i] = last[now];
    if (last[now] != -1) {
      nxt[last[now]] = i;
    }
    last[now] = i;
  }

  Fenwick fw(m);
  for (int i = 0; i < m; ++i) {
    if (prv[i] != -1) {
      maxx[v[i]] = max(maxx[v[i]], fw.Query(prv[i] + 1));
      fw.Add(prv[i], -1);
    }
    fw.Add(i, 1);
  }

  for (int i = 0; i < m; ++i) {
    if (nxt[i] == -1) {
      maxx[v[i]] = max(maxx[v[i]], fw.Query(i + 1));
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << minn[i] + 1 << " " << maxx[i] + 1 << '\n';
  }

  return 0;
}