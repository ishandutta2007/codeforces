#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

int n,m,x,y,a,b;

int nod(int a, int b)
{
   while (a > 0 && b > 0)
      if (a >= b)
         a %= b;
      else
         b %= a;
   return a + b;
}

int main()
{
   cin >> n >> m >> x >> y >> a >> b;
   
   int temp = nod(a,b);
   a /= temp;
   b /= temp;
   
   int k = min(n/a, m/b);
   int lx = k*a;
   int ly = k*b;
    
   int x1 = x - lx/2;
   int y1 = y - ly/2;
   if (lx%2 != 0)
      --x1;
   if (ly%2 != 0)
      --y1;
   x1 = max(x1, 0);
   y1 = max(y1, 0);
   x1 = min(x1, n-lx);
   y1 = min(y1, m-ly);

   cout << x1 << " " << y1 << " " << x1+lx << " " << y1+ly << endl;
   return 0;
}