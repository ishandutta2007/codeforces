#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> a;
int n,m;

int main()
{
   cin >> n >> m;
   a.resize(n);
   for (int i=0; i<n; ++i)
      cin >> a[i];
   ll sum = 0;
   for (int i=0; i<m; ++i)
   {
      int t;
      cin >> t;
      if (t == 1)
      {
         int q;
         ll x;
         cin >> q >> x;
         a[q-1] = x-sum;
      }else
      if (t == 2)
      {
         ll y;
         cin >> y;
         sum += y;
      }else
      {
         int q;
         cin >> q;
         cout << a[q-1]+sum << endl;
      }
   }        
   return 0;
}