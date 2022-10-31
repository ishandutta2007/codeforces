#include <iostream>

using namespace std;

int g[100][100];

int main() {
  int k;
  cin >> k;
  for(int i = 0; i < 100; ++i)
    for(int j = 0; j < 100; ++j)
      g[i][j] = 0;
  int ks = 3;
  while((ks*(ks-1)*(ks+1))/6 <= k)
    ++ks;
  for(int i = 0; i < ks; ++i)
    for(int j = 0; j < ks; ++j)
      g[i][j] = i != j;
  k -= (ks*(ks-1)*(ks-2))/6;
  while(k) {
    int j = 1;
    int add = 0;
    while(add+j <= k) {
      add += j;
      ++j;
    }
    k -= add;
    for(int i = 0; i < j; ++i)
      g[ks][i] = g[i][ks] = 1;
    ++ks;
  }
  cout << ks << "\n";
  for(int i = 0; i < ks; ++i) {
    for(int j = 0; j < ks; ++j)
      cout << g[i][j];
    cout << "\n";
  }

  return 0;
}