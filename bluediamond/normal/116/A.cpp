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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,ma=0,a,b,s=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        s=max(0,s-a);
        s+=b;
        ma=max(ma,s);
    }
    cout<<ma;
    return 0;
}
/**
**/