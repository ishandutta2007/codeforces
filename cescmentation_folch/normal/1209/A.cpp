#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef vector<pi> vpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vi V(n);
  for (int i = 0; i < n; ++i) cin >> V[i];
  sort(V.begin(), V.end());
  vi R;
  for (int i = 0; i < n; ++i) {
    bool pot = false;
    for (int j = 0; j < (int)R.size() and !pot; ++j) {
      if (V[i]%R[j] == 0) {
        pot = true;
      }
    }
    if (!pot) R.push_back(V[i]);
  }
  cout << R.size() << endl;
}