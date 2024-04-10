#include <bits/stdc++.h>
#define int long long 

using namespace std;

int gcd(int a, int b) {
  while (b) {
    int r = a % b;
    a = b; b = r;
  }
  return a;
}

struct SegTree {
  vector<int> T; int n;
  SegTree(int n) : T(2 * n, 0), n(n) {}
  
  void Update(int pos, int val) {
    for (T[pos += n] = val; pos > 1; pos /= 2)
      T[pos / 2] = gcd(T[pos], T[pos ^ 1]);
  }
  int Query(int b, int e) {
    int res = 0;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) res = gcd(res, T[b++]);
      if (e % 2) res = gcd(res, T[--e]);
    }
    return res;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
      cin >> v[i];

    SegTree S(n - 1);
    for (int i = 0; i < n - 1; ++i) {
      int del = v[i + 1] - v[i];
      del = abs(del);
      //cerr << "pos: " << i << " val: " << del << endl;
      S.Update(i, del);
    }
   
    int j = 0;
    int ans = 1;
    for (int i = 0; i < n - 1; ++i) {
      while (j <= n - 1 && S.Query(i, j) != 1) {
        //cerr << "ok: " << i << " " << j << " " << S.Query(i, j) << endl;
        ++j;
      }
      //cerr << i << ": " << j << endl;
      ans = max(ans, j - i);
    }
    cout << ans << '\n';
  }

  return 0;
}