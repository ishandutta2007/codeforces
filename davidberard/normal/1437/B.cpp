#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int zero=0, one=0;
    for (int i=0; i<n-1; ++i) {
      zero += (s[i] == '0' && s[i+1] == '0');
      one  += (s[i] == '1' && s[i+1] == '1');
    }
    cout << max(zero, one) << endl;
  }
  return 0;
}