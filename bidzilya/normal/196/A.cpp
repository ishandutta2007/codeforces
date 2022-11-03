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
    string s;
    cin >> s;
    int p[111111];
    int n = s.length();
    p[n-1]=n-1;
    for (int i=n-2;i>=0;i--)
        if (s[p[i+1]]>s[i])
           p[i]=p[i+1];
        else
            p[i]=i;
    int i=0;
    while (i<n)
    {
          cout << s[p[i]];
          i = p[i]+1;
    }
        
    return 0;
}