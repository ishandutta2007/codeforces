#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef int llint;
typedef vector<llint> vi;
typedef vector<vi> vvi;
typedef pair<llint, llint> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

vvi G;
void dik(int s, vi& R) {
  queue<int> Q;
  Q.push(s);
  R[s] = 0;
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    for (auto y : G[x]) {
      if (R[y] == -1) {
        R[y] = R[x] + 1;
        Q.push(y);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  G = vvi(n);
  vi S(k);
  for (int i = 0; i < k; ++i) {
    cin >> S[i];
    --S[i];
  } 
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  vi R1(n, -1), R2(n, -1);
  dik(0, R1);
  dik(n-1, R2);
  vpi D(k);
  for (int i = 0; i < k; ++i) {
    D[i] = pi(R1[S[i]], R2[S[i]]);
  }
  sort(D.begin(), D.end());
  vi F(k);
  for (int i = k-1; i >= 0; --i) {
    F[i] = D[i].second;
    if (i < k-1) F[i] = max(F[i], F[i+1]);
  }
  int a = 0;
  int b = R1[n-1] +1;
  while (a+1 < b) {
    int c= (a+b)/2;
    bool pots = false;
    for (int i = 0; i < k; ++i) {
      int l = i;
      int r = k;
      while (l+1 < r) {
        int d = (l+r)/2;
        if (D[i].second + 1 + D[d].first >= c) r = d;
        else l = d;
      }
      if (r == k) continue;
      if (F[r] + 1 + D[i].first >= c) {
        pots = true;
        break;
      }
    }
    if (pots) a = c;
    else b = c;
  }
  cout << a << '\n';
}