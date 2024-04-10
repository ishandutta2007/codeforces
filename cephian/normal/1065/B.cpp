#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;
  long long clique = 0;
  while(clique*(clique-1)/2 < m)
    ++clique;
  cout << max(0LL, n-2*m) << " " << n-clique << "\n";
}