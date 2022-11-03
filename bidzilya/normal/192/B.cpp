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
    int n;
    cin>>n;
    int a[1000];
    int m = 0;
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
        m = max(m,a[i]);
    }
    for (int i=1;i<=m;i++)
    {
        for (int j=0;j<n;j++)
            a[j]--;
        bool f[1000];
        f[0]=(a[0]>0);
        for (int i=1;i<n;i++)
            f[i]=(a[i]>0 && (f[i-1]||(i>1 && f[i-2])));
        if (!f[n-1])
        {
                    cout << i;
                    break;
        }
    }
    return 0;
}