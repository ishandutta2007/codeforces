#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

const int SIZE = 100;

int a[SIZE][SIZE][SIZE];

int main()
{
   int r,g,b;
   cin >> r >> g >> b;
   if (g < r) swap(r, g);
   if (b < r) swap(r, b);
   if (b < g) swap(g, b);
   int ans = (g-r)/3 + (b-r)/3;
   g = g - (g-r)/3*3;
   b = b - (b-r)/3*3;
   ans += r;
   if (r > 0 && g-r == 2 && b-r==2)
      ++ans;
   
   cout << ans << endl;
   return 0;
}