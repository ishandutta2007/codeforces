#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
signed realMain();

/**
bool eprim(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}**/

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int MOD = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= MOD) {
    return a - MOD;
  }
  if (a < 0) {
    return a + MOD;
  }
  return a;
}

const int N = (int) 1e5 + 7;
const int M = 333;
int n, k, a[N], dp[N], cnt[N], bucket[N], rad;
vector<int> f[N];
int lazy[M], first[M], last[M];
int sum[M][N], good[M];

void open(int b) {
  if (!lazy[b]) {
    return;
  }
  good[b] = 0;
  for (int j = first[b]; j <= last[b]; j++) {
    sum[b][cnt[j]] = add(sum[b][cnt[j]], -dp[j]);
    cnt[j] += lazy[b];
    if (cnt[j] <= k) {
      good[b] = add(good[b], dp[j]);
    }
    sum[b][cnt[j]] = add(sum[b][cnt[j]], +dp[j]);
  }
  lazy[b] = 0;
}

void add(int l, int r, int val) {
  if (bucket[l] == bucket[r]) {
    open(bucket[l]);
    int b = bucket[l];
    for (int j = l; j <= r; j++) {
      if (cnt[j] <= k) {
        good[b] = add(good[b], -dp[j]);
      }

      sum[b][cnt[j]] = add(sum[b][cnt[j]], -dp[j]);
      cnt[j] += val;
      sum[b][cnt[j]] = add(sum[b][cnt[j]], +dp[j]);

      if (cnt[j] <= k) {
        good[b] = add(good[b], +dp[j]);
      }
    }
    return;
  }
  open(bucket[l]);
  int b = bucket[l];
  for (int j = l; j <= last[bucket[l]]; j++) {
    if (cnt[j] <= k) {
      good[b] = add(good[b], -dp[j]);
    }

    sum[b][cnt[j]] = add(sum[b][cnt[j]], -dp[j]);
    cnt[j] += val;
    sum[b][cnt[j]] = add(sum[b][cnt[j]], +dp[j]);

    if (cnt[j] <= k) {
      good[b] = add(good[b], +dp[j]);
    }
  }
  for (int j = bucket[l] + 1; j <= bucket[r] - 1; j++) {
   // open(j);
    if (val == 1) {
      int num = k - lazy[j];
      if (num >= 0) {
        good[j] = add(good[j], -sum[j][num]);
      }
    } else {
      int num = k + 1 - lazy[j];
      if (num >= 0) {
        good[j] = add(good[j], +sum[j][num]);
      }
    }
    lazy[j] += val;
   // open(j);
  }
  open(bucket[r]);
  b = bucket[r];
  for (int j = first[bucket[r]]; j <= r; j++) {

    if (cnt[j] <= k) {
      good[b] = add(good[b], -dp[j]);
    }

    sum[b][cnt[j]] = add(sum[b][cnt[j]], -dp[j]);
    cnt[j] += val;
    sum[b][cnt[j]] = add(sum[b][cnt[j]], +dp[j]);

    if (cnt[j] <= k) {
      good[b] = add(good[b], +dp[j]);
    }


  }
}

signed realMain() {
  cin >> n >> k;
  rad = sqrt(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    f[i].push_back(0);
  }
  for (int i = 0; i <= n; i++) {
    bucket[i] = i / rad + 1;
    last[bucket[i]] = i;
  }
  for (int i = n; i >= 0; i--) {
    first[bucket[i]] = i;
  }
  dp[0] = 1;
  sum[bucket[0]][0] = 1;
  good[bucket[0]] = 1;
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    if ((int) f[x].size() == 1) {
      add(0, i - 1, +1);
    } else {
      add(f[x][(int) f[x].size() - 1], i - 1, +1);
      add(f[x][(int) f[x].size() - 2], f[x][(int) f[x].size() - 1] - 1, -1);
    }
    f[x].push_back(i);
    for (int b = bucket[0]; b < bucket[i - 1]; b++) {
      dp[i] = add(dp[i], good[b]);
    }
    open(bucket[i - 1]);
    for (int j = first[bucket[i - 1]]; j <= i - 1; j++) {
      if (cnt[j] <= k) {
        dp[i] = add(dp[i], dp[j]);
      }
    }
    sum[bucket[i]][cnt[i]] = add(sum[bucket[i]][cnt[i]], dp[i]);
    good[bucket[i]] = add(good[bucket[i]], dp[i]);
  }
  cout << dp[n] << "\n";
  return 0;
}