#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef int llint;
typedef vector<llint> vi;
typedef vector<vi> vvi;
typedef pair<llint, llint> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int tot = 0;
  int col = 0;
  int al;
  vi res;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    tot += x;
    if (i) {
      if (2*x <= al) {
        col += x;
        res.push_back(i+1);
      }
    }
    else {
      col += x;
      al = x;
      res.push_back(1);
    }
  }
  if (2*col > tot) {
    cout << res.size() << endl;
    for (int i = 0; i < (int)res.size(); ++i) {
      if (i) cout << ' ' ;
      cout << res[i];
    }
    cout << endl;
  }
  else {
    cout << 0 << endl;
  }
}