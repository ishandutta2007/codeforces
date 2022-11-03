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
const int N = 1e5 + 9;

int n;
int a[N], qa[N], qb[N], c = 0;

int main()
{
//   ifstream cin("input.txt");
   cin >> n;
   for (int i=0; i<n; ++i)
      cin >> a[i];
   int ans = 0;
   for (int i=0; i<n; ++i)
   {
      int temp = 0;
      while (c > 0 && qa[c-1] < a[i])
      {
         temp = max(temp, qb[c-1] + 1);
         --c;
      }
      if (c > 0)
      {
         qb[c-1] = max(temp, qb[c-1] + 1);
         ans = max(ans, qb[c-1]);
      }
      qa[c] = a[i];
      qb[c] = 0;
      ++c;
   }
   cout << ans << endl;
   return 0;
}