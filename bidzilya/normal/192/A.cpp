#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <map>
#include <fstream>
#include <cstdio>
using namespace std;

typedef long long lli;

bool Binary(lli a[], int l, int r, lli x)
{
     while (l<=r)
     {
           int m = (l+r)/2;
           if (a[m]==x)
              return true;
           else
           if (a[m]>x)
              r = m-1;
           else
               l = m+1;
     }
     return false;
}

int main()
{
    lli a[50000];
    for (int i=0;i<50000;i++)
        a[i] = 1LL*i*(i+1)/2;
    lli n;
    cin >> n; 
    for (int i=1;a[i]<=n;i++)
    {
        lli b = n - a[i];
        if (Binary(a,1,49999,b))
        {
                                cout << "YES";
                                return 0;
        }
    }
    cout << "NO";
    return 0;
}