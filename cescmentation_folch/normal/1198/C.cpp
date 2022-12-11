#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef unordered_set<int> usi;
typedef vector<usi> vusi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vpi A(m);
    vi V(3*n, 0);
    for (int i = 0; i < m; ++i) {
      cin >> A[i].first >> A[i].second;
      --A[i].first; --A[i].second;
    }
    int ind = 0;
    vi R;
    while (R.size() < n and ind < m) {
      if (!V[A[ind].first] and !V[A[ind].second]) {
        V[A[ind].first] = V[A[ind].second] = 1;
        R.push_back(ind);
      }
      ++ind;
    }
    if (R.size() == n) {
      cout << "Matching\n";
      for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << R[i] + 1;
      }
      cout << '\n';
    }
    else {
      cout << "IndSet\n";
      int cont = 0;
      int i = 0;
      while (cont < n) {
        if (!V[i]) {
          if (cont) cout << ' ';
          cout << i + 1;
          ++cont;
        }
        ++i;
      }
      cout << '\n';
    }
  }
}