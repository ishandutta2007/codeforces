#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vi V(n);
  for (int i = 0; i < n; ++i) cin >> V[i];
  ll val = 0;
  for (int i = 0; i < n; ++i) {
    if (i) cout << ' ';
    if (V[i] >= 0) val += V[i];
    cout << val + min(0ll, V[i]);
  }
  cout << '\n';
}