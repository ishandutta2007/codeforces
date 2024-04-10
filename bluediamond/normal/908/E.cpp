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

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;

  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int& a, int b) {
  a = add(a, b);
}

void mulup(int& a, int b) {
  a = mul(a, b);
}

const int N = 1000 + 7;
int fact[N], ifact[N], partitions[N];

int comb(int n, int k) {
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif


  if (home) {
    FILE* stream;
    freopen_s(&stream, "iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);


  partitions[0] = 1;
  for (int i = 1; i < N; i++) {
    for (int last = 1; last <= i; last++) {
      addup(partitions[i], mul(partitions[i - last], comb(i - 1, last - 1)));
    }
  }

  int cnt, n;
  string s;
  cin >> n >> cnt;
  map<ll, int> f;
  vector<ll> msk(n, 0);
  for (int bit = 0; bit < cnt; bit++) {
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') msk[i] += (1LL << bit);
    }
  }
  for (int i = 0; i < n; i++) f[msk[i]]++;
  int sol = 1;
  for (auto& it : f) {
    mulup(sol, partitions[it.second]);
  }
  cout << sol << "\n";
}