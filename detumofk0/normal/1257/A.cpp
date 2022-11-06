#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int ntest; cin >> ntest;
  while(ntest--) {
    int n, x, a, b;
    cin >> n >> x >> a >> b;
    if(a > b) swap(a, b);
    int na = max(a - x, 1);
    x -= a - na;
    int nb = min(b + x, n);
    cout << nb - na << endl;
  }

  return 0;
}