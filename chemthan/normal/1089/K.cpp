#include <bits/stdc++.h>

using namespace std;
#define sz(a) (int)(a).size()
#define rep(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define debug(a) cerr << #a << ": " << (a) << '\n';
#define debug_arr(arr, n) { cerr << #arr << " "; rep(i, 0, n) cerr << arr[i] << " \n"[i == n]; }
#define debug_two(a, b) cerr << #a << ": " << (a) << ", " << #b << ": " << (b) << '\n';

template <typename num_t>
inline void addmod(num_t& a, const long long& b, const int& m) { a = (a + b) % m; if (a < 0) a += m; }
template <typename num_t>
inline void update_max(num_t& a, const num_t& b) { a = max(a, b); }
template <typename num_t>
inline void update_min(num_t& a, const num_t& b) { a = min(a, b); }
template <typename num_t>
num_t gcd(num_t lhs, num_t rhs) { return !lhs ? rhs : gcd(rhs % lhs, lhs); }
template <typename num_t>
num_t pw(num_t n, num_t k, num_t mod) {
  num_t res = 1; for (; k; k >>= 1) { if (k & 1) res = 1ll * res * n % mod; n = 1ll * n * n % mod; } return res;
}

typedef long long ll;
const int inf = 1e9 + 7;
const int mod = inf;
const int MAX_N = 1000000 + 7;
const long long ll_inf = (ll)inf * inf;

struct query {
  char op;
  int time, duration;
};

vector<query> q;
int mapping[MAX_N];

const int MAGIC = 420;

struct Block {
  static const int BLOCK_SIZE = MAGIC;
  pair<int, int> value[BLOCK_SIZE];
  long long f[BLOCK_SIZE];
  long long gap[BLOCK_SIZE];
  int n;
  long long total_gap = 0;
  long long first = -1, second = -1;

  void add(pair<int, int> r) {
    value[n++] = r;
    for (int i = n - 1; i > 0; --i) if (value[i].first < value[i - 1].first)
      swap(value[i], value[i - 1]);
    update_block();
  }

  void remove(pair<int, int> r) {
    int i = 0; while (i < n && value[i] != r) ++i;
    for (; i + 1 < n; ++i) value[i] = value[i + 1];
    --n;
    update_block();
  }

  void update_block() {
    total_gap = 0;
    long long last = 0;
    first = second = -1;
    for (int i = 0; i < n; ++i) {
      if (value[i].first < last) {
        last += value[i].second;
      } else {
        if (first != -1) {
          total_gap += value[i].first - last;
        } else first = value[i].first;
        last = value[i].first + value[i].second;
      }
      f[i] = last;
      gap[i] = total_gap;
    }
    second = last;
  }

  inline void b_search(int time, long long& last) {
//    for (int i = 0; i < n; ++i) if (value[i].first <= time) {
//      last = max(last, (ll)value[i].first) + value[i].second;
//    } else break;
    int lo = 0, hi = n - 1, res = -1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (value[mid].first <= time) {
        res = mid;
        lo = mid + 1;
      } else hi = mid - 1;
    }

    long long temp = f[res];
    if (last - first >= gap[res]) temp += last - first - gap[res];
    last = temp;
  }

  void query(int time, long long& last) {
    if (first == -1 || value[0].first > time) return;
    if (last <= first) {
      if (second <= time) {
        last = second; return;
      }
      b_search(time, last);
    } else {
      if (last - first >= total_gap) {
        long long temp = second + last - first - total_gap;
        if (temp <= time) {
          last = temp; return;
        }
      } else {
        if (second <= time) {
          last = second; return;
        }
      }
      b_search(time, last);
    }
  }
};

Block blocks[MAX_N / MAGIC + 7];

void solve() {
  int m; cin >> m; q.resize(m);
  rep(i, 0, m) {
    cin >> q[i].op;
    if (q[i].op == '+') {
      cin >> q[i].time >> q[i].duration;
    } else cin >> q[i].time;
    if (q[i].op != '-') mapping[q[i].time] = 1;
  }

  int mx_block = 0;

  for (int i = 1; i < MAX_N; ++i) {
    static int k = 0;
    if (mapping[i]) {
      mapping[i] = ++k;
      update_max(mx_block, k / MAGIC + 1);
    }
  }

  rep(i, 0, m) {
    if (q[i].op == '+') {
      blocks[mapping[q[i].time] / MAGIC].add({ q[i].time, q[i].duration });
    } else if (q[i].op == '-') {
      int u = q[i].time - 1;
      blocks[mapping[q[u].time] / MAGIC].remove({ q[u].time, q[u].duration });
    } else {
      long long last = 0;
      for (int j = 0; j < mx_block; ++j)
        blocks[j].query(q[i].time, last);
      if (q[i].time >= last) cout << 0 << '\n';
      else cout << last - q[i].time << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
  freopen("in.txt", "r", stdin);
#endif
  const bool multiple_test = false;
  int test = 1;
  if (multiple_test)
    cin >> test;

  for(int i = 0; i < test; ++i) {
    //printf("Case #%d: ", i + 1);
    solve();
  }
#ifdef _LOCAL_
  cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
#endif
}