#include <bits/stdc++.h>

using namespace std;
#define sz(a) (int)(a).size()
#define rep(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define debug(a) cerr << #a << ": " << (a) << '\n';
#define debug_arr(a, n) { cerr << #a << " "; rep(i, 0, n) cerr << a[i] << " \n"[i == n]; }
#define debug_two(a, b) cerr << #a << ": " << (a) << ", " << #b << ": " << (b) << '\n';
mt19937 rng(static_cast<unsigned int>(chrono::steady_clock::now().time_since_epoch().count()));

template <typename num_t>
inline void add_mod(num_t& a, const int& b, const int& m) { a = (a + b) % m; if (a >= m) a -= m; if (a < 0) a += m; }
template <typename num_t>
inline bool update_max(num_t& a, const num_t& b) { return a < b ? a = b, true : false; }
template <typename num_t>
inline bool update_min(num_t& a, const num_t& b) { return a > b ? a = b, true : false; }
template <typename num_t>
num_t gcd(num_t lhs, num_t rhs) { return !lhs ? rhs : gcd(rhs % lhs, lhs); }
template <typename num_t>
num_t pw(num_t n, num_t k, const num_t& mod) {
  if (k == -1) k = mod - 2;
  num_t res = 1; for (; k > 0; k >>= 1) { if (k & 1) res = 1ll * res * n % mod; n = 1ll * n * n % mod; }
  return res % mod;
}

typedef long long ll;
const int inf = 1e9 + 7;
const int mod = 998244353;
const ll ll_inf = 9ll * inf * inf + 7;
const int MAX_N = 1000 + 7;

template <typename num_t>
class SegmentTree {
public:
  int d_left, d_right;
  void init(int l, int r) {
    d_left = l;
    d_right = r;
    tree.resize((r - l + 1) << 1);
    node_index = 0;
    build_tree(tree[node_index++], l, r);
  }

  void update(int left_index, int right_index, const num_t& val) {
    left_index = max(left_index, d_left);
    right_index = min(right_index, d_right);
    update_(tree[0], left_index, right_index, val);
  }

  num_t get(int left_index, int right_index) {
    if (right_index < left_index) return 0;
    return get(tree[0], left_index, right_index);
  }

private:
  struct node {
    static const num_t nil = 0;
    node *left_child, *right_child;
    int left_index, right_index;
    num_t value = 0;
    num_t lazy = 0;

    inline void push_down(num_t updated_value) {
      value += updated_value;
      lazy += updated_value;
    }

    inline void merge_node() {
      const node &lhs = *left_child, &rhs = *right_child;
      value = max(lhs.value, rhs.value);
    }

    inline void lazy_update() {
      if (lazy) {
        if (left_child != nullptr)
          left_child->push_down(lazy);
        if (right_child != nullptr)
          right_child->push_down(lazy);
        lazy = 0;
      }
    }

    inline void init_value(num_t v = 0) {
      value = 0;
      lazy = 0;
    }

    inline void init(int left, int right, node* left_child_, node* right_child_) {
      left_index = left; right_index = right;
      left_child = left_child_; right_child = right_child_;
    }

    int size() const { return right_index - left_index + 1; }
  };

  vector<node> tree;
  int node_index = 0;

  void build_tree(node& root, int left, int right) {
    if (left == right) {
      root.init(left, right, nullptr, nullptr);
      root.init_value(0);
      return;
    }
    int mid = (left + right) >> 1, lhs = node_index++, rhs = node_index++;
    build_tree(tree[lhs], left, mid);
    build_tree(tree[rhs], mid + 1, right);
    root.init(left, right, &tree[lhs], &tree[rhs]);
    root.init_value(0);
    root.merge_node();
  }

  void update_(node& root, int u, int v, const num_t& value) {
    if (u > root.right_index || v < root.left_index) return;
    if (u <= root.left_index && root.right_index <= v) {
      root.push_down(value);
    } else {
      root.lazy_update();
      update_(*root.left_child, u, v, value);
      update_(*root.right_child, u, v, value);
      root.merge_node();
    }
  }

  num_t get(node& root, int u, int v) {
    if (u <= root.left_index && root.right_index <= v) return root.value;
    if (u > root.right_index || v < root.left_index) return node::nil;
    root.lazy_update();
    auto lhs = get(*root.left_child, u, v);
    auto rhs = get(*root.right_child, u, v);
    return max(lhs, rhs);
  }
};

SegmentTree<int> segment_tree;
int n, r;
vector<pair<int, int>> points;

void solve() {
  cin >> n >> r;
  points.resize(n);
  for (auto& p : points) cin >> p.first >> p.second;

  for (auto& p : points) {
    auto temp = p;
    p.first = temp.first - temp.second;
    p.second = temp.first + temp.second;
  }
  r *= 2;
  const int BOUND = 2000000 + 7;
  segment_tree.init(-BOUND, BOUND);
  sort(points.begin(), points.end());
  int res = 0;
  int last = 0;
  for (int i = 0; i < n;) {
    int nxt_i = i;
    while (nxt_i < n && points[nxt_i].first == points[i].first) {
      int index = points[nxt_i].second;
      segment_tree.update(index, index + r, 1);
      ++nxt_i;
    }
    while (last < i && points[last].first + r < points[i].first) {
      int index = points[last].second;
      segment_tree.update(index, index + r, -1);
      ++last;
    }
    i = nxt_i;
    update_max(res, segment_tree.get(-BOUND, BOUND));
  }
  cout << res << '\n';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
  freopen("in.txt", "r", stdin);
#endif
//  freopen("out.txt", "w", stdout);
  const bool multiple_test = false;
  int test = 1;
  if (multiple_test)
    cin >> test;

  for(int i = 0; i < test; ++i) {
//    cout << "Case #" << i + 1 << ": ";
    solve();
  }
#ifdef _LOCAL_
  cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
#endif
}