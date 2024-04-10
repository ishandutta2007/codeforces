#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

map<pair<int, int>, int> memo;

int ask(int i, int j) {
  if (i > j) {
    swap(i, j);
  }
  if (!memo.count({i, j})) {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int res;
    cin >> res;
    memo[{i, j}] = res;
  }
  return memo[{i, j}];
}

const int N = 2048 + 7;
int n, mb, non[20], so[N];

int get(int i) {
  int sol = (1 << 30) - 1;
  for (int b = 0; b <= mb; b++) {
    if (i == non[b]) {
      sol &= (((1 << 30) - 1) ^ (1 << b));
    } else {
      sol &= ask(i, non[b]);
    }
  }
  return sol;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  while ((1 << (mb + 1)) < n) {
    mb++;
  }
  for (int b = 0; b <= mb; b++) {
    while (1) {
      int i = rng() % n, j = rng() % n;
      if (i == j) continue;
      if (!(ask(i, j) & (1 << b))) {
        non[b] = i;
        break;
      }
    }
  }
  int pm = 0, val = get(0);
  for (int i = 1; i < n && val > 0; i++) {
    if (ask(i, pm) != val) continue;
    pm = i;
    val = get(pm);
  }
  for (int i = 0; i < n; i++) {
    if (i == pm) {
      so[i] = 0;
    } else {
      so[i] = ask(i, pm);
    }
  }
  cout << "! ";
  for (int i = 0; i < n; i++) {
    cout << so[i] << " ";
  }
  cout << endl;
  return 0;
}