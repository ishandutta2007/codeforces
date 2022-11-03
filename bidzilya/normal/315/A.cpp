#include <iostream>
#include <vector>
using namespace std;

vector<int> a,b;
int n;

int main()
{
   cin >> n;
   a.resize(n);
   b.resize(n);
   for (int i=0; i<n; ++i)
      cin >> a[i] >> b[i];
   int c = 0;
   for (int i=0; i<n; ++i)
   {
      bool may = true;
      for (int j=0; j<n; ++j)
         if (j!=i && b[j] == a[i])
            may = false;
      c += may;
   }
   cout << c << endl;
            
   return 0;
}