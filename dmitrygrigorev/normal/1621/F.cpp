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

struct FenwickTree1 {

  vector<ll> t;
  int MAX_SIZE;

  // Sum [0..v]
  ll get(int v) {
    if (v < 0) return 0;
    ll res = 0;
    for (; v >= 0; v = (v & (v + 1)) - 1) {
      res += t[v];
    }
    return res;
  }

  FenwickTree1(int n) {
    MAX_SIZE = 2*n;
    t.assign(2*n, 0);
  }

  // Sum [vl..vr]
  bool get(int vl, int vr) {
    ll res = get(vr);
    if (vl > 0) {
      res -= get(vl - 1);
    }
    return (res == vr - vl + 1);
  }

  // Update t[v] += val;
  void up(int v, int val) {
    for (; v < MAX_SIZE; v = v | (v + 1)) {
      t[v] += val;
    }
  }
};

db eps = 1e-9;

int bs(vector<db> &groups, db x) {
  int L = 0, R = groups.size() + 1;
  while (R-L>1) {
    int M = (L+R)/2;
    if (groups[M - 1] > x + eps) L = M;
    else R = M;
  }

  return L;

}

void solve() {

  int n, a, b, c;

  cin >> n >> a >> b >> c;

  string s;
  cin >> s;

  vector<pair<char, int> > st;
  st.pb(mp(s[0], 1));

  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == s[i - 1]) {
      st.back().y++;
    }
    else st.pb(mp(s[i], 1));
  }

  vector<int> edge, middle;
  
  int ones = 0;
  int await = 0;

  for (int i = 0; i < st.size(); ++i) {
    if (st[i].x == '1') {
      ones += st[i].y - 1;
    }
    else {
      if (i == 0 || i + 1 == st.size()) edge.pb(st[i].y);
      else middle.pb(st[i].y);
    }
  }

  sort(all(edge), greater<int>());
  sort(all(middle), greater<int>());

  ll ans = 0;  

  for (int start = 0; start < 2; ++start) {

    int move = start;

    auto A = edge, B = middle;
    int C = ones;

    ll cur = 0;
    while (true) {
     // per(start, move, cur, ones, await, middle, edge);
      if (move == 1) {
        if (ones > 0) {
          ones--;
          cur += b;
        }
        else break;
      }
      else {

        if ((edge.size() && edge[0] > 1) || (middle.size() && middle[0] > 1)) {
          ans = max(ans, cur + a);
        }

        bool made = false;

        if (ones == 0) {
          while (middle.size()) {
            if (middle.back() == 1) {
              await++;
              middle.pop_back();
            }
            else break;
          }
          if (await) {
            await--;
            ones++;
            cur -= c;
            made = true;
          }
        }

        if (!made) {

          while (middle.size()) {
            if (middle.back() == 1) {
              await++;
              middle.pop_back();
            }
            else {
              cur += a;
              made = true;
              middle.back()--;
              break;
            }
          }

         // per(made, await);

          if (!made) {
            if (edge.size() == 2 && edge[1] > 1) {
              edge[1]--;
              cur += a;
              made = true;
            }
            if (!made) {
              if (edge.size() >= 1 && edge[0] > 1) {
                edge[0]--;
                cur += a;
                made = true;
              }
              if (!made) {
                if (await) {
                  await--;
                  ones++;
                  cur -= c;
                  made = true;
                }
                if (!made) {
                  if (edge.size()) {
                    edge.pop_back();
                    cur -= c;
                    made = true;
                  }
                }
              }
            }
          }
        }

        if (!made) break;

      }

      move ^= 1;
      ans = max(ans, cur);

    }

    edge = A;
    middle = B;
    ones = C;
    await = 0;

  }

  cout << ans << '\n';




}

int main(){
#ifdef LOCAL
  freopen("B_input.txt", "r", stdin);
  //freopen("B_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}