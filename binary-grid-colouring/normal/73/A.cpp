#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


string s[123],ss[123];
int main(int argc, char const *argv[]) {

  ll x ,y,z,k;
  std::cin >> x >> y >> z >> k;
  ll xx=1,yy=1,zz=1;
  x--; y--; z--;
  while(k!=0)
  {
      if(x!=0)
      {
          x--;
          xx++;
          k--;
      }
      if(y!=0&&k!=0)
      {
          y--;
          yy++;
          k--;
      }
      if(z!=0&&k!=0)
      {
          z--;
          zz++;
          k--;
      }
      if(x==0&&y==0&&z==0) break;
   }
   std::cout << xx*yy*zz << '\n';
  return 0;
}