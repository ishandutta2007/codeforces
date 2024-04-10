#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void print(vector<int> v) {
  cout << " ----> ";
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << "\n";
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    if (n % 2 == 1) {
      cout << "NO\n";
      continue;
    }
    sort(a.begin(), a.end());
    vector<int> av;
    vector<int> requests;

    for (int i = n / 2; i < n; i++) {
      av.push_back(a[i]);
    }
    for (int i = 0; i < n / 2; i++) {
      requests.push_back(max(a[i], a[(i + 1) % (n / 2)]));
    }

    assert((int) av.size() == n / 2);
    assert((int) requests.size() == n / 2);

    sort(av.begin(), av.end());
    sort(requests.begin(), requests.end());

    /**
    print(av);
    print(requests);
    **/
    bool ok = 1;
    for (int i = 0; i < n / 2; i++) {
      ok &= (av[i] > requests[i]);
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        cout << a[i / 2] << " ";
      } else {
        cout << a[i / 2 + n / 2] << " ";
      }
    }
    cout << "\n";
  }
}