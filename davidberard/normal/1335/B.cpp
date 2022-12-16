#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    for (int i=0; i<a-b+1; ++i) {
      s += 'a';
    }
    for (int i=0; i<b-1; ++i) {
      s += (char) ('a'+i+1);
    }
    for (int i=0; i<n-a; ++i) {
      s += s[i];
    }
    cout << s << endl;
  }
  return 0;
}