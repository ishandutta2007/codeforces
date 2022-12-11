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
typedef long double ld;
typedef vector<ld> vld;

int main() {
  int n, p;
  cin >> n >> p;
  vld V(n);
  
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    int k = x/p;
    int q = y/p;
    
    V[i] = ld(q - k)/ld(y - x);
  }
  
  ld res = 0;
  
  for (int i = 0; i < n; ++i) {
    int ant = (i - 1 + n)%n;
    int next = (i + 1)%n;
    
    res += 1000.0*(2*V[i] + (1.0 - V[i])*(V[ant] + V[next]));
  }
  
  cout << setprecision(10) << fixed << res << endl;
}