#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x,y;
int Ciel()
{
  if(x>=2 && y >= 2) {
    x -= 2;
    y -= 2;
  }
  else if(x >= 1 && y >= 12) {
    x -= 1;
    y -= 12;
  }
  else if(y >= 22) {
    y -= 22;
  }
  else {
    std::cout << "Hanako" << '\n';return 1;
  }
  return 0;
}
int Hanako()
{
  if(y>=22) {
    y-=22;
  }
  else if(x>=1 && y>=12) {
    x-= 1;
    y-= 12;
  }
  else if(x>=2 && y >= 2) {
    x -= 2;
    y -= 2;
  }
  else
  {
    std::cout << "Ciel" << '\n';
    return 1;
  }
  return 0;
}
int main(int argc, char const *argv[]) {
  std::cin >> x >> y;
  while(1)
  {
    if(Ciel() || Hanako()) break;
  }
  return 0;
}