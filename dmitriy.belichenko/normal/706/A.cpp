#include <iostream>
#include <bits/c++io.h>
#include <math.h>
using namespace std;
int main()
{
  int a , b , n , x , y , v;
  double mn = 100001;
  cin >> a >> b >> n;
  for(int i = 0; i < n; i++ )
    {
     cin >> x >> y >> v;
     mn = min( sqrt( (a - x)* ( a- x ) + (b - y)* (b - y ) )/  v , mn);
    }
printf("%.9f\n", mn);
}