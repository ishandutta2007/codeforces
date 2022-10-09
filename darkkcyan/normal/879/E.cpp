#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

struct ds {
  int cnt;
  vector<int> min_data, max_data;
  ds() {}
  ds(int cnt_ = 1, int data_size = 0): cnt(cnt_), min_data(data_size), max_data(data_size) {}
  ds(const vector<int>& data): cnt(1), min_data(data), max_data(data) {}
};

ds join(ds a, const ds& b) {
  a.cnt += b.cnt;
  rep(i, len(a.min_data)) {
    a.min_data[i] = min(a.min_data[i], b.min_data[i]);
    a.max_data[i] = max(a.max_data[i], b.max_data[i]);
  }
  return a;
}

int comparing_id;
bool by_min;
bool operator<(const ds& a, const ds& b) {
  if (by_min) return a.min_data[comparing_id] < b.min_data[comparing_id];
  return a.max_data[comparing_id] < b.max_data[comparing_id];
}
using namespace std::rel_ops;

multiset<ds> se;

bool cmp_itor(const multiset<ds>::iterator& u, const multiset<ds>::iterator& v) {
  return 
    u == se.end() ? false :
    v == se.end() ? true :
    *u < *v;
}

bool updatable(const ds& a, const ds& b) {
  bool has_lower = false, has_upper = false;
  rep(i, len(a.min_data)) {
    if (a.min_data[i] < b.max_data[i]) has_lower = true;
    if (b.min_data[i] < a.max_data[i]) has_upper = true;
    // if (b.min_data[i] < a.min_data[i] and a.max_data[i] < b.max_data[i]) return true;
  }
  return has_lower and has_upper;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;

    rep1(i, n) {
      vector<int> data(k);
      rep(f, k) cin >> data[f];
      ds cur(data);

      for (comparing_id = 0; comparing_id < k; ++comparing_id) {
        by_min = false;
        for (auto it = se.upper_bound(ds(cur.min_data)); it != se.end() and updatable(*it, cur); it = se.erase(it)) {
          cur = join(cur, *it);
        }
      }
      comparing_id = 0;

      se.insert(cur);
      cout << (--se.end())->cnt << '\n';
    }

    return 0;
}