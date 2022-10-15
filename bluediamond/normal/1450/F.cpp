#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n, a[N], f[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  while (t--) {
    cin >> n;
    int fmax = 0, k = 0;
    for (int i = 1; i <= n; i++) f[i] = 0;
    for (int i = 1; i <= n; i++) {cin >> a[i]; f[a[i]]++; fmax = max(fmax, f[a[i]]);}
    if (fmax > (n + 1) / 2) {cout << "-1\n"; continue;}
    vector<int> split = {0};
    for (int i = 1; i < n; i++) if (a[i] == a[i + 1]) split.push_back(i), k++;
    split.push_back(n);
    for (int i = 1; i <= n; i++) f[i] = 0;
    for (int it = 0; it + 1 < (int) split.size(); it++) {
      int l = split[it] + 1, r = split[it + 1];
      f[a[l]]++;
      f[a[r]]++;
    }
    fmax = 0;
    for (int i = 1; i <= n; i++) fmax = max(fmax, f[i]);
    cout << k + max(0, fmax - (k + 2)) << "\n";
    continue;
    cout << fmax << " " << k + 2 << "\n";
  }

}