#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class linearSieve   /// linear Sieve
{
public:
  vector<int> primes;
  vector<int> lp;
  void put(int Limit)
  {
    primes.clear();
    lp.clear();
    lp.resize(Limit + 1, 0);
    for (int i = 2; i <= Limit; i++)
    {
      if (!lp[i])
      {
        lp[i] = i;
        primes.push_back(i);
      }
      for (int j = 0; j < (int) primes.size() && primes[j] * i <= Limit && primes[j] <= lp[i]; j++)
      {
        lp[primes[j] * i] = primes[j];
      }
    }
  }
} mySieve;

const int N = (int) 1e5 + 7;
const int K = 11;
int n, mod, phi;
bool specialMod[N];
int specialModID[N];
vector<int> primes;
vector<int> modPrimes;

int fast_pow(int a, int b)
{
  if (a == mod)
  {
    a = 0;
  }
  int r = 1;
  while (b)
  {
    if (b & 1)
    {
      r = (ll) r * a % mod;
    }
    a = (ll) a * a % mod;
    b /= 2;
  }
  return r;
}

int sum[4 * N];
int lazy_mult[4 * N];
int lazy[4 * N][K];
bool bad[4 * N];

int the_number[N];
int coefs[N][K];
int memo[K][(int) 1e6];

int S;
vector<pair<int, int>> jobs[N];
int mul[N];
int mul_inv[N];



void push(int v, int tl, int tr)
{
  if (!bad[v])
  {
    return;
  }
  if (lazy_mult[v] > 1)
  {
    sum[v] = (ll) sum[v] * lazy_mult[v] % mod;
    if (tl < tr)
    {
      lazy_mult[2 * v] = (ll) lazy_mult[2 * v] * lazy_mult[v] % mod;
      lazy_mult[2 * v + 1] = (ll) lazy_mult[2 * v + 1] * lazy_mult[v] % mod;
      bad[2 * v] = bad[2 * v + 1] = 1;
    }
    else
    {
      the_number[tl] = (ll) the_number[tl] * lazy_mult[v] % mod;
    }
    lazy_mult[v] = 1;
  }
  for (int k = 0; k < (int) primes.size(); k++)
  {
    if (lazy[v][k] > 0)
    {
      if (tl < tr)
      {
        lazy[2 * v][k] += lazy[v][k];
        lazy[2 * v + 1][k] += lazy[v][k];
        bad[2 * v] = bad[2 * v + 1] = 1;
      }
      else
      {
        coefs[tl][k] += lazy[v][k];
      }
      if (lazy[v][k] < (int) 1e6)
      {
        sum[v] = (ll) sum[v] * memo[k][lazy[v][k]] % mod;
      }
      else
      {
        sum[v] = (ll) sum[v] * fast_pow(primes[k], lazy[v][k]) % mod;
      }
      lazy[v][k] = 0;
    }
  }
  bad[v] = 0;
}

void initial(int v, int tl, int tr)
{
  sum[v] = (tr - tl + 1) % mod;
  if (tl < tr)
  {
    int tm = (tl + tr) / 2;
    initial(2 * v, tl, tm);
    initial(2 * v + 1, tm + 1, tr);
  }
}

void join(int v)
{
  sum[v] = (sum[2 * v] + sum[2 * v + 1]) % mod;
}

bool no;

void normalMult(int v, int tl, int tr, int l, int r, int x)
{
  push(v, tl, tr);
  if (tr < l || r < tl)
  {
    return;
  }
  if (l <= tl && tr <= r)
  {
    lazy_mult[v] = x;
    bad[v] = 1;
    if (!no)
    {
      for (auto &it : jobs[S])
      {
        lazy[v][it.first] = it.second;
      }
    }
    push(v, tl, tr);
  }
  else
  {
    int tm = (tl + tr) / 2;
    normalMult(2 * v, tl, tm, l, r, x);
    normalMult(2 * v + 1, tm + 1, tr, l, r, x);
    join(v);
  }
}

void mult(int l, int r, int x)
{
  S = x;
  normalMult(1, 1, n, l, r, mul[S]);
}

int get(int v, int tl, int tr, int l, int r)
{
  push(v, tl, tr);
  if (tr < l || r < tl)
  {
    return 0;
  }
  if (l <= tl && tr <= r)
  {
    return sum[v];
  }
  else
  {
    int tm = (tl + tr) / 2;
    return (get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r)) % mod;
  }
}

int get(int l, int r)
{
  return get(1, 1, n, l, r);
}

void dv(int v, int tl, int tr, int i)
{
  push(v, tl, tr);
  if (tr < i || i < tl)
  {
    return;
  }
  if (tl == tr)
  {
    for (auto &it : jobs[S])
    {
      coefs[tl][it.first] -= it.second;
    }
    sum[v] = the_number[tl];
    for (int k = 0; k < (int) primes.size(); k++)
    {
      if (coefs[tl][k] < (int) 1e6)
      {
        sum[v] = (ll) sum[v] * memo[k][coefs[tl][k]] % mod;
      }
      else
      {
        sum[v] = (ll) sum[v] * fast_pow(primes[k], coefs[tl][k]) % mod;
      }
    }
  }
  else
  {
    int tm = (tl + tr) / 2;
    dv(2 * v, tl, tm, i);
    dv(2 * v + 1, tm + 1, tr, i);
    join(v);
  }
}

void dv(int p, int x)
{
  S = x;
  dv(1, 1, n, p);
  no = 1;
  normalMult(1, 1, n, p, p, mul_inv[S]);
  no = 0;
}

int init[N];

void build(int v, int tl, int tr)
{
  if (tl == tr)
  {
    S = init[tl];
    the_number[tl] = mul[S];
    for (auto &it : jobs[S])
    {
      coefs[tl][it.first] += it.second;
    }
    sum[v] = init[tl] % mod;
  }
  else
  {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    join(v);
  }
}

signed main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 0; i < 4 * N; i++)
  {
    lazy_mult[i] = 1;
  }
  for (int i = 0; i < N; i++)
  {
    the_number[i] = 1;
  }

  mySieve.put(N);
  cin >> n >> mod;
  initial(1, 1, n);
  phi = mod;
  int copyMod = mod;
  for (int d = 2; d * d <= copyMod; d++)
  {
    if (copyMod % d == 0)
    {
      modPrimes.push_back(d);
      phi /= d;
      phi *= (d - 1);
      while (copyMod % d == 0)
      {
        copyMod /= d;
      }
    }
  }
  if (copyMod > 1)
  {
    phi /= copyMod;
    phi *= (copyMod - 1);
    modPrimes.push_back(copyMod);
  }
  for (auto &x : modPrimes)
  {
    if (x < N)
    {
      specialMod[x] = 1;
      specialModID[x] = (int) primes.size();
      primes.push_back(x);
    }
  }
  for (int j = 0; j < (int) primes.size(); j++)
  {
    memo[j][0] = 1;
    for (int i = 1; i < (int) 1e6; i++)
    {
      memo[j][i] = (ll) memo[j][i - 1] * primes[j] % mod;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    cin >> init[i];
  }
  for (int num = 1; num < N; num++)
  {
    mul[num] = 1;
    int x = num;
    while (x > 1)
    {
      int prime = mySieve.lp[x], val = 1, coef = 0;
      while (x % prime == 0)
      {
        x /= prime;
        val *= prime;
        coef++;
      }
      if (specialMod[prime])
      {
        jobs[num].push_back({specialModID[prime], coef});
      }
      else
      {
        mul[num] = (ll) mul[num] * val % mod;
      }
    }
    mul_inv[num] = fast_pow(mul[num], phi - 1);
  }
  int q;
  cin >> q;
  build(1, 1, n);
  for (int iq = 1; iq <= q; iq++)
  {
    int type;
    cin >> type;
    if (type == 1)
    {
      int l, r, x;
      cin >> l >> r >> x;
      mult(l, r, x);
    }
    if (type == 2)
    {
      int p, x;
      cin >> p >> x;
      dv(p, x);
    }
    if (type == 3)
    {
      int l, r;
      cin >> l >> r;
      cout << get(l, r) << "\n";
    }
  }
  return 0;
}