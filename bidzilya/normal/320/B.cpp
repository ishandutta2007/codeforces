#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

int n;

vector<int> a,b,c;

bool isPath(int vs, int vf)
{
   return (a[vs] > a[vf] && a[vs] < b[vf] ||
      b[vs] > a[vf] && b[vs] < b[vf]);
}

void dfs(int vs, int vf)
{
   c[vs] = true;
   for (int i=0; i<a.size(); ++i)
      if (!c[i] && isPath(vs, i))
         dfs(i, vf);
}

int main()
{
   cin >> n;
   for (int i=0; i<n; ++i)
   {
      int t;
      cin >> t;
      if (t == 1)
      {
         int xa, xb;
         cin >> xa >> xb;
         a.push_back(xa);
         b.push_back(xb);
      }else
      {
         int v1, v2;
         cin >> v1 >> v2;
         v1--; v2--;
         c.assign(a.size(), 0);
         dfs(v1, v2);
         if (c[v2])
            cout << "YES" << endl;
         else
            cout << "NO" << endl;
      }
   }
   return 0;
}