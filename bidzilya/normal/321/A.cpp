#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

int n,m;
string s;

int main()
{
   cin >> n >> m >> s;
   
   int x = 0, y = 0, X = 0, Y = 0;
   for (int i=0; i<s.length(); ++i)
      if (s[i] == 'R')
         ++X;
      else
      if (s[i] == 'L')
         --X;
      else
      if (s[i] == 'U')
         ++Y;
      else
         --Y;
   for (int i=0; i<s.length(); ++i)
   {
      if (X!=0 && Y!=0 && (n-x)%X==0 && (m-y)%Y==0 && (n-x)/X == (m-y)/Y && (n-x)/X >= 0 ||
         X==0 && Y!=0 && n-x==0 && (m-y)%Y==0 && (m-y)/Y >= 0 ||
         X!=0 && Y==0 && (n-x)%X==0 && m-y==0 && (n-x)/X >= 0||
         X==0 && Y==0 && n-x==0 && m-y==0)
      {
         cout << "Yes" << endl;
         return 0;
      }
      if (s[i] == 'R')
         ++x;
      else
      if (s[i] == 'L')
         --x;
      else
      if (s[i] == 'U')
         ++y;
      else
         --y;
   }
   cout << "No" << endl;
   return 0;
}