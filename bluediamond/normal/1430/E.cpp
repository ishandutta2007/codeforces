#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 200000 + 7;
int tree[N];

void add(int i) {
  while (i < N) {
    tree[i]++;
    i += i & (-i);
  }
}

int get(int i) {
  int sol = 0;
  while (i) {
    sol += tree[i];
    i -= i & (-i);
  }
  return sol;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string t;
  cin >> n >> t;
  vector<vector<int>> p(26);
  for (int i = 0; i < n; i++) {
    int x = t[i] - 'a';
    p[x].push_back(i);
  }
  reverse(t.begin(), t.end());
  for (int i = 0; i < 26; i++) {
    reverse(p[i].begin(), p[i].end());
  }
  ll sol = 0;
  for (int i = 0; i < n; i++) {
    int x = t[i] - 'a';
    int pos = p[x].back() + 1;
    int now = i + 1;
    p[x].pop_back();
    sol += pos + (i - get(pos)) - now;
    add(pos);
  }
  cout << sol << "\n";

}