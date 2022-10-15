#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3000 + 7;
int n;
int a[N];
int pre[N];
int mid[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pre[a[i]] = 0;
    }
    ll sol = 0;
    for (int i = 1; i <= n; i++) {
      ll cur = 0;
      for (int j = 1; j <= n; j++) {
        mid[j] = 0;
      }
      for (int j = i + 1; j <= n; j++) {
        if (a[i] == a[j]) {
          sol += cur;
        }
        cur -= mid[a[j]] * pre[a[j]];
        mid[a[j]]++;
        cur += mid[a[j]] * pre[a[j]];
      }
      pre[a[i]]++;
    }
    cout << sol << "\n";
  }
  return 0;
}