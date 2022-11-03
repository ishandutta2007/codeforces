#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;

string s1, s2;
int p1, p2, l1, l2;
int p = 0;

bool condition(int p)
{
   if (l1 * p1 < 1LL * l2 * p2 * p)
      return false;
   int aFull[100], aPos[100], aUs[100];
   for (int i=0; i<l2; ++i)
      aUs[i] = 0;
   int pos = 0;
   int full2 = 0;
   int full1 = 0;
   bool findCyrcle = false;
   while (full1 < p1 && full2 < p2 * p)
   {
      ++full1;
      int _pos = pos;
      for (int i=0; i<l1; ++i)
         if (s1[i] == s2[pos])
         {
            ++pos;
            if (pos == l2)
            {
               pos = 0;
               ++full2;
            }
         }
      if (full2 >= p2*p) break;
      if (!findCyrcle)
      {
      if (!aUs[pos])
      {
         aUs[pos] = 1;
         aPos[pos] = _pos;
         aFull[pos] = full2;
      }else
      {
         int _full1 = 1;
         int _full2 = full2;
         while (_pos != pos)
         {
            ++_full1;
            _pos = aPos[_pos];
         }
         _full2 -= aFull[_pos];
         if (_full2 == 0)
            return false;

         int ost = (p2 * p - full2 - 1)/_full2;
         full1 += _full1*ost;
         full2 += _full2*ost;
         findCyrcle = true;
      }
      }
   }
   if (full2 >= p2 * p && full1 <= p1)
      return true;
   else
      return false;
}

int main()
{
   cin >> p1 >> p2 >> s1 >> s2;
   l1 = s1.length();
   l2 = s2.length();
   int l = 1, r = 1e9;
   while (l <= r)
   {
      int m = (l+r) >> 1;
      if (condition(m))
      {
         p = m;
         l = m+1;
      }else
         r = m-1;
   }
   cout << p << endl;
   return 0;
}