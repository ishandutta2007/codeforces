#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 100100;
int sv[N], degv[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  set<tuple<int, int>> st;
  int n;
  cin >> n;
  int dsum = 0;
  for (int i=0; i<n; ++i) {
    int deg, s;
    cin >> deg >> s;
    sv[i] = s;
    degv[i] = deg;
    if (!deg) {
      continue;
    }
    dsum += deg;
    st.insert({deg, i});
  }
  assert(dsum %2 == 0);
  cout << dsum/2 << "\n";
  while (!st.empty()) {
    auto [deg, i] = *st.begin();
    st.erase({deg, i});
    assert(deg == 1);
    int s = sv[i];
    sv[i] ^= s;
    degv[i] --;
    
    int x = s;
    int degx = degv[x];
    st.erase({degx, x});
    cout << i << " " << x << "\n";
    --degv[x];
    sv[x]^= i;
    if (degv[x]) {
      st.insert({degv[x], x});
    }
  }
  return 0;
}