#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1010;
char s[N];
char t[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n, m;
    cin >> n >> m;
    cin >> (s+1);
    t[n+1] = 0;
    t[0] = 0;
    for (int i=1; i<=n; ++i) {
      t[i] = s[i];
    }
    int score = 0;
    for (int i=1; i<=n; ++i) {
      if (score > 0) {
        t[i] = '1';
      }
      --score;
      if (s[i] == '1') {
        score = m;
      }
    }
    score = 0;
    for (int i=n; i>=1; --i) {
      if (score > 0) {
        t[i] = '1';
      }
      --score;
      if (s[i] == '1') {
        score = m;
      }
    }
    for (int i=1; i<=n; ++i) {
      if (s[i] == '1') {
        continue;
      }
      int j;
      for (j=i; j<=n && s[j] == '0'; ++j);
      if (i != 1 && j != n+1 && (j-i)%2) {
        t[(i+j)/2] = '0';
      }
      i = j-1;
    }
    cout << (t+1) << "\n";
  }
  return 0;
}