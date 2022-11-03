#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;

const int modulo = 1e9 + 7;

int binPow(int base, long long pow)
{
   if (pow == 0)
      return 1;
   if (pow%2 == 0)
   {
      int temp = binPow(base, pow/2);
      return (1LL*temp*temp)%modulo;
   }else
      return (1LL*base*binPow(base, pow-1))%modulo;
}

string s;
int k;
int ans = 0;

int main()
{
   cin >> s >> k;
   int sum = binPow(2, 1LL*s.length()*k)-1;
   if (sum < 0)
      sum += modulo;
   int det = binPow(2, s.length())-1;
   if (det < 0)
      det += modulo;
   sum = (1LL*sum*binPow(det, modulo-2))%modulo;
   for (int i=s.length()-1; i>=0; --i)
      if (s[i] == '0' || s[i] == '5')
         ans = (ans + (1LL*sum*binPow(2,i))%modulo)%modulo;
   cout << ans << endl;
   return 0;
}