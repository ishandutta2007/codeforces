#include <iostream>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int a = 0;
  for(int i = 0; i < n; ++i)
    a += (s[i]=='1');
  cout << max(n-2*a, 2*a-n) << "\n";

  return 0;
}