#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int sum[2][20];

int main(){
  int tt; cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < 20; ++i) sum[0][i] = sum[1][i] = 0;
    for (int i = 0; i < n; ++i) {
      ll now = 0;
      int kek = i;
      if (i % 2 == 0) {
        ll step = 1;
        for (int j = 0; j < 20; ++j) {
          ll suka = (-sum[0][j] + sum[1][j] + (kek % k)) % k;
          if (suka < 0) suka += k;
          now += suka * step;
          kek /= k;
          step *= k;
          if (step > 1e9) break;
        }

      } else {
        ll step = 1;
        for (int j = 0; j < 20; ++j) {
          ll suka = (sum[0][j] - sum[1][j] - (kek % k)) % k;
          if (suka < 0) suka += k;
          now += suka * step;
          kek /= k;
          step *= k;
          if (step > 1e9) break;
        }
      }
      cout << now << endl;
      ll wtf; cin >> wtf; if (wtf == 1) break;
      for (int j = 0; j < 20; ++j) {
        sum[i % 2][j] += now % k;
        now /= k;
      }
    }
  }
}