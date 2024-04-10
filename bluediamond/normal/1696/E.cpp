/// 483 -> 484
#include <bits/stdc++.h>

using namespace std;

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

int pw(int a, int b) {
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

void print(vector<int> v) {
  cout << " ---> ";
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << "\n";
}

const int N = (int) 4e5 + 7;
int n;
int a[N];
int fact[N];
int ifact[N];

int comb(int n, int k) {
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE
  {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
      fact[i] = mul(fact[i - 1], i);
    }
    ifact[N - 1] = dv(1, fact[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
      ifact[i] = mul(ifact[i + 1], i + 1);
    }
    /**
    for (int i = 0; i < 10; i++) {
      cout << i << " : " << fact[i] << " and " << ifact[i] << " ---> " << mul(fact[i], ifact[i]) << "\n";
    }
    **/
   /// exit(0);
  }

  cin >> n;
  n++;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }


  int sol = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      addup(sol, comb(i + a[i], i + 1));
    }
  }
  cout << sol << "\n";
}