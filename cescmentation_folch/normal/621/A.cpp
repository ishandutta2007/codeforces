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
  vll V(n);
  
  ll res = 0;
  ll mi = 1e9 + 1;
  for (int i = 0; i < n; ++i) {
    cin >> V[i];
    res += V[i];
    if (V[i]%2 == 1 and mi > V[i]) mi = V[i];
  }
  
  if (res%2 == 1) res -= mi;
  cout << res << endl;
}