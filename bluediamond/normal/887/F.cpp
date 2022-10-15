#include <bits/stdc++.h>

using namespace std;

const int N = (int) 5e5 + 7;
int n, k, aib[N];

void clr() {
  for (int i = 1; i <= n; i++) {
    aib[i] = 0;
  }
}

int get(int i) {
  int sol = 0;
  while (i) {
    sol += aib[i];
    i -= i & (-i);
  }
  return sol;
}

void add(int i, int x) {
  while (i <= n) {
    aib[i] += x;
    i += i & (-i);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> k;
  vector<pair<int, int>> events;
  for (int i = 1; i <= n; i++) {
    int foo;
    cin >> foo;
    events.push_back({foo, i});
  }
  sort(events.begin(), events.end());
  int lmax = -(int) 1e9, rmin = -lmax, firstInd = -1;
  add(1, +1);
  add(1 + k, -1);
  for (int i = 0; i < n; i++) {
    events[i].second = n + 1 - events[i].second;
    int j = events[i].second;
    if (!get(j)) {
      if (firstInd == -1) {
        firstInd = i;
      }
      lmax = max(lmax, j - k);
      rmin = min(rmin, j);
    }
    add(j, +1);
    add(j + k + 1, -1);
  }

  if (firstInd == -1) {
    cout << "YES\n";
    return 0;
  }

  if (lmax > rmin) {
    cout << "NO\n";
    return 0;
  }

  clr();
  add(1, +1);
  add(1 + k, -1);
  for (int i = 0; i < firstInd; i++) {
    int j = events[i].second;
    if (j < lmax && get(lmax)) {
      cout << "YES\n";
      return 0;
    }
    add(j, +1);
    add(j + k + 1, -1);
  }
  cout << "NO\n";



  return 0;
}