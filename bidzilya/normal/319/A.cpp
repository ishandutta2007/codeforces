#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

const int mod = 1e9+7;

int main()
{
   string s;
   cin >> s;
   int ans = 0;
   int cur = 1;
   for (int i=1; i<s.length(); ++i)
      cur = (2*cur)%mod;
   for (int i=s.length()-1; i>=0; --i)
   {
      if (s[i] == '1')
         ans = (ans+cur)%mod;
      cur = (2*cur)%mod;
   }
   cout << ans << endl;
   return 0;
}