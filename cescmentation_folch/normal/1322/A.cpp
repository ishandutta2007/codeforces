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
  string a;
  cin >> n >> a;
  int k = 0;
  for (int i = 0; i < n; ++i) if (a[i] == '(') ++k;
  if (2*k != n) {
    cout << -1 << endl;
    return 0;
  }
  int res = 0;
  int ac = 0;
  int ant = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == '(') {
      ++ac;
      if (ac == 0) {
        res += i - ant + 1;
      }
    }
    else {
      --ac;
      if (ac == -1) ant = i;
    }
  }
  cout << res << endl;
}