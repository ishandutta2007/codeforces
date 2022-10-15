#include <bits/stdc++.h>

using namespace std;

const int N = 150 + 7;
int n;
int p[N][N];

void gen(int id) {
  for (int i = 0; i < N; i++) {
    if (p[id - 1][i]) {
      p[id][i + 1] ^= 1;
    }
    if (p[id - 2][i]) {
      p[id][i] ^= 1;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ///freopen ("input", "r", stdin);
  p[0][0] = 1;
  p[1][1] = 1;
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    gen(i);
  }
  cout << n << "\n";
  for (int i = 0; i <= n; i++) {
    cout << p[n][i] << " ";
  }
  cout << "\n";
  cout << n - 1 << "\n";
  for (int i = 0; i <= n - 1; i++) {
    cout << p[n - 1][i] << " ";
  }
  cout << "\n";
  return 0;
}