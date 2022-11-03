#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

vector<int> m;
string s;

int main()
{
   getline(cin, s);
   m.resize(s.length());
   for (int i=s.length()-1; i>=0; --i)
   {
      if (i < s.length()-1) m[i] = m[i+1]; else m[i] = 0;
      if (i - 4 >= 0 &&
         s[i] == 'l' && s[i-1] == 'a' &&
         s[i-2] == 't' && s[i-3] == 'e' && 
         s[i-4] == 'm')
            ++m[i];
   }
   ll ans = 0;
   for (int i=0; i < s.length(); ++i)
      if (i + 4 < s.length() && 
         s[i] == 'h' && s[i+1] == 'e' && 
         s[i+2] == 'a' && s[i+3] == 'v' && 
         s[i+4] == 'y')
            ans += m[i];
   cout << ans << endl;
   return 0;
}