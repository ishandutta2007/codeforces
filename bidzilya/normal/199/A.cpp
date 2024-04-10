#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <map>
using namespace std;

typedef long long lli;

int main()
{
    int n;
    cin >> n;
    if (n==0)
       cout << "0 0 0";
    else
    if (n==1)
       cout << "0 0 1";
    else
    {
    int f[10000];
    f[0]=0;f[1]=0;f[2]=1;
    for (int i=3;i<1000;i++)
        f[i]=f[i-1]+f[i-2];
    for (int i=46;i>=0;i--)
        if (f[i]==n)
        {
                    cout << f[i-3] << " " << f[i-2] << " " << f[i-2];
                    break;
        }
    }
    return 0;
}