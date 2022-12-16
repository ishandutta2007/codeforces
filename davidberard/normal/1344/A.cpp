#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;
ll a[N];
unordered_set<ll> st;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    st.clear();
    int n;
    cin >> n;
    ll extra = ((ll) (2e9)/n)*n;
    for (int i=0; i<n; ++i) {
      cin >> a[i];
      st.insert((i+a[i]+extra)%n);
    }
    cout << (st.size() == n ? "YES" : "NO") << "\n";
  }
  return 0;
}