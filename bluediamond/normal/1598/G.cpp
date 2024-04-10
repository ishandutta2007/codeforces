#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll

bool prime(int x) {
  if (x <= 1) return 0;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}

const int C = 3;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int mods[C];

struct T {
  int a;
  int b;
  int c;
};

T add(T ff, T ss) {
  ff.a += ss.a;
  ff.b += ss.b;
  ff.c += ss.c;
  if (ff.a >= mods[0]) ff.a -= mods[0];
  if (ff.b >= mods[1]) ff.b -= mods[1];
  if (ff.c >= mods[2]) ff.c -= mods[2];
  return ff;
}

T sub(T ff, T ss) {
  ff.a -= ss.a;
  ff.b -= ss.b;
  ff.c -= ss.c;
  if (ff.a < 0) ff.a += mods[0];
  if (ff.b < 0) ff.b += mods[1];
  if (ff.c < 0) ff.c += mods[2];
  return ff;
}

T mul(T ff, T ss) {
  ff.a = (ll) ff.a * ss.a % mods[0];
  ff.b = (ll) ff.b * ss.b % mods[1];
  ff.c = (ll) ff.c * ss.c % mods[2];
  return ff;
}


int piwi(int a, int b, int mod) {
  int r = 1;
  while (b) {
    if (b & 1) r = (ll) r * a % mod;
    a = (ll)a * a % mod;
    b /= 2;
  }
  return r;
}

T divi(T ff, T ss) {
  ff.a = (ll) ff.a * piwi(ss.a, mods[0] - 2, mods[0]) % mods[0];
  ff.b = (ll) ff.b * piwi(ss.b, mods[1] - 2, mods[1]) % mods[1];
  ff.c = (ll) ff.c * piwi(ss.c, mods[2] - 2, mods[2]) % mods[2];
  return ff;
}

const int N = (int) 5e5 + 7;
string s, t;
int n;
T src;
T put[N], inv[N];
T pref[N];

T get(int l, int r) {
  return mul(sub(pref[r], pref[l - 1]), inv[n - r]);
}

void print(vector<int> v) {
  cout << " ---> ";
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << "\n";
}

bool operator < (T ff, T ss) {
  if (ff.a != ss.a) return ff.a < ss.a;
  if (ff.b != ss.b) return ff.b < ss.b;
  return ff.c < ss.c;
}

map<T, int> first;
//map<vector<int>, int> last;

T tt[N];

vector<int> nanjing(string s) {
  int n = (int) s.size(), l = -1, r = -1;
  vector<int> z(n, 0);
  for (int i = 1; i < n; i++) {
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }
    while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
      z[i]++;
    }
    if (z[i] && i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}

void st(T &sol, int x) {
  sol.a = sol.b = x;
}

bool operator == (T ff, T ss) {
  return ff.a == ss.a && ff.b == ss.b;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

/**  string aa = "ababac";
  print(nanjing(aa));
  return 0;**/

  //freopen ("input", "r", stdin);
  vector<int> primes;

  for (int i = 1; i <= (int) 1e5; i++) { /// schimb la (int) 1e5
    if (prime((int) 1e9 + i)) {
      primes.push_back((int) 1e9 + i);
    }
  }
  shuffle(primes.begin(), primes.end(), rng);

  for (int i = 0; i < C; i++) {
    mods[i] = primes[i];
  }

  st(put[0], 1);
  st(put[1], 10);

  for (int i = 2; i < N; i++) {
    put[i] = mul(put[i - 1], put[1]);
  }

  inv[N - 1] = divi(put[0], put[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    inv[i] = mul(inv[i + 1], put[1]);
  }

  cin >> s >> t;
  vector<int> lol = nanjing(t + "#" + s);
  n = (int) s.size();
  for (int i = 1; i <= n; i++) {
    T now;
    st(now, s[i - 1] - '0');
    pref[i] = add(pref[i - 1], mul(put[n - i], now));
    first[pref[i - 1]] = i;
  }

  for (int i = 1; i <= (int) t.size(); i++) {
    T now;
    st(now, t[i - 1] - '0');
    src = add(src, mul(put[(int) t.size() - i], now));
    tt[i] = src;
  }


  for (int l2 = 1; l2 <= n; l2++) {
    vector<int> r2s = {l2 + (int) t.size() - 2, l2 + (int) t.size() - 1};
    for (auto &r2 : r2s) {
      if (r2 < l2 || r2 > n) continue;
      int r1 = l2 - 1;
      T x = sub(pref[r1], mul(put[n - r1], sub(src, get(l2, r2))));
      if (first.count(x) && first[x] <= r1) {
        cout << first[x] << " " << r1 << "\n";
        cout << l2 << " " << r2 << "\n";
        return 0;
      }
    }
  }

  for (int l1 = 1; l1 <= n; l1++) {
    vector<int> r1s = {l1 + (int) t.size() - 2, l1 + (int) t.size() - 1};
    for (auto &r1 : r1s) {
      if (r1 < l1 || r1 > n) continue;
      int l2 = r1 + 1;
      if (r1 == l1 + (int) t.size() - 2) {
        int r2 = l2 + (int) t.size() - 2;
        if (r2 > n) continue;
        T sum = add(get(l1, r1), get(l2, r2));
        if (sum == src) {
          cout << l1 << " " << r1 << "\n";
          cout << l2 << " " << r2 << "\n";
          return 0;
        }
        continue;
      }
      assert(r1 - l1 + 1 == (int) t.size());
      int cnt = (int) t.size() - lol[l1 + (int) t.size()];


      for (int r2 = max(l2, l2 + cnt - 2); r2 <= min(l2 + cnt + 1, n); r2++) {
        T sum = add(get(l1, r1), get(l2, r2));

        if (sum == src) {
          cout << l1 << " " << r1 << "\n";
          cout << l2 << " " << r2 << "\n";
          return 0;
        }
      }
    }
  }


  assert(0);

  return 0;



  assert(0);







  return 0;
}