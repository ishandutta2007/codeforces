#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long long ll;

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, ll b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int &a, int b) {
  a = add(a, b);
}

void mulup(int &a, int b) {
  a = mul(a, b);
}



class Number {
public:
  int a;
  int b;

  Number(int a, int b) : a(a), b(b) {
  }


  void operator = (Number other) {
    a = other.a;
    b = other.b;
  }
}; /// n = (a + sqrt(5) * b)

Number operator + (Number x, Number y) {
  x.a = add(x.a, y.a);
  x.b = add(x.b, y.b);
  return x;
}

Number operator - (Number x, Number y) {
  x.a = add(x.a, -y.a);
  x.b = add(x.b, -y.b);
  return x;
}

Number operator * (Number x, Number y) {
  int aa, bb;
  aa = add(mul(5, mul(x.b, y.b)), mul(x.a, y.a));
  bb = add(mul(x.a, y.b), mul(x.b, y.a));
  x.a = aa;
  x.b = bb;
  return x;
}

Number operator ^ (Number a, ll b) {
  Number sol(1, 0);
  while (b) {
    if (b & 1) {
      sol = sol * a;
    }
    a = a * a;
    b /= 2;
  }
  return sol;
}

Number operator / (Number x, ll value) {
  x.a = dv(x.a, value);
  x.b = dv(x.b, value);
  return x;
}

Number sqrt5(0, 1);
Number a(dv(1, 2), dv(1, 2)), b(dv(1, 2), add(0, -dv(1, 2)));

Number binet(ll n) {
  Number sol = (a ^ n) - (b ^ n);
  sol = sol * sqrt5;
  sol = sol / 5;
  return sol;
}

vector<int> mult(vector<int> a, vector<int> b) {
  vector<int> c((int) a.size() + (int) b.size(), 0);

  for (int i = 0; i < (int) a.size(); i++) {
    for (int j = 0; j < (int) b.size(); j++) {
      addup(c[i + j], mul(a[i], b[j]));
    }
  }

  while (!c.empty() && c.back() == 0) {
    c.pop_back();
  }
  return c;
}

vector<int> getCombCoefs(int k) {
  vector<int> all = {1};
  int under = 1;
  for (int i = 1; i <= k; i++) {
    all = mult(all, {add(i, -k), 1});
    mulup(under, i);
  }
  under = dv(1, under);
  for (auto &x : all) {
    mulup(x, under);
  }
  return all;
}

Number operator / (Number x, Number y) {
  y.b = add(0, -y.b);
  x = x * y;
  int under = add(mul(y.a, y.a), -mul(5, mul(y.b, y.b)));
  return x / under;
}

int comb[300][300];

Number pref(ll limit, int k) {
  vector<int> coefs = getCombCoefs(k);
  assert((int) coefs.size() == k + 1);
  Number print(0, 0);
  for (int j = 0; j <= k; j++) {
    Number currentj(0, 0);
    for (int k = 0; k <= j; k++) {
      Number sol(0, 0);
      Number unity = (a ^ k) * (b ^ (j - k));

      for (ll i = 1; i <= limit; i++) {break;
        sol = sol + (unity ^ i);
      }

     // a^0+...+a^n=(a^(n+1)-1)/(a-1)

      Number val = ((unity ^ (limit + 1)) - Number(1, 0));


      if (unity.a == 1 && unity.b == 0) {
        val = Number(limit % M, 0);
       // cout << "fr\n";
      } else {
     //   cout << "cobai\n";
        val = val / (unity - Number(1, 0));
        val.a = add(val.a, -1);
      }


      sol = val;


      if (sol.a != val.a || sol.b != val.b) {
        cout << unity.a << " " << unity.b << "\n";
        //sol = val;
        //cout << sol.a << " " << val.a << "\n";
        //cout << sol.b << " " << val.b << "\n\n";
        cout << sol.a << " " << sol.b << "\n";
        cout << val.a << " " << val.b << "\n";
       // cout << "bad = " << bad;

        exit(0);
      }

    //  sol = sol + unity;
      if ((j - k) % 2) {
        sol.a = add(0, -sol.a);
        sol.b = add(0, -sol.b);
      }
      currentj = currentj + sol * Number(comb[j][k], 0);
    }
    print = print + currentj * Number(coefs[j], 0) / pw(5, j) * (sqrt5 ^ j);
  }
  return print;
}

signed main() {
  //ios::sync_with_stdio(0); cin.tie(0);

  for (int i = 0; i < 300; i++) {
    comb[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      comb[i][j] = add(comb[i - 1][j], comb[i - 1][j - 1]);
    }
  }

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int k;
  ll l, r;

  cin >> k >> l >> r;

  Number sol = pref(r + 2, k) - pref(l + 1, k);

  cout << sol.a << "\n";
  assert(sol.b == 0);

  return 0;
}