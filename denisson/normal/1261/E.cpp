#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
using namespace std;
 
#define pper(a) cerr << #a << " = " << a << endl;
 
void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }
 
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
 
template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}
 
template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}
 
template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }
 
template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}
 
mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}
 
const int mod = 1000000007;
 
void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}
 
void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}
 
int mult(int a, int b) {
  return a * (ll)b % mod;
}
 
int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}
 
 
int res[1007][1007];
int n;
 
void solve(vector<int> a) {
 
  n = a.size();
 
  vector<pair<int, int> > t;
  for (int i = 0; i < n; ++i) t.pb(mp(a[i], i));
  for (int i = 0; i < n + 1; ++i) for (int j = 0; j < n; ++j) res[i][j] = 0;
  sort(all(t));
  reverse(all(t));
 
  vector<pair<int, int>> d;
  d.pb(mp(0, *max_element(all(a))));
 
  for (int i = 0; i < t.size(); ++i) {
    int v = t[i].y;
    int cnt = t[i].x;
 
    int ma_len = d[0].y - d[0].x + 1;
 
    for (int j = 1; j < d.size(); ++j) uax(ma_len, d[j].y - d[j].x + 1);

    int vl = 0, vr = ma_len;
    while (vl + 1 < vr) {
      int vm = (vl + vr) >> 1;
 
      int le = 0, ri = 0;
      int can = 1;
 
      for (auto [w1, w2] : d) {
        int len = w2 - w1 + 1;
        if (vm * 2 < len) can = 0;
        else if (vm >= len) {
          ri += len;
        } else {
          le += min(vm, len - vm);
          ri += max(vm, len - vm);
        }
      }
 
    // per("WTF:  ", v, le, ri, cnt);
 
      can &= (cnt >= le) && (cnt <= ri);
 
 
      if (can) vr = vm; else vl = vm;
 
    }
 
 
    vector<pair<int, int>> p;
 
    vector<int> used(d.size(), 0);
  
   // per("CNT: ", cnt);

    for (int j = 0; j < d.size(); ++j) {
        auto [w1, w2] = d[j];
 
        int len = w2 - w1 + 1;
        if (vr >= len) {
 
        } else {
        //  per("===== ", v, vr, len);
          used[j] += min(vr, len - vr);
          cnt -= used[j];
        }
 
    }

   // pper(vr);
   // pper(v);
   // pper(cnt);


 
    for (int j = 0; j < d.size(); ++j) {
        auto [w1, w2] = d[j];
 
        int len = w2 - w1 + 1;
        if (vr >= len) {
 
          while (cnt > 0 && used[j] + 1 <= len) {
            int now = max(used[j], len - used[j]);
            int now2 = max(used[j] + 1,  len  - 1- used[j]);
            if (now2 < now) {
              ++used[j];--cnt;
            } else break;
          }
 
        } else {
          int ca = max(vr, len - vr);
          while (cnt > 0 && used[j] + 1 <= ca) {
 
            int now = max(used[j], len - used[j]);
            int now2 = max(used[j] + 1,  len  - 1- used[j]);
            if (now2 < now) {
              ++used[j];--cnt;
            } else break;
 
          }
        }
 
    }

    for (int j = 0; j < d.size(); ++j) {
        auto [w1, w2] = d[j];
 
        int len = w2 - w1 + 1;
        if (vr >= len) {
 
          while (cnt > 0 && used[j] + 1 <= len) {
            ++used[j];--cnt;
          }
 
        } else {
          int ca = max(vr, len - vr);
          while (cnt > 0 && used[j] + 1 <= ca) {
            ++used[j];--cnt;
          }
        }
 
    }
 
 
//    per(used);
  //  per(d);
//
 
 
    for (int j = 0; j < d.size(); ++j) {
        auto [w1, w2] = d[j];
 
        int len = w2 - w1 + 1;
 
        if (used[j] == len) {
 
          for (int s = w1; s <= w2; ++s) res[s][v] = 1;
 
          p.pb(d[j]);
        } else if (used[j] == 0) {
 
          p.pb(d[j]);
 
        } else {
          p.pb(mp(w1, w1 + used[j] - 1));
          p.pb(mp(w1 + used[j], w2));
 
          for (int s = w1; s <= w1 + used[j] - 1; ++s) res[s][v] = 1;
 
        }
 
    }
 
 
 
 
    swap(d, p);
 
  }
 

  for (auto [w1, w2] : d) {
    if (w1 != w2) while (1) {
 
    }
  } 
 
  int ans = 0;
  
  for (int i = 0; i < n + 1; ++i) {
    int was = 0;
    for (int j = 0; j < n; ++j) was += res[i][j];
    if (was != 0) ans++;
  }
 
  cout << ans << "\n";
 
 
  for (int i = 0; i < n + 1; ++i) {
    int was = 0;
    for (int j = 0; j < n; ++j) was += res[i][j];
    if (was) {
      for (int j = 0; j < n; ++j) cout << res[i][j], a[j] -= res[i][j];
      cout << "\n";
    }
  }

  for (int i = 0; i < n; ++i) if (a[i] != 0) while (1) {}
 
}
 
int main(){
#ifdef LOCAL
  freopen("A_input.txt", "r", stdin);
  //freopen("E_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int n;
  cin >> n;
  vector<int> a(n);
  readArr(all(a));
 
  solve(a);
 
}