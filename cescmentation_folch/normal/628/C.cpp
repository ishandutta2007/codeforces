#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, t;
  cin >> n >> t;
  
  string a;
  char mander;
  
  for (int i = 0; i < n; ++i) {
    cin >> mander;
    int r = mander - 'a';
    
    if (r > 25 - r) {
      a.push_back('a');
      t -= r;
//       cerr << a[i] << endl;
      if (t < 0) {
	a[i] = 'a' - t;
	t = 0;
      }
    }
    else {
      t -= 25 - r;
      a.push_back('z');
//        cerr << a[i] << endl;
      if (t < 0) {
	a[i] = 'z' + t;
	t = 0;
      }
    }
  }
  
  if (t == 0) cout << a << endl;
  else cout << -1 << endl;
}