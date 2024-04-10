#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
mt19937 rng((long long) (new char));


const int N = (int) 1e5 + 7;
int n;
int k;
int steps;

int ask_idol(int i) {
  cout << "? " << i << endl;
  int ret;
  cin >> ret;
  return ret;
}

int add(int a, int b) {
  a += b - 1;
  a %= n;
  a += n;
  a %= n;
  return a + 1;
}

int ask(int i) {
  int ret = ask_idol(i);
  steps++;
  return ret;
}

int len(int l, int r) {
  if (l <= r) {
    return r - l;
  } else {
    return len(1, r) + len(l, n);
  }
}

int fnd(int l, int r) {
  while (steps < min(n, 950)) {
    ask(1);
  }

  while (1) {
    int mid = add(l, len(l, r) / 2);
    int x = ask(mid);
    int y = ask(add(mid, +1));
    if (x == k) {
      if (y > k) {
        return mid;
      } else {
        return add(mid, n / 2);
      }
    }
    if (x > k) {
      r = add(mid, -1);
    } else {
      l = add(mid, +1);
    }
  }
  return -1;
}

int solve() {
  steps = 0;

  if (n < 250) {
    for (int i = 1; i <= n; i++) {
      ask(1);
    }
    for (int i = 1; i <= n; i++) {
      int x = ask(i);
      if (x == k) {
        int y = ask(add(i, +1));
        if (y > k) {
          return i;
        }
      }
    }
  }
  while (1) {
    int i = rng() % n + 1;
    int xi = ask(i);
    if (xi != k) {
      if (steps < n / 2) {
        return fnd(add(i, -steps), add(i, steps));
      } else {
        return fnd(1, n);
      }
    }
  }
}

signed main() {
  cin >> n >> k;
  cout << "! " << solve() << endl;

}