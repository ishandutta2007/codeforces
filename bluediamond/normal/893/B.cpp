#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cctype>
using namespace std;
#define ll long long
int p[20],n,sl;
bool efrum(int x)
{
    for(int i=1;i<=10;i++)
        if((p[i]-1)*(p[i-1])==x)
            return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    p[0]=1;
    for(int i=1;i<=17;i++)
        p[i]=p[i-1]*2;
    cin>>n;
    for(int i=1;i<=n;i++)
        if(n%i==0)
        {
            if(efrum(i))
                sl=i;
        }
    cout<<sl;
    return 0;
}
/**
**/