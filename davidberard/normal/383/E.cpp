#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int K = 24;
const int N = 1<<K;

int f[N];
int a[10100];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  int have[26];
  for (int i=1; i<=n; ++i) {
    memset(have, 0, sizeof have);
    string s;
    cin >> s;
    int r = 0;
    for (auto& c : s) {
      r |= (1<<(c-'a'));
    }
    f[r]++;
  }
  for (int i=0; i<K; ++i) {
    for (int mask=0; mask<N; ++mask) {
    //for (int mask=N-1; mask>=0; --mask) {
      if (mask&(1<<i)) {
        f[mask] += f[mask^(1<<i)];
      }
    }
  }
  int ans = 0;
  for (int mask=0; mask<N; ++mask) {
    ans ^= ((n-f[mask])*(n-f[mask]));
  }
  cout << ans << "\n";
  return 0;
}