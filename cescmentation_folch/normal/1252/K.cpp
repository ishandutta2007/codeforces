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
  cin >> n;
  vi V(n);
  vi B(32, 0);
  for (int i = 0; i < n; ++i) {
    cin >> V[i];
    for (int j = 0; j < 32; ++j) {
      if ((1<<j)&V[i]) ++B[j];
    }
  }
  int maxi = 0;
  for (int i = 0; i < n; ++i) {
    int val = 0;
    for (int j = 0; j < 32; ++j) {
      if ((1<<j)&V[i] and B[j] == 1) {
        val += (1<<j);
      }
    }
    if (val > maxi) {
      maxi = val;
      swap(V[i], V[0]);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i) cout << ' ';
    cout << V[i];
  }
  cout << endl;
}