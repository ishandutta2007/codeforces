#include <bits/stdc++.h>
using namespace std;

int main() {
   int t;
   cin >> t;
   while(t--) {
      long long a, b, t;
      cin >> a >> b >> t;
      cout << a * (t-t/2) - b * (t/2) << "\n";
   }
}