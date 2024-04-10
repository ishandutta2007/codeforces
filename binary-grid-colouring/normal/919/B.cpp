#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum(int x)
{
  int res = 0;
  while(x)
  {
    res += (x % 10);
    x /= 10;
  }
  return res;
}
int main(int argc, char const *argv[]) {

  int k;
  int i =18;
  std::cin >> k;
  while(k)
  {
    i++;
    if(sum(i)==10) {
      k--;
    }
  }
  std::cout << i << '\n';
  return 0;
}