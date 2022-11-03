#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

int n;
ll k;

int main()
{
   cin >> n >> k;
   ll sum = 0;
   int del = 0;
   for (int i=1; i<=n; ++i)
   {
      ll a;
      cin >> a;
      ll cur = sum-(n-i)*a*(i-1-del);
      if (cur < k)
      {
         cout << i << endl;
         ++del;
      }else
         sum += a*(i-1-del);
   }

   return 0;
}