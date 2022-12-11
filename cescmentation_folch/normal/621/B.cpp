#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main() {
  int n;
  cin >> n;
  vll R(2000 + 10, 0);
  vll T(2000 + 10, 0);
  
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    R[x - y + 1000]++;
    T[x + y]++;
  }
  
  ll res = 0;
  for (int i = 0; i < 2000 + 10; ++i) {
    if (R[i] > 1) {
      res += R[i]*(R[i] - 1)/2;
    }
    if (T[i] > 1) {
      res += T[i]*(T[i] - 1)/2;
    }
  }
  
  cout << res << endl;
}