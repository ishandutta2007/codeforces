#include <bits/stdc++.h>

using namespace std;

time_t bg;
bool home = 1;

mt19937 rng((long long) (new char));

const int N = 300000 + 7;
const int C = 77;
int n, a[N], pos[N];

void yes() {
  cout << "YES\n";
  exit(0);
}

void test(int i, int j) {
  if (i > j) swap(i, j);
  if (1 <= i && i < j && j <= n) {
    int x = a[i] + a[j];
    if (x % 2) return;
    x /= 2;
    if (i < pos[x] && pos[x] < j) yes();
  }
}

void algo1() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= min(i - 1, C); j++) {
      int w = 2 * a[i] - a[j];
      if (1 <= w && w <= n && pos[w] > i) yes();
    }
    for (int j = i - 1; j >= max(1, i - C); j--) {
      int w = 2 * a[i] - a[j];
      if (1 <= w && w <= n && pos[w] > i) yes();
    }
    for (int j = i + 1; j <= min(n, i + C); j++) {
      int w = 2 * a[i] - a[j];
      if (1 <= w && w <= n && pos[w] < i) yes();
    }
    for (int j = n; j >= max(i + 1, n - C); j--) {
      int w = 2 * a[i] - a[j];
      if (1 <= w && w <= n && pos[w] < i) yes();
    }
  }
}

void algo2() {
  for (int x = 1; x < C; x++) {
    for (int i = x; i + x <= n; i++) {
      test(pos[i - x], pos[i + x]);
    }
  }
}


void algo3() {
  int steps = (int) 3e7;
  for (int x = n; x >= 1 && steps >= 0; x--) {
    for (int i = x; i + x <= n; i++) {
      test(pos[i - x], pos[i + x]);
      steps--;
    }
  }
}

void algo4() {
  vector<int> difs(n);
  iota(difs.begin(), difs.end(), 1);
  shuffle(difs.begin(), difs.end(), rng);
  int steps = 0;
  for (auto &x : difs) {
    steps++;
    for (int i = x; i + x <= n; i++) {
      test(pos[i - x], pos[i + x]);
    }
    if (steps % 10 == 0 && (double) (clock() - bg) / CLOCKS_PER_SEC > 0.9) {
      return;
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  bg = clock();

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  }

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }

  algo1();
  algo2();
  algo3();
  algo4();
  cout << "NO\n";



  return 0;
}