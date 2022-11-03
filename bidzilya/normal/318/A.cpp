#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
   ll n,k;
   cin >> n >> k;
   if (k > n-n/2)
   {
      k -= (n-n/2);
      cout << 2*k << endl;
   }else
      cout << 2*k-1 << endl;
   return 0;
}