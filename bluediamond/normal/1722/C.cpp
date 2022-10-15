#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    map<string, int> freq;
    vector<vector<string>> a(3, vector<string>(n));
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
        freq[a[i][j]]++;
      }
    }
    for (int i = 0; i < 3; i++) {
      int score = 0;
      for (string s: a[i]) {
        int f = freq[s];
        if (f == 1) score += 3;
        if (f == 2) score += 1;
      }
      cout << score << ' ';
    }
    cout << '\n';
  }
}