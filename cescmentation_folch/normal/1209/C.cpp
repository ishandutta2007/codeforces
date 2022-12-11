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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a;
    cin >> a;
    vi A, B;
    vi M(n);
    int m = 9;
    for (int i = n-1; i >= 0; --i) {
      m = min(m, int(a[i]-'0'));
      M[i] = m;
    }
    m = 9;
    for (int i = 0; i < n; ++i) {
      int k = a[i] - '0';
      if (k <= m and k <= M[i]) A.push_back(i);
      else {
        m = min(k, m);
        B.push_back(i);
      }
    }
    bool pot = true;
    for (int i = 1; i < (int)B.size(); ++i) {
      if (a[B[i-1]] > a[B[i]]) {
        pot = false;
        break;
      }
    }
    if (!pot) {
      cout << "-\n";
    } else {
      string R(n, '0');
      for (int i = 0; i < (int)A.size(); ++i)
        R[A[i]] = '1';
      for (int i = 0; i < (int)B.size(); ++i)
        R[B[i]] = '2';
      cout << R << '\n';
    }
  }
}