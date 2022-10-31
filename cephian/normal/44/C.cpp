#include <iostream>

using namespace std;

int n,m;
int d[105]={0};

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i < m; ++i) {
    int a,b;
    cin >> a >> b;
    for(int j = a; j <= b; ++j)
      ++d[j];
  }
  for(int k = 1; k <= n; ++k) {
    if(d[k] != 1) {
      cout << k <<" " << d[k] << "\n";
      return 0;
    }
  }
  cout << "OK\n";
  return 0;
}