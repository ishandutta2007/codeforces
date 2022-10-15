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
#include <cstdio> 


bool home = true;
using namespace std;
#define int long long
typedef long long ll;
const int N = (int)1e5 + 7;
int total, MOD, some[N];
vector<int> primes, exps;

int rep(int a) {
  a %= MOD;
  if (a < 0) a += MOD;
  return a;
}

int add(int a, int b) {
  a = rep(a);
  b = rep(b);
  assert(0 <= a && a < MOD);
  assert(0 <= b && b < MOD);
  ll sum = a + b;
  if (sum >= MOD) sum -= MOD;
  return sum;
}

int sub(int a, int b) {
  a = rep(a);
  b = rep(b);
  assert(0 <= a && a < MOD);
  assert(0 <= b && b < MOD);
  ll dif = a - b;
  if (dif < 0) dif -= MOD;
  return dif;
}

int mul(int a, int b) {
  a = rep(a);
  b = rep(b);
  assert(0 <= a && a < MOD);
  assert(0 <= b && b < MOD);
  ll prod = a * (ll)b % MOD;
  return prod;
}


int t[4 * N];

void clr(int v, int tl, int tr) {
  t[v] = 1;
  if (tl < tr) {
    int tm = (tl + tr) / 2;
    clr(2 * v, tl, tm);
    clr(2 * v + 1, tm + 1, tr);
  }
}

int get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) return 1;
  if (l <= tl && tr <= r) return t[v];
  int tm = (tl + tr) / 2;
  return mul(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

int get(int l, int r) {
  return get(1, 0, (int)primes.size() - 1, l, r);
}

int pw(int number, int e) {
  number = rep(number);
  assert(0 <= number && number < MOD);
  int sol = 1;
  while (e) {
    if (e & 1) sol = mul(sol, number);
    number = mul(number, number);
    e /= 2;
  }
  return sol;
}

void upd(int v, int tl, int tr, int i, int x) {
  if (tr < i || i < tl) return;
  if (tl == tr) { t[v] = x; return; }
  int tm = (tl + tr) / 2;
  upd(2 * v, tl, tm, i, x);
  upd(2 * v + 1, tm + 1, tr, i, x);
  t[v] = mul(t[2 * v], t[2 * v + 1]);
}

void upd(int i, int x) {
  upd(1, 0, (int)primes.size() - 1, i, x);
}

int nn;
int kk;

void clr() {
  nn = 0;
  kk = 0;
  for (auto& x : exps) {
    x = 0;
  }

  clr(1, 0, (int)primes.size() - 1);
}

void mulup(int num) {
  while (num > 1) {
    int id = some[num];
    int prime = primes[id];

    exps[id]++;
    upd(id, pw(primes[id], exps[id]));
    num /= prime;
  }
}

void dvup(int num) {
  while (num > 1) {
    int id = some[num];
    int prime = primes[id];
    exps[id]--;
    upd(id, pw(primes[id], exps[id]));
    num /= prime;
  }

}

int get() {
  int them = get(0, (int)primes.size() - 1);
  return them;
}

void go(int new_n, int new_k) {
  assert(nn <= new_n);
  assert(kk <= new_k);

  while (nn < new_n) {
    nn++;
    mulup(nn);
    dvup(nn - kk);
  }

  while (kk < new_k) {
    mulup(nn - kk);
    dvup(kk + 1);
    kk++;
  }
  assert(nn == new_n);
  assert(kk == new_k);
}


int solve(int _, int __, int ___, int ____) {
  int VAL_B, VAL_C;
  total = _;
  MOD = __;
  int l = ___;
  int r = ____;
  VAL_B = ___;
  VAL_C = ____;
  VAL_B = VAL_B / 2;
  VAL_C = VAL_C / 2 + 1;

  {
    vector<bool> ciur(total + 1, 0);
    ciur[2] = 1;
    for (int i = 3; i <= total; i += 2) ciur[i] = 1;
    for (int i = 3; i * i <= total; i += 2) if (ciur[i]) for (int j = i * i; j <= total; j += 2 * i) ciur[j] = 0;
    int cnt = 0;
    for (int i = 1; i <= total; i++) {
      if (ciur[i]) {
        cnt++;
        primes.push_back(i);
        exps.push_back(0);
      }
    }

    for (int i = 0; i < (int)primes.size(); i++) {
      for (int j = primes[i]; j <= total; j += primes[i]) {
        some[j] = i;
      }
    }
  }

  int sol = 0;

  vector<int> AS(total + 1, 0), BS(total + 1), CS(total + 1);
 
  {
    clr();
    AS[0] = 1;
    for (int n = 1; n <= total; n++) {
      dvup(n);
      mulup(total - n + 1);
      AS[n] = get();
    }
  }

  if (___ == 0) {
    sol = add(sol, 1);
  }

  

  clr();
  for (int n = 1; n <= total; n++) {
    int F = 0, S = 0;

    int l = ___, r = ____;

    if (l % 2 != n % 2) l++;
    if (r % 2 != n % 2) r--;

    if (l > r) continue;

    int value = 0;
    {
      if (0 <= n / 2 - l / 2) {
        go(n, n / 2 - l / 2);
        BS[n] = get();
      }
    }
  }
  clr();
  for (int n = 1; n <= total; n++) {
    int F = 0, S = 0;

    int l = ___, r = ____;

    if (l % 2 != n % 2) l++;
    if (r % 2 != n % 2) r--;

    if (l > r) continue;

    int value = 0;
    {
      if (0 <= n / 2 - r / 2 - 1) {
        go(n, n / 2 - r / 2 - 1);
        CS[n] = get();
      }
    }
  }
  for (int n = 1; n <= total; n++) {
    int F = 0, S = 0;
    
    int l = ___, r = ____;

    if (l % 2 != n % 2) l++;
    if (r % 2 != n % 2) r--;
    
    if (l > r) continue;

    int value = 0;
    {
      value = add(value, BS[n]);
    }
    {
      value = add(value, -CS[n]);
    }

    sol = add(sol, mul(value, AS[n]));
  }
  return sol;
}

signed main() {
  int _, __, ___, ____;
  cin >> _ >> __ >> ___ >> ____;
  cout << solve(_, __, ___, ____) << "\n";
  exit(0);
  


}