#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int K = 22;
const int N = 1<<K;

int f[N];
int g[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
    g[a[i]] = f[a[i]] = a[i];
  }
  for (int i=0; i<K; ++i) {
    //for (int mask=N-1; mask>=0; --mask) {
    for (int mask=0; mask<N; ++mask) {
      if (mask&(1<<i)) {
        if (!g[mask]) {
          g[mask] = g[mask^(1<<i)];
        }
      }
    }
  }
  for (int i=1; i<=n; ++i) {
    int b = (N-1)^a[i];
    cout << (g[b] ? g[b] : -1) << " ";
  }
  cout << "\n";
  return 0;
}