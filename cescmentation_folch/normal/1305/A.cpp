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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi A(n), B(n);
    for (auto& a : A) cin >> a;
    for (auto& a : B) cin >> a;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ';
      cout << A[i];
    }
    cout << '\n';
    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ';
      cout << B[i];
    }
    cout << '\n';
  }
}