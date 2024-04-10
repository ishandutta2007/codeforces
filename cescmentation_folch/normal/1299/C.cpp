#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef pair<int, ld> pil;
typedef vector<pil> vpil;

vi P;
int pare(int x) {
  if (P[x] == -1) return x;
  return P[x] = pare(P[x]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  P = vi(n, -1);
  vector<ld> V(n);
  vector<pi> vp(n);
  queue<pi> Q;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    V[i] = x;
    vp[i] = pi(i,i);
    if (i and V[i-1] > V[i]) {
      Q.push(pi(i-1, i));
    }
  }
  while (!Q.empty()) {
    int x = pare(Q.front().first);
    int y = pare(Q.front().second);
    Q.pop();
    if (x == y) continue;
    P[y] = x;
    int d1 = vp[x].second - vp[x].first + 1;
    int d2 = vp[y].second - vp[y].first + 1;
    vp[x].second = vp[y].second;
    V[x] = ld(V[x]*d1 + V[y]*d2)/ld(d1+d2);
    int l = vp[x].first -1 ;
    if (l >= 0 and V[pare(l)] > V[x]) Q.push(pi(l, x));
    int r = vp[x].second +1;
    if (r < n and V[pare(r)] < V[x]) Q.push(pi(x, r));
  }

  for (int i = 0; i < n; ++i) {
    cout << fixed << setprecision(10) << V[pare(i)] << '\n';
  }
}