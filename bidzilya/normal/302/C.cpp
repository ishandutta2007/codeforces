#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

int n;

bool a[200];

void dfs(int v)
{
   a[v] = 1;
   for (int i=0; i<=n; ++i)
      if (i <= v && n-i <= 2*n-1-v && !a[v-i+n-i])
         dfs(v-i+n-i);
}

int main()
{
   cin >> n;
   int mn = 1e9, sum = 0;
   int pos = 0, nl = 0;
   for (int i=0; i<2*n-1; ++i)
   {
      int a;
      cin >> a;
      sum += abs(a);
      mn = min(mn, abs(a));
      if (a > 0)
         ++pos;
      else
      if (a == 0)
         ++nl;
   }
   if (nl > 0)
      cout << sum << endl;
   else
   {
      dfs(pos);
      if (a[n-1])
         cout << sum << endl;
      else
         cout << sum-2*mn << endl;
   }
   return 0;
}