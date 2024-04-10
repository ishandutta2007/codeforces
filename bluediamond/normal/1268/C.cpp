
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200000 + 7;
int n;
int a[N];
int p[N];
int t1[N];
long long t2[N];

void add1(int i) {
  i = p[i];
  while (i <= n) {
    t1[i]++;
    i += i & (-i);
  }
}

int sum1(int i) {
  int sol = 0;
  while (i) {
    sol += t1[i];
    i -= i & (-i);
  }
  return sol;
}

int sum1(int l, int r) {
  return sum1(r) - sum1(l - 1);
}

void add2(int i) {
  i = p[i];
  int grow = i;
  while (i <= n) {
    t2[i] += grow;
    i += i & (-i);
  }
}

ll sum2(int i) {
  ll sol = 0;
  while (i) {
    sol += t2[i];
    i -= i & (-i);
  }
  return sol;
}

ll sum2(int l, int r) {
  return sum2(r) - sum2(l - 1);
}

ll gauss(ll i) {
  return i * (i + 1) / 2;
}

ll gauss(ll l, ll r) {
  return gauss(r) - gauss(l - 1);
}

int kth(int k) {
  int l = 1, r = n, ans = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    if (sum1(1, m) >= k) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[a[i]] = i;
  }
  ll invs = 0;
  for (int x = 1; x <= n; x++) {
    invs += sum1(p[x] + 1, n);
    add1(x);
    add2(x);
    int half = x / 2 + 1;
    int on_right = x - half;
    int pos = kth(half);
    ll lft = gauss(pos - half + 1, pos) - sum2(1, pos);
    ll rgh = sum2(pos + 1, n) - gauss(pos + 1, pos + on_right);
    ll sol = invs + lft + rgh;
    cout << sol << " ";
  }
  cout << "\n";

}