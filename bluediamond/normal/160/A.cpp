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
int v[105],n,s,o;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        s+=v[i];
    }
    sort(v+1,v+n+1);
    for(int i=n;i>=1;i--)
    {
        o+=v[i];
        if(o>s-o)
        {
            cout<<n-i+1;
            return 0;
        }
    }
    return 0;
}
/**
**/