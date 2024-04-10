#include <iostream>
using namespace std;
int main()
{
  int  n , cnt = 0;
  cin >> n;
  int a[n];
 if ( n != 1 )
    for (int i = 0; i < n; i++)
        {
         cin >> a[i];
         if( a[i] == 0) cnt++;
        }
  else
        {
          cin >> a[0];
          if( a[0] == 1 ) cnt++;

        }
  if(cnt != 1) cout << "NO";
  else cout << "YES";
}