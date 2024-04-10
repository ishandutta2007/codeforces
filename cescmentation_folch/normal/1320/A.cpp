#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, ll> M;
  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;
    int k = b - i;
    M[k] += b;
  }
  ll res = 0;
  for (auto it : M) {
    res = max(res, it.second);
  }
  cout << res << '\n';
}