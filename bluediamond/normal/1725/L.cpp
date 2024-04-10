#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int n;
ll p[N];
int t[N];

void add(int i) {
  while (i <= n) {
    t[i]++;
    i += i & (-i);
  }
}

int get(int i) {
  int sol = 0;
  while (i) {
    sol += t[i];
    i -= i & (-i);
  }
  return sol;
}

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie();
#endif /// ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE


  /// 2 <= i && i <= n - 1
  /// 1 <= i - 1
  /// i <= n - 1

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    p[i] = p[i - 1] + x;
  }

  bool is_doable = 1;
  for (int i = 1; i <= n - 1; i++) {
    is_doable &= (p[0] <= p[i]);
    is_doable &= (p[i] <= p[n]);
  }
  is_doable &= (p[0] <= p[n]);

  if (!is_doable) {
    cout << "-1\n";
    exit(0);
  }

  n--;


  map<ll, int> tr;
  for (int i = 1; i <= n; i++) {
    tr[p[i]] = 0;
  }
  int c = 0;
  for (auto &it : tr) {
    it.second = ++c;
  }

  ll invs = 0;
  for (int i = n; i >= 1; i--) {
    p[i] = tr[p[i]];
    invs += get(p[i] - 1);
    add(p[i]);
  }

  cout << invs << "\n";

  return 0;
}