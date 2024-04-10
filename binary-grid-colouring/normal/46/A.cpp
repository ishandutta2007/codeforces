#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
std::map<int, int> mp;


int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  int k = 2;
  std::cout << "2" <<" ";
  for(int i=2;i<n;i++) {
    std::cout <<( (k+i)%n==0? (k+i): (k+i)%n )<<" ";
    k = (k+i)%n==0? (k+i): (k+i)%n;
  }
  std::cout << '\n';
  return 0;
}