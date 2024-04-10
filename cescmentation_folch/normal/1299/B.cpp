#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

bool eq(pi a, pi b) {
  if (a.first*a.first + a.second*a.second != b.first*b.first + b.second*b.second) return false;
  if (a.first*b.second - a.second*b.first != 0) return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vpi V(n);
  for (int i = 0; i < n; ++i) cin >> V[i].first >> V[i].second;
  if (n%2) {
    cout << "NO" << '\n';
    return 0;
  }
  for (int i = 0; i < n/2; ++i) {
    int j = i + n/2;
    pi a = pi(V[i+1].first - V[i].first, V[i+1].second - V[i].second);
    pi b = pi(V[(j+1)%n].first - V[j].first, V[(j+1)%n].second - V[j].second);
    if (!eq(a,b)) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
}