#include <iostream>
#include <string>
using namespace std;
int main()
{
  int n, a = 0, b = 0;
  cin >> n;
  int m[n];
  int c[n];
 for(int i = 0; i < n; i++ )
    {
     cin >> m[i] >> c[i];
     if( m[i] > c[i] ) a++;
     if( m[i] < c[i] ) b++;

    }
  if(a > b)

    cout << "Mishka";
    if(a < b ) cout << "Chris";
    if(a == b) cout << "Friendship is magic!^^";
}