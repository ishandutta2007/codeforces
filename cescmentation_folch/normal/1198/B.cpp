#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vpi V(n);
  for (int i = 0; i < n; ++i) {
    cin >> V[i].second;
    V[i].first = i;
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    pi t;
    int k;
    cin >> k;
    if (k == 1) {
      cin >> t.first >> t.second;
      --t.first;
    } else {
      t.first = -1;
      cin >> t.second;
    }
    V.push_back(t);
  }
  vi R(n, -1);
  int mn = 0;
  for (int i = (int)V.size() - 1; i >= 0; --i) {
    if (V[i].first == -1) {
      mn = max(mn, V[i].second);
    } else {
      int ind = V[i].first;
      if (R[ind] == -1) {
        R[ind] = max(mn, V[i].second);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i) cout <<' ';
    cout << R[i];
  }
  cout << endl;
}