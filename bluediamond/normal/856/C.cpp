#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
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

int rep(int a, int modulo = 11) {
  a %= modulo;
  if (a < 0) a += modulo;
  return a;
}

void addup(int &a, int x) {
  a = add(a, x);
}

const int N = 2000 + 7;
int n, len[N], sum[N];
int fact[N], ifact[N];

int comb(int n, int k) {
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

int dp[N][11], ndp[N][11], ways[11];

void computeDp(vector<int> nums) {
  for (int i = 0; i <= (int) nums.size(); i++) {
    for (int x = 0; x < 11; x++) {
      dp[i][x] = 0;
      assert(ndp[i][x] == 0);
    }
  }
  dp[0][0] = 1;
  for (int total = 0; total < (int) nums.size(); total++) {
    for (int pls = 0; pls <= total; pls++) {
      for (int x = 0; x < 11; x++) {
        int cur = dp[pls][x];
        if (!cur) continue;
        addup(ndp[pls + 1][rep(x + nums[total])], cur);
        addup(ndp[pls][rep(x - nums[total])], cur);
      }
    }
    for (int pls = 0; pls <= total + 1; pls++) {
      for (int j = 0; j < 11; j++) {
        dp[pls][j] = ndp[pls][j];
        ndp[pls][j] = 0;
      }
    }
  }

}

int X[N][N];

int buga(int spaces, int cnt) {
  if (!cnt) return 1;


  int sol = 0;
  for (int j = 1; j <= spaces && j <= cnt; j++) {
    sol = add(sol, mul(comb(spaces, j), comb(cnt - 1, j - 1)));
  }

  return sol;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = mul(ifact[i + 1], i + 1);
  }

  int tt;
  cin >> tt;
  for (int tc = 1; tc <= tt; tc++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int foo;
      cin >> foo;
      len[i] = 0;
      sum[i] = 0;
      while (foo) {
        int x = foo % 10;
        len[i] ^= 1;
        if (len[i] & 1) {
          sum[i] += x;
        } else {
          sum[i] -= x;
        }
        foo /= 10;
      }
      sum[i] = rep(sum[i]);
    }


    int cnt_odd, cnt_even;

    {
      /// for odd lengths
      vector<int> odds;
      for (int i = 1; i <= n; i++) {
        if (len[i] & 1) {
          odds.push_back(sum[i]);
        }
      }
      cnt_odd = (int) odds.size();
      computeDp(odds);
      int neg = (int) odds.size() / 2, pls = (int) odds.size() - neg;
      for (int x = 0; x < 11; x++) {
        ways[x] = mul(dp[pls][x], mul(fact[pls], fact[neg]));
      }
    }

    {
      /// for even lengths
      vector<int> evens;
      for (int i = 1; i <= n; i++) {
        if (!(len[i] & 1)) {
          evens.push_back(sum[i]);
        }
      }
      cnt_even = (int) evens.size();
      computeDp(evens);
    }


    int sol = 0;
    for (int pls = 0; pls <= cnt_even; pls++) {
      for (int x = 0; x < 11; x++) {
        int cur = mul(dp[pls][x], ways[rep(11 - x)]);
        if (!cur) continue;
        cur = mul(cur, fact[pls]);
        cur = mul(cur, fact[cnt_even - pls]);

        int spaces_for_pls = cnt_odd / 2 + 1, spaces_for_neg = cnt_odd + 1 - spaces_for_pls;
        assert(spaces_for_pls >= 0);
        assert(spaces_for_neg >= 0);

        int neg = cnt_even - pls;

        cur = mul(cur, buga(spaces_for_pls, pls));
        cur = mul(cur, buga(spaces_for_neg, neg));

        sol = add(sol, cur);
      }
    }
    cout << sol << "\n";
  }
}