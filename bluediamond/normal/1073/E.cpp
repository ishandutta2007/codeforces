#include <bits/stdc++.h>

using namespace std;

#define int long long
const int M = 998244353;

int pop(int x) {
  return __builtin_popcountll(x);
}

int rep(int x) {
  x %= M;
  if (x < 0) {
    x += M;
  }
  return x;
}

struct T {
  int sum;
  int cnt;
};

T operator + (T a,  T b) {
  return {rep(a.sum + b.sum), rep(a.cnt + b.cnt)};
}

int p10[100];

map<vector<int>, T> memo;


T combine(int num, int len, T a) {
  num = rep(num);
  assert(0 <= a.cnt && a.cnt < M);
  assert(0 <= a.sum && a.sum < M);
  a.sum += rep(a.cnt * rep(p10[len] * num));
  a.sum = rep(a.sum);
  return a;
}


T compute(int mask, int lft, int k) {
  vector<int> Data = {mask, lft, k};
  if (memo.count(Data)) {
    return memo[Data];
  }
  if (pop(mask) > k) {
    memo[Data] = {0, 0};
    return memo[Data];
  }
  if (!lft) {
    if (pop(mask) == k) {
      memo[Data] = {0, 1};
    } else {
      memo[Data] = {0, 0};
    }
    return memo[Data];
  }
  T sol = {0, 0};
  for (int digit = 0; digit <= 9; digit++) {
    sol = sol + combine(digit, lft - 1, compute(mask | (1 << digit), lft - 1, k));
  }
  memo[Data] = sol;
  return sol;
}

int get_no_digits(int len, int k) {
  int sol = 0;
  for (int f = 1; f <= 9; f++) {
    sol = rep(sol + combine(f, len - 1, compute(1 << f, len - 1, k)).sum);
  }
  return sol;
}

int get(int n, int k) {
  if (n == 0) {
    return 0;
  }
  vector<int> digits;
  while (n) {
    digits.push_back(n % 10);
    n /= 10;
  }
  reverse(digits.begin(), digits.end());
  n = (int) digits.size();
  int sol = 0;
  for (int l = 1; l < n; l++) {
    sol = rep(sol + get_no_digits(l, k));
  }
  int mask = 0, num = 0;
  for (int pre = 0; pre <= n; pre++) {
    if (pre >= 1) {
      mask |= (1 << digits[pre - 1]);
      num = rep(10 * num + digits[pre - 1]);
    }
    if (pre == n) {
      if (pop(mask) == k) {
        sol = rep(sol + num);
      }
      break;
    }
    for (int digit = (pre == 0); digit < digits[pre]; digit++) {
      int val = rep(num * 10 + digit);
      sol = rep(sol + combine(val, n - pre - 1, compute(mask | (1 << digit), n - pre - 1, k)).sum);
    }
  }
  return sol;
}

int compute_pref_at_most(int n, int at_most) {
  int sol = 0;
  for (int k = 1; k <= at_most; k++) {
    sol += get(n, k);
  }
  return sol;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  p10[0] = 1; for (int i = 1; i < 100; i++) p10[i] = rep(10 * p10[i - 1]);

  int l, r;
  int k;
  cin >> l >> r >> k;
  cout << rep(compute_pref_at_most(r, k) - compute_pref_at_most(l - 1, k)) << "\n";
  return 0;
}