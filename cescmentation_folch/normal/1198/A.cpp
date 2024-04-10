#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  int b;
  cin >> n >> b;
  b *= 8;
  int tt = min(30, b/n);
  int val = (1<<tt);
  vi V(n);
  for (int i = 0; i < n; ++i) cin >> V[i];
  sort(V.begin(), V.end());
  int ant = -1;
  int vlal = -1;
  for (int i = 0; i < n; ++i) {
    if (V[i] != vlal) {
      ++ant;
      vlal = V[i];
    }
    V[i] = ant;
  }
  
  int res = n;
  int it2 = 0;
  int it1 = 0;
  while (it1 < n) {
    it2 = max(it2, it1);
    while (it2 < n-1 and V[it2+1] - V[it1] < val) ++it2;
    res = min(res, n - (it2 - it1 + 1));
    ++it1;
  }
  cout << res << '\n';
}