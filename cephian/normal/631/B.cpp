#include <iostream>
#include <map>
#include <set>

using namespace std;

int r[5005]={0},c[5005]={0},tr[5005]={0},tc[5005]={0};
int R,C,k;

int main() {
  cin >> R >> C >> k;
  for(int q = 1; q <= k; ++q) {
    int t,p,a;
    cin >> t >> p >> a;
    --p;
    if(t==1) {
      r[p] = a;
      tr[p] = q;
    } else {
      c[p] = a;
      tc[p] = q;
    }
  }
  for(int i = 0; i < R; ++i) {
    for(int j = 0; j < C; ++j) {
      if(tr[i] > tc[j]) cout << r[i];
      else cout << c[j];
      cout << " ";
    }
    cout << "\n";
  }
}