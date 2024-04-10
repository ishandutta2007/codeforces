#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

int main()
{
   ll a,b,m;
   cin >> a >> b >> m;
   ll h = 0;
   while (a < m && b < m)
   {
      if (a > b) swap(a, b);
      ll sum = a + b;
      if (b <= 0)
      {
         cout << -1 << endl;
         return 0;
      }
      ll k = (b-a)/b;
      a += k*b;
      h += k;
      if (a <= b)
      {
         ++h;
         a += b;
      }
      if (a+b <= sum)
      {
         cout << -1 << endl;
         return 0;
      }
   }
   cout << h << endl;
   return 0;
}