#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;

const int MAX_INT = (1 << 31) - 1;

//****************************************************** 

int n;
int sum, curAns, ans;

int main()
{
   cin >> n;
   ans = -MAX_INT;
   sum = curAns = 0;
   for (int i=0; i<n; ++i)
   {
      int x;
      cin >> x;
      if (x == 1)
         --curAns;
      else
         ++curAns;
      ans = max(ans, curAns);
      curAns = max(0, curAns);  
      sum += x;
   }
   cout << ans + sum << endl;
   return 0;
}