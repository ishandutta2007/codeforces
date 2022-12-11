#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 200010;
ll S[N];
ll T[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> S[i] >> T[i];
    T[i] += S[i];
  }
  ll k = 100000000;
  for (int i = 0; i < n; ++i) {
    ++k;
    T[i] = min(T[i], k);
    k = T[i];
  }
  k = 100000000;
  for (int i = n-1; i >= 0; --i) {
    ++k;
    T[i] = min(T[i], k);
    k = T[i];
  }
  ll res =0;
  for (int i = 0; i < n; ++i) {
    if (S[i] > T[i]) {
      res = -1;
      break;
    }
    res += T[i] - S[i];
  }
  cout << res << endl;
  if (res == -1) return 0;
  for (int i = 0; i < n; ++i) {
    if (i) cout << ' ';
    cout << T[i];
  }
  cout << endl;
}