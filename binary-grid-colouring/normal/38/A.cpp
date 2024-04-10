#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
std::map<int, int> mp;
int a[1234];
int main(int argc, char const *argv[]) {
  int ans = 0;
  int n;
  std::cin >> n;
  for(int i=1;i<n;i++) {
    int b;
    std::cin >> b;
    a[i+1] = a[i] + b;
  }
  int A,B;
  std::cin >> A >> B;
  std::cout << a[B] - a[A] << '\n';
  return 0;
}