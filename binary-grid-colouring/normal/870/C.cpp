#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;

int main(int argc, char const *argv[]) {
  int q;
  std::cin >> q;
  while (q--) {
    /* code */
    int n;
    scanf("%d",&n);
    if(n < 4 || n==5 || n==7 || n==11) {
      std::cout << "-1" << '\n';
      continue;
    }
    if(n%4==0) std::cout << n / 4 << '\n';
    else if(n%4==1)
    {
        if(n<9) std::cout << "-1" << '\n';
        else std::cout << (n-9)/4+1 << '\n';
    }
    else if(n%4==2)
    {
        if(n<6) std::cout << "-1" << '\n';
        else std::cout << (n-6)/4+1 << '\n';
    }
    else
    {
        if(n<=11) std::cout << "-1" << '\n';
        else std::cout << (n-11)/4+1 << '\n';
    }
  }
  return 0;
}