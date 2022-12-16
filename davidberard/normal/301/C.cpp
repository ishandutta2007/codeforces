#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

string z[110];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> z[i];
  }

  for (int i=0; i<=9; ++i) {
    cout << "???" << i << ">>" << i << "???\n";
  }
  for (int i=0; i<=9; ++i) {
    cout << i << "???" << ">>" << i << "??\n";
  }
  for (int i=0; i<=8; ++i) {
    cout << i << "??" << ">>" << "?" << (i+1) << "\n";
  }
  cout << "9??>>??0\n";
  cout << "??>>?1\n";
  cout << "?<>\n";
  for (int i=0; i<=9; ++i) {
    cout << i << ">>" << i << "???\n";
  }
  return 0;
}