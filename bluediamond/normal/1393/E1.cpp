#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int pw(int a, int b, int mod) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = (ll) r * a % mod;
    }
    a = (ll) a * a % mod;
    b /= 2;
  }
  return r;
}

int dv(int a, int b, int mod) {
  return (ll) a * pw(b, mod - 2, mod) % mod;
}

const int C = 2;
const int mods[] = {1000000271, 1000000787, 1000000931};

struct T {
  int first, second;
};

bool operator < (T f, T s) {
  if (f.first != s.first) {
    return f.first < s.first;
  }
  return f.second < s.second;
}

T operator + (T f, T s) {
  f.first += s.first;
  if (f.first >= mods[0]) {
    f.first -= mods[0];
  }
  f.second += s.second;
  if (f.second >= mods[1]) {
    f.second -= mods[1];
  }
  return f;
}

T operator - (T f, T s) {
  f.first -= s.first;
  if (f.first < 0) {
    f.first += mods[0];
  }
  f.second -= s.second;
  if (f.second < 0) {
    f.second += mods[1];
  }
  return f;
}

T operator * (T f, T s) {
  f.first = (ll) f.first * s.first % mods[0];
  f.second = (ll) f.second * s.second % mods[1];
  return f;
}

T operator ^ (T f, int x) {
  f.first = pw(f.first, x, mods[0]);
  f.second = pw(f.second, x, mods[1]);
  return f;
}

T operator / (T f, T s) {
  f.first = dv(f.first, s.first, mods[0]);
  f.second = dv(f.second, s.second, mods[1]);
  return f;
}

bool operator == (T f, T s) {
  return (f.first == s.first && f.second == s.second);
}

const int K = (int) 1e6 + 7;
T kwk[K], iki[K];

struct magma {
  vector<T> lol;
  int ln;
  void init(string s) {
    ln = (int) s.size();
    lol.resize(ln + 1);
    for (int j = 0; j < ln; j++) {
      T now;
      now.first = now.second = s[j] - 'a';
      lol[j + 1] = lol[j] + now * kwk[j + 1];
    }
  }
  T get(int l, int r) {
    l++;
    r++;
    T sol = lol[r] - lol[l - 1];
    sol = sol * iki[l - 1];
    return sol;
  }
  T get_skip(int skp, int i) {
    if (i < skp) {
      return get(0, i);
    } else {
      T a = get(0, skp - 1);
      T b = get(skp + 1, i + 1);
      return a + b * kwk[skp];
    }
  }
  T get_pos(int skp, int i) {
    if (i < skp) {
      return get(i, i);
    } else {
      return get(i + 1, i + 1);
    }
  }
};

void upd(vector<int> x) {
  for (auto &it : x) {
    if (it == -1) {
      return;
    }
  }
  vector<int> y = x;
  sort(y.begin(), y.end());
  for (int i = 1; i < (int) y.size(); i++) {
    if (y[i] == y[i - 1]) {
      return;
    }
  }
  cout << "YES\n";
  for (auto &it : x) {
    cout << it << " ";
  }
  cout << "\n";
  exit(0);
}

vector<int> get_sorted(string s) {
  int n = (int) s.size();
  vector<int> nd(n);
  nd[n - 1] = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    if (s[i] == s[i + 1]) {
      nd[i] = nd[i + 1];
    } else {
      nd[i] = i + 1;
    }
  }
  vector<int> sol(n);
  int l = 0, r = n - 1;
  for (int i = 0; i < n; i++) {
    if (s[nd[i]] <= s[i]) {
      sol[l++] = i;
    } else {
      sol[r--] = i;
    }
  }
  vector<int> ret;
  for (auto &it : sol) {
    ret.push_back(it);
    if (it == n - 1) {
      ret.push_back(n);
    }
  }
  return ret;
}

vector<int> get_sorted_smart(string s) {
  int n = (int) s.size();
  vector<pair<string, int>> vec;
  vec.push_back({s, n});
  for (int j = 0; j < n; j++) {
    string t;
    for (int i = 0; i < n; i++) {
      if (i != j) {
        t += s[i];
      }
    }
    vec.push_back({t, j});
  }
  sort(vec.begin(), vec.end());
  vector<int> sol;
  for (auto &it : vec) {
    sol.push_back(it.second);
  }
  return sol;
}

const int N = (int) 1e5 + 7;
const int MOD = (int) 1e9 + 7;
int n;
string a[N];
magma b[N];
vector<int> so[N];

int comp(int i, int skp1, int skp2) {
  int ln1 = (int) a[i].size() - (skp1 < (int) a[i].size());
  int ln2 = (int) a[i + 1].size() - (skp2 < (int) a[i + 1].size());
  int com = 0, lo = 1, hi = min(ln1, ln2);
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (b[i].get_skip(skp1, mid - 1) == b[i + 1].get_skip(skp2, mid - 1)) {
      com = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  if (com == min(ln1, ln2)) {
    if (ln1 == ln2) {
      return 0;
    }
    if (ln1 < ln2) {
      return 1;
    } else {
      return 2;
    }
  }
  if (b[i].get_pos(skp1, com) < b[i + 1].get_pos(skp2, com)) {
    return 1;
  } else {
    return 2;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  T p26;
  p26.first = p26.second = 26;
  kwk[0].first = kwk[0].second = 1;
  for (int j = 1; j < K; j++) {
    kwk[j] = kwk[j - 1] * p26;
  }
  iki[K - 1] = kwk[0] / kwk[K - 1];
  for (int j = K - 2; j >= 0; j--) {
    iki[j] = iki[j + 1] * kwk[1];
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    so[i] = get_sorted(a[i]);
    b[i].init(a[i]);
  }
  vector<int> dp((int) so[1].size(), 1);
  for (int i = 2; i <= n; i++) {
    vector<int> ndp((int) so[i].size(), 0);
    int pos = 0, sum = 0;
    for (int k = 0; k < (int) so[i].size(); k++) {
      while (pos < (int) so[i - 1].size() && comp(i - 1, so[i - 1][pos], so[i][k]) <= 1) {
        sum = (sum + dp[pos]) % MOD;
        pos++;
      }
      ndp[k] = sum;
    }
    dp = ndp;
  }
  int sol = 0;
  for (auto &it : dp) {
    sol = (sol + it) % MOD;
  }
  cout << sol << "\n";
  return 0;
}