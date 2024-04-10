#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int long long
const int N = 200000 + 7;
int n;
int inita[N];
int dif[N];

void print() {
  cout << " ---> ";
  for (int i = 1; i <= n; i++) {
    cout << dif[i] << " ";
  }
  cout << "\n";
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    inita[0] = inita[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> inita[i];
    }
    for (int i = 1; i <= n + 1; i++) {
      dif[i] = inita[i] - inita[i - 1];
    }
    n++;
   /// print();
    int sol = 0;
    for (int i = 2; i < n; i++) {
      sol += abs(dif[i]);
      if (dif[i] < 0) {
        dif[1] -= abs(dif[i]);
      } else {
        dif[n] += abs(dif[i]);
      }
    }
    assert(dif[n] == -dif[1]);
    sol += abs(dif[n]);
    cout << sol << "\n";

  }
}