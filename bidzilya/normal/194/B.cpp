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

int main()
{
    int t;
    cin >> t;
    while (t>0)
    {
          int n;
          cin >> n;
          if (n%2==0)
                    cout << 4LL*n+1 << endl;
          else
          if (n%4==1)
                     cout << 2LL*n+1 << endl;
          else
              cout << n+1 << endl;
          t--;
    }
    return 0;
}