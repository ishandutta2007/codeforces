#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  if (n) cout << 2 << endl;
  for (ll i = 3; i <= n + 1; ++i) {
    cout << i*i*(i-1ll) - (i - 2) << endl;
  }
}