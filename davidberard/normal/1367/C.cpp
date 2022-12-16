#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int pre = -k-1;
    int ans = 0;
    for (int i=0; i<=s.size(); ++i) {
      if (i == s.size() || s[i] == '1') {
        if (i == s.size()) {
          i = s.size()+k;
        }
        //cerr << "! " << pre << " -> " << i << endl;
        for (int j=pre+k+1; j<i-k; j+=k+1) {
          ++ans;
        }
        pre = i;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}