#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using PII = pair<int, int>;
using PIL = pair<int, ll>;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define VI(n) vector<int>(n)
#define VII(n, m) vector<vector<int>>(n, vector<int>(m))
#define VIII(n, m, p) vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(p)))

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

/*
  find the biggest x that check(x) is true.
  time complexity: O(log(r-l))
  space commplexity: O(1)
*/
int bs_biggest(int l, int r, function<bool(int)> check) {
  assert(l <= r);
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid)) l = mid; else r = mid - 1;
  }
  return l;
}

/*
  find the smallest x that check(x) is true.
  time complexity: O(log(r-l))
  space commplexity: O(1)
*/
int bs_smallest(int l, int r, function<bool(int)> check) {
  assert(l <= r);
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid; else l = mid + 1;
  }
  return l;
}

ll gcd(ll a, ll b) { 
  return b ? gcd(b, a % b) : a;
}

/*
  example:
    BIT<int> b1(5);
    b1.add(3, 10);
    b1.add(1, 7);
    debug(b1.query(1, 3)); // should be 17
    debug(b1.query(2, 3)); // should be 10
*/
template<typename T>
struct BIT {
  int n;
  vector<T> c;

  BIT(int _n) {
    n = _n;
    c.resize(n + 1);
  }

  void add(int p, T v) {
    assert(p >= 1 && p <= n);
    for (; p <= n; p += p & -p) c[p] += v;
  };

  T sum(int p) {
    T ret = 0;
    for (; p >= 1; p -= p & -p) ret += c[p];
    return ret;
  };

  T query(int l, int r) {
    assert(l <= r && r <= n && l >= 1);
    return sum(r) - sum(l - 1);
  };
};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename T>
struct BBT {
  using BST = tree<pair<T, int>, null_type, less<pair<T, int>>, 
                   rb_tree_tag, tree_order_statistics_node_update>;
  //  CE null_type  null_mapped_type
  map<T, int> M;
  BST B;
  size_t size() {
    return B.size();
  }
  void insert(int x) {
    M[x]++, B.insert(make_pair(x, M[x]));
  }
  void erase(int x) {
    if(M[x]) B.erase(make_pair(x, M[x])), M[x]--;
  }
  int query(int x) { //  <=x 
    return B.order_of_key(make_pair(x + 1, -1));
  }
  int kth(int k) { //  k  (1-based)
    return (*B.find_by_order(k - 1)).first;
  }
  void clear() {
    M.clear(); B.clear();
  }
};

void my_main() {
  int n;
  cin >> n;
  auto per = VI(n + 1);
  auto pos = VI(n + 1);
  rep(i, 1, n + 1) {
    cin >> per[i];
    pos[per[i]] = i;
  }
  BBT<int> bbt;
  BIT<int> bit(n);
  BIT<int> bit2(n);
  ll cur_ans1 = 0;
  ll cur_ans2 = 0;
  rep(i, 1, n + 1) {
    int p = pos[i];
    if (i > 1) {
      int pref_ones = bit.query(1, p);
      int suff_ones = i - 1 - pref_ones;
      cur_ans1 -= min(pref_ones, suff_ones);
      int med_p = bbt.kth(i / 2);
      if (p + 1 <= med_p - 1) {
        int ones = bit.query(p + 1, med_p - 1);
        int zeros = med_p - p - 1 - ones;
        cur_ans1 += zeros;
      } else {
        if ((i - 1) & 1) {
          // do nothing
        } else {
          med_p = bbt.kth(i / 2 + 1);
        }
        if (med_p + 1 <= p - 1) {
          int ones = bit.query(med_p + 1, p - 1);
          int zeros = p - 1 - med_p - ones;
          cur_ans1 += zeros;
        }
      }
      if (p < n) {
        cur_ans2 += bit2.query(p + 1, n);
      }
    }
    bbt.insert(p);
    bit.add(p, 1);
    bit2.add(p, 1);
    cout << cur_ans1 + cur_ans2 << " \n"[i == n];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  my_main();
  return 0;
}