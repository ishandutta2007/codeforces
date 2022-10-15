#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
const int M = (int) 1e9 + 9;
int p[N];
int t[N];
int n;
int m;
int basis_size;

int root(int x) {
  if (t[x] == x) {
    return x;
  } else {
    return t[x] = root(t[x]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  p[0] = 1;
  for (int i = 1; i < N; i++) {
    p[i] = p[i - 1] * 2 % M;
    t[i] = i;
  }
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    if (root(a) != root(b)) {
      basis_size++;
      t[root(a)] = root(b);
    }
    cout << p[i - basis_size] - 1 << "\n";
  }
}