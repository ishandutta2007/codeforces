#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 

bool home = true;

using namespace std;
typedef long long ll;

const int M = (int)1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll)b % M;
}

int fpw(int a, int b) {
  if (b == 0) {
    return 1;
  }
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, fpw(b, M - 2));
}

void addup(int& a, int b) {
  a = add(a, b);
}

void mulup(int& a, int b) {
  a = mul(a, b);
}

const int N = 777;
int pw10[N];
int sumpw10[N];
int comb[N][N];
int pw[10][N];
int ipw[10][N];
int fact[N];
int ifact[N];

vector<int> get_rsorted_digits(int n) {
  assert(n > 0);
  vector<int> digits;
  while (n) {
    digits.push_back(n % 10);
    n /= 10;
  }
  sort(digits.rbegin(), digits.rend());
  return digits;
}
int magic(vector<int> current, int len) {
  vector<int> f(10, 0);
  for (int i = 0; i <= 9; i++) {
    f[i] = 0;
  }
  for (auto& x : current) {
    f[x]++;
  }
  int dim = (int)current.size();
  assert(dim > 0);
  assert(len >= 0);

  int sol = 0;

  int total = dim + len;
  for (int digit = 1; digit <= 9; digit++) {
    int smaller = 0, bigger = 0;
    for (int j = 0; j < digit; j++) smaller += f[j];
    for (int j = digit; j <= 9; j++) bigger += f[j];
    int tl = 0;

    for (int bg = bigger; bg <= total-smaller; bg++) {
      int sma = total - bg;
      if (bg >= bigger && sma >= smaller) {
        int sum = sumpw10[bg - 1];
        int ways = 1;
        int x_smaller = sma - smaller;
        int x_bigger = bg - bigger;
        mulup(ways, pw[digit][x_smaller]);
        mulup(ways, pw[10 - digit][x_bigger]);
        mulup(ways, comb[x_smaller + x_bigger][x_smaller]);
        addup(sol, mul(sum, ways));
      }
      else {
        assert(0);
      }
    }
  }
  return sol;
}

int solve(string s) {
  int sol = 0;
  int dim = (int)s.size();
  for (int fdigit = 1; fdigit <= 9; fdigit++) {
    for (int len = 1; len < dim; len++) {
      vector<int> current = { fdigit };
      addup(sol, magic(current, len - 1));
    }
  }
  vector<int> digits;
  for (int pref = 0; pref <= dim; pref++) {
    if (pref) {
      digits.push_back(s[pref - 1] - '0');
    }
    if (pref == dim) {
      sort(digits.rbegin(), digits.rend());
      for (int i = 0; i < (int)digits.size(); i++) {
        addup(sol, mul(pw10[i], digits[i]));
      }
      continue;
    }
    for (int current = (pref == 0); current < s[pref] - '0'; current++) {
      vector<int> ndigits = digits;
      ndigits.push_back(current);
      addup(sol, magic(ndigits, dim - pref - 1));
    }
  }
  return sol;
}


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);

  pw[0][0] = 1;
  ipw[0][0] = 1;

  for (int d = 1; d <= 9; d++) {
    pw[d][0] = 1;
    for (int j = 1; j < N; j++) pw[d][j] = mul(pw[d][j - 1], d);
    ipw[d][N - 1] = dv(1, pw[d][N - 1]);
    for (int j = N - 2; j >= 0; j--) ipw[d][j] = mul(d, ipw[d][j + 1]);
  }

  pw10[0] = 1;
  for (int i = 1; i < N; i++) pw10[i] = mul(pw10[i - 1], 10);

  sumpw10[0] = 1;
  for (int i = 1; i < N; i++) sumpw10[i] = add(sumpw10[i - 1], pw10[i]);

  for (int i = 0; i < N; i++) {
    comb[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      comb[i][j] = add(comb[i - 1][j], comb[i - 1][j - 1]);
    }
  }


  if (home) {
    FILE* stream;
    freopen_s(&stream, "iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  string number;
  cin >> number;
  cout << solve(number) << "\n";

}