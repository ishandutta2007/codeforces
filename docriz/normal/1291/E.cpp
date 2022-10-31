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

void my_main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  s = "#" + s;
  vector<vector<int>> lamp(n + 1);
  rep(i, 1, k + 1) {
    int c;
    cin >> c;
    while (c--) {
      int id;
      cin >> id;
      lamp[id].pb(i);
    }
  }
  rep(i, 1, n + 1) {
    assert(sz(lamp[i]) <= 2);
    /*
    cerr << i << ": ";
    for (auto l: lamp[i]) cerr << l << " ";
    cerr << endl;
    */
  }
  auto fa = VI(k + 1);
  vector<vector<int>> S(k + 1);
  auto cnt0 = VI(k + 1);
  auto v = VI(k + 1);
  auto done = VI(k + 1);
  auto ans = VI(k + 1);
  rep(i, 1, k + 1) {
    fa[i] = i;
    S[i].pb(i);
    cnt0[i] = 1; // cnt1[i] = 0;
    v[i] = 0;
    done[i] = -1;
    ans[i] = min(cnt0[i], sz(S[i]) - cnt0[i]);
  }
  int cur_ans = 0;
  rep(i, 1, n + 1) {
    // debug(i);
    if (sz(lamp[i]) == 0) {
      assert(s[i] == '1');
    } else if (sz(lamp[i]) == 1) {
      int cur = lamp[i][0];
      int f = fa[cur];
      int cur_val = (s[i] == '1') ? 0 : 1;
      int root_val = (cur_val ^ v[cur]);
      if (done[f] != -1) {
        assert(root_val == done[f]);
        // continue;
      } else {
        cur_ans -= ans[f];
        done[f] = root_val;
        if (root_val) {
          ans[f] = cnt0[f];
        } else {
          ans[f] = sz(S[f]) - cnt0[f];
        }
        cur_ans += ans[f];
      }
    } else {
      int a = lamp[i][0], b = lamp[i][1];
      int f_a = fa[a], f_b = fa[b];
      if (f_a == f_b) {
        // continue;
      } else {
        if (sz(S[f_a]) > sz(S[f_b])) {
          swap(a, b);
          swap(f_a, f_b);
        }
        cur_ans -= ans[f_a];
        cur_ans -= ans[f_b];
        int z = (v[a] ^ v[b] ^ ((s[i] == '1') ? 0 : 1));
        for (auto p: S[f_a]) {
          S[f_b].pb(p);
          v[p] ^= z;
          fa[p] = f_b;
          if (v[p] == 0) ++cnt0[f_b];
        }
        if (done[f_b] != -1) {
          if (done[f_a] != -1) {
            assert((done[f_a] ^ z) == done[f_b]);
          }
          if (done[f_b]) {
            ans[f_b] = cnt0[f_b];
          } else {
            ans[f_b] = sz(S[f_b]) - cnt0[f_b];
          }
        } else {
          if (done[f_a] != -1) {
            done[f_b] = (done[f_a] ^ z);
            if (done[f_b]) {
              ans[f_b] = cnt0[f_b];
            } else {
              ans[f_b] = sz(S[f_b]) - cnt0[f_b];
            }
          } else {
            ans[f_b] = min(cnt0[f_b], sz(S[f_b]) - cnt0[f_b]);
          }
        }
        cur_ans += ans[f_b];
        S[f_a].clear();
      }
    }
    /*
    debug(cur_ans);
    rep(t, 1, k + 1) {
      cerr << fa[t] << " ";
    }
    cerr << endl;
    */
    cout << cur_ans << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  my_main();
  return 0;
}