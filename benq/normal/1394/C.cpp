/**
 *    author:  tourist
 *    created: 12.08.2020 17:47:26       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
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
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  const int inf = (int) 1e8;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (char c : s) {
      if (c == 'B') {
        ++x[i];
      } else {
        ++y[i];
      }
    }
  }
  int px = -1, py = -1;
  int low = 0, high = inf;
  while (low <= high) {
    int mid = (low + high) >> 1;
    int mind = -inf;
    int maxd = inf;
    int minx = 0;
    int maxx = inf;
    int miny = 0;
    int maxy = inf;
    for (int i = 0; i < n; i++) {
      mind = max(mind, x[i] - y[i] - mid);
      maxd = min(maxd, x[i] - y[i] + mid);
      minx = max(minx, x[i] - mid);
      maxx = min(maxx, x[i] + mid);
      miny = max(miny, y[i] - mid);
      maxy = min(maxy, y[i] + mid);
    }
    bool ok = false;
    if (mind <= maxd && minx <= maxx && miny <= maxy) {
      for (int rot = 0; rot < 3; rot++) {
        int x = (rot == 0 ? minx : (rot == 1 ? min(maxx, minx + 1) : maxx));
        int from = max(miny, x-maxd);
        int to = min(maxy, x-mind);
        if (x == 0) {
          from = max(from, 1);
        }
        if (from <= to) {
          ok = true;
          px = x;
          py = from;
        }
      }
      for (int rot = 0; rot < 3; rot++) {
        int y = (rot == 0 ? miny : (rot == 1 ? min(maxy, miny + 1) : maxy));
        int from = max(minx, mind + y);
        int to = min(maxx, maxd + y);
        if (y == 0) {
          from = max(from, 1);
        }
        if (from <= to) {
          ok = true;
          px = from;
          py = y;
        }
      }
    }
    if (low == high) {
      assert(ok);
      break;
    }
    if (ok) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << low << '\n';
  for (int i = 0; i < px; i++) {
    cout << 'B';
  }
  for (int i = 0; i < py; i++) {
    cout << 'N';
  }
  cout << '\n';
  return 0;
}