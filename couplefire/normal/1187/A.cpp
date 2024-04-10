#include <bits/stdc++.h>
using namespace std;

int main() {
  int p;
  cin >> p;
  for(int i = 0; i<p; i++){
    int n, s, t;
    cin >> n >> s >> t;
    int ma = max(s, t);
    cout << ma-(s+t-n)+1 << endl;
  }
}