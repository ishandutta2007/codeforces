#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    if (s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0') {cout << "YES\n";continue;}
    if (s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n - 1] == '0') {cout << "YES\n";continue;}
    if (s[0] == '2' && s[1] == '0' && s[n - 2] == '2' && s[n - 1] == '0') {cout << "YES\n";continue;}
    if (s[0] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0') {cout << "YES\n";continue;}
    if (s[n - 4] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0') {cout << "YES\n";continue;}
    cout << "NO\n";
  }
}