#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;



int main()
{
   string s;
   getline(cin, s);
   int i = s.length()-1;
   while (i >= 0)
   {
      if (s[i] == '1') 
         --i;
      else
      if (i > 0 && s[i]=='4' && s[i-1]=='1')
         i -= 2;
      else
      if (i > 1 && s[i]=='4' && s[i-1]=='4' && s[i-2]=='1')
         i -= 3;
      else
      {
         cout << "NO" << endl;
         return 0;
      }
   }
   cout << "YES" << endl;
   return 0;
}