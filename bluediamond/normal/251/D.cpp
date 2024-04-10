#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


const int N = (int) 1e5 + 7;
const int B = 60;
int n;
ll nums[N];
ll xo;
int col[N];
bitset<N> representation[B];

bool is_ok(ll mask_care, ll mask) {
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = (nums[i + 1] & mask_care);
  }
  vector<ll> h(B, 0);
  for (int i = 0; i < n; i++) {
    ll x = a[i];
    for (int b = B - 1; b >= 0; b--) {
      if (x & (1LL << b)) {
        x ^= h[b];
      }
    }
    if (x == 0) {
      continue;
    }
    for (int b = B - 1; b >= 0; b--) {
      if (x & (1LL << b)) {
        assert(h[b] == 0);
        h[b] = x;
        break;
      }
    }
  }
  for (int b = B - 1; b >= 0; b--) {
    if (mask & (1LL << b)) {
      mask ^= h[b];
    }
  }
  return (mask == 0);
}

void compute(ll mask_care, ll mask) {
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = (nums[i + 1] & mask_care);
  }
  vector<ll> h(B, 0);
  for (int i = 0; i < n; i++) {
    ll x = a[i];
    for (int b = B - 1; b >= 0; b--) {
      if (x & (1LL << b)) {
        x ^= h[b];
      }
    }
    if (x == 0) {
      continue;
    }
    x = a[i];
    bitset<N> cur;
    cur[i + 1] = 1;
    for (int b = B - 1; b >= 0; b--) {
      if (x & (1LL << b)) {
        x ^= h[b];
        cur ^= representation[b];
      }
    }
    for (int b = B - 1; b >= 0; b--) {
      if (x & (1LL << b)) {
        assert(h[b] == 0);
        h[b] = x;
        representation[b] = cur;
        break;
      }
    }
  }
  bitset<N> cur;
  for (int b = B - 1; b >= 0; b--) {
    if (mask & (1LL << b)) {
      mask ^= h[b];
      cur ^= representation[b];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (cur[i]) {
      col[i] = 1;
    } else {
      col[i] = 2;
    }
  }
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> nums[i];
    xo ^= nums[i];
  }

  ll mask = 0;
  for (int b = B - 1; b >= 0; b--) {
    if (!(xo & (1LL << b))) {
      if (is_ok(mask + (1LL << b), mask + (1LL << b))) {
        mask += (1LL << b);
      }
    }
  }

  ll mask_care = mask;
  for (int b = B - 1; b >= 0; b--) {
    if (xo & (1LL << b)) {
      if (is_ok(mask_care + (1LL << b), mask)) {
        mask_care += (1LL << b);
      }
    }
  }


  compute(mask_care, mask);

  ll A = 0, B = 0;
  for (int i = 1; i <= n; i++) {
    cout << col[i] << " ";
    if (col[i] == 1) {
      A ^= nums[i];
    } else {
      B ^= nums[i];
    }
  }
  cout << "\n";

}