#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int ntest; cin >> ntest;
  while(ntest--) {
    int n; cin >> n;
    if(n == 1) cout << -1 << endl;
    else {
      cout << 8;
      for(int i = 1; i < n; ++i) cout << 9;
      cout << endl;
    }
  }

  return 0;
}