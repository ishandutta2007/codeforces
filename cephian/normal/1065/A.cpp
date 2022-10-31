#include <bits/stdc++.h>
using namespace std;

int main() {
  long long t,s,a,b,c;
  cin >> t;
  while(t--) {
    cin >> s >> a >> b >> c;
    long long tot = s/c;
    tot += tot/a * b;
    cout << tot << "\n";
  }
}