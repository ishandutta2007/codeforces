#include <bits/stdc++.h>

using namespace std;

template <class T> void mini(T &l, T r) {l = min(l, r);}
template <class T> void maxi(T &l, T r) {l = max(l, r);}

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(bool a) {
  return a ? "T" : "F";
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
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

using ll = long long;
using ld = long double;

void run() {
  int t, x;
  cin >> t;
  while (t--) {
    cin >> x;
    if (x == 0) {
      cout << "1 1" << endl;
      continue;
    }
    int n = -1, m = -1, k = -1;
    for (int i = 1; i * i <= x; ++i) if (x % i == 0) {
      n = -1, m = -1, k = -1;
      if (((i & 1) && ((x / i) & 1)) || (!(i & 1) && !((x / i) & 1))) {
        n = (i + x / i) / 2;
        k = (x / i - i) / 2;
        if (k != 0) {
          m = n / k;
        }
        if (k != n / m) {
          n = -1;
          m = -1;
        }
      }
      if (n != -1 && m != -1) break;
    }
    if (n != -1 && m != -1) {
      cout << n << " " << m << endl;
    } else {
      cout << "-1" << endl;
    }
  }
}

int main() {
  run();
  return 0;
}