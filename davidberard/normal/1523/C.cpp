#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1010;
int a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n;
    cin >> n;
    vector<int> cur(1, 0);
    for (int i=1; i<=n; ++i) {
      cin >> a[i];
      if (a[i] == cur.back()+1) {
        cur.back()++;
      } else if (a[i] == 1) {
        cur.push_back(1);
      } else {
        while(cur.size() && cur.back()+1 != a[i]) {
          cur.pop_back();
        }
        assert(cur.size());
        cur.back()++;
      }
      for (int j=0; j<cur.size(); ++j) {
        cout << cur[j];
        if (j+1 != cur.size()) {
          cout << ".";
        }
      }
      cout << "\n";
    }
  }
  return 0;
}