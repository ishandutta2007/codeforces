#include <bits/stdc++.h>

using namespace std;

const int N = (int) 5e5 + 7;
const int A = 22;
const int INF = (int) 1e9;
int n;
int h[N];
int x[N];
int l[N];
int r[N];
int ord[N];
int sol[N];
int top;
int mh[1 << A];
vector<int> g[N];

void bb(int a) {
  ord[++top] = a;
  l[a] = top;
  for (auto &b : g[a]) {
    h[b] = 1 + h[a];
    x[b] ^= x[a];
    bb(b);
  }
  r[a] = top;
}

void dd(int a) {
  if (g[a].empty()) {
    mh[x[a]] = h[a];
  } else {
    int c = 0;
    for (auto &b : g[a]) {
      if (r[b] - l[b] > r[c] - l[c]) {
        c = b;
      }
    }
    for (auto &b : g[a]) {
      if (b != c) {
        dd(b);
        sol[a] = max(sol[a], sol[b]);
        for (int j = l[b]; j <= r[b]; j++) {
          int i = ord[j];
          mh[x[i]] = -INF;
        }
      }
    }
    dd(c);
    mh[x[a]] = max(mh[x[a]], h[a]);
    sol[a] = max(sol[a], sol[c]);
    for (auto &b : g[a]) {
      if (b != c) {
        for (int j = l[b]; j <= r[b]; j++) {
          int i = ord[j];
          sol[a] = max(sol[a], h[i] + mh[x[i]] -  2 * h[a]);
          for (int bt = 0; bt < A; bt++) {
            sol[a] = max(sol[a], h[i] + mh[x[i] ^ (1 << bt)] - 2 * h[a]);
          }
        }
        for (int j = l[b]; j <= r[b]; j++) {
          int i = ord[j];
          mh[x[i]] = max(mh[x[i]], h[i]);
        }
      }
    }
    sol[a] = max(sol[a], mh[x[a]] - h[a]);
    for (int bt = 0; bt < A; bt++) {
      sol[a] = max(sol[a], mh[x[a] ^ (1 << bt)] - h[a]);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < (1 << A); i++) {
    mh[i] = -INF;
  }
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int p;
    string s;
    cin >> p >> s;
    g[p].push_back(i);
    x[i] = (1 << (s[0] - 'a'));
  }
  bb(1);
  dd(1);
  for (int j = 1; j <= n; j++) {
    cout << sol[j] << " ";
  }
  cout << "\n";
}