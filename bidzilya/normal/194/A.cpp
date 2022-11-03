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
    int n,k;
    scanf("%d%d",&n,&k);
    int ans = -1;
    for (int c2=0;2*c2<=k && c2<=n;c2++)
        for (int c3=0;3*c3<=k && c3+c2<=n;c3++)
            for (int c4=0;4*c4<=k && c3+c2+c4<=n;c4++)
            {
                int c5=n-c2-c3-c4;
                if (c2*2+c3*3+c4*4+c5*5==k &&
                   (ans==-1 || c2<ans))
                                 ans = c2;
            }
    cout <<ans;
    return 0;
}