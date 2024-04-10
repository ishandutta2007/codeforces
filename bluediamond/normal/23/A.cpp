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

const int C = 3;
const int mods[] = {1000000271, 1000000787, 1000000931};

struct T {
  int a[C];
  T() {
    for (int j = 0; j < C; j++) {
      a[j] = 0;
    }
  }
};

bool operator < (T f, T s) {
  for (int i = 0; i < C; i++) {
    if (f.a[i] != s.a[i]) {
      return f.a[i] < s.a[i];
    }
  }
  return 0;
}

T operator + (T f, T s) {
  for (int j = 0; j < C; j++) {
    f.a[j] += s.a[j];
    if (f.a[j] >= mods[j]) {
      f.a[j] -= mods[j];
    }
  }
  return f;
}

T operator - (T f, T s) {
  for (int j = 0; j < C; j++) {
    f.a[j] -= s.a[j];
    if (f.a[j] < 0) {
      f.a[j] += mods[j];
    }
  }
  return f;
}

T operator * (T f, T s) {
  for (int j = 0; j < C; j++) {
    f.a[j] = (ll) f.a[j] * s.a[j] % mods[j];
  }
  return f;
}

T operator ^ (T f, int x) {
  for (int j = 0; j < C; j++) {
    f.a[j] = pw(f.a[j], x, mods[j]);
  }
  return f;
}

T operator / (T f, T s) {
  for (int j = 0; j < C; j++) {
    f.a[j] = dv(f.a[j], s.a[j], mods[j]);
  }
  return f;
}

bool operator == (T f, T s) {
  for (int j = 0; j < C; j++) {
    if (f.a[j] != s.a[j]) {
      return 0;
    }
  }
  return 1;
}

struct magma {
  vector<T> lol;
  T cur, p26;
  int ln;
  magma(string s) {
    ln = (int) s.size();
    lol.resize(ln + 1);
    for (int j = 0; j < C; j++) {
      cur.a[j] = 1;
      p26.a[j] = 26;
    }
    for (int j = 0; j < ln; j++) {
      T now;
      for (int k = 0; k < C; k++) {
        now.a[k] = s[j] - 'a';
      }
      cur = cur * p26;
      lol[j + 1] = lol[j] + now * cur;
    }
  }
  T get(int l, int r) {
    l++;
    r++;
    T sol = lol[r] - lol[l - 1];
    T val = p26 ^ (l - 1);
    sol = sol / val;
    return sol;
  }
};

int n;
string s;

bool check(int l)
{
    magma b(s);
    set<T> st;
    for (int i = 0; i + l - 1 < n; i++)
    {
        T it = b.get(i, i + l - 1);
        if (st.count(it))
        {
            return 1;
        }
        st.insert(it);
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> s;
    n = (int) s.size();
    int l = 1, r = n, sol = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (check(m))
        {
            sol = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    cout << sol << "\n";
}