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
  int T;
  cin >> T;
  while (T--) {
    int n, t, a, b;
    cin >> n >> t >> a >> b;
    struct P {
      int type;
      int t;
      bool operator<(const P& rhs) const {
        return t < rhs.t;
      }
    };
    vector<P> p(n + 2);
    p[0].t = -1;
    rep(i, 1, n + 1) cin >> p[i].type;
    rep(i, 1, n + 1) cin >> p[i].t;
    p[++n] = {2, t + 1};
    sort(p.begin() + 1, p.end());
    int tot_easy = 0;
    int tot_hard = 0;
    rep(i, 1, n + 1) {
      if (p[i].type == 0) ++tot_easy;
      else if (p[i].type == 1) ++tot_hard;
    }
    // debug(tot_easy, tot_hard);
    int easy_req = 0;
    int hard_req = 0;
    int ans = 0;
    rep(i, 1, n + 1) {
      // debug(p[i].type, p[i].t);
      if (p[i].t != p[i - 1].t) {
        // leave at p[i].t-1
        ll need = (ll)easy_req * a + (ll)hard_req * b;
        int cur_time = p[i].t - 1;
        // debug(cur_time);
        if (need > cur_time) {

        } else {
          // debug(i, easy_req, hard_req);
          int cur_ans = easy_req + hard_req;
          int easy = tot_easy - easy_req;
          int hard = tot_hard - hard_req;
          if (need + (ll)easy * a <= cur_time) {
            cur_ans += easy;
            need += (ll)easy * a;
            int time_left = cur_time - need;
            cur_ans += min(hard, time_left / b);
          } else {
            int time_left = cur_time - need;
            cur_ans += min(easy, time_left / a);
          }
          ans = max(ans, cur_ans);
        }
      }
      if (p[i].type == 0) {
        ++easy_req;
      } else {
        ++hard_req;
      }
    }
    cout << ans << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  my_main();
  return 0;
}