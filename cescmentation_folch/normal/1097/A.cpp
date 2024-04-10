#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<pld> vpld;
typedef vector<vpld> vvpld;

int main() {
  string a;
  cin >> a;
  for (int i = 0; i < 5; ++i) {
    string b;
    cin >> b;
    if (b[0] == a[0] or b[1] == a[1]) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
}