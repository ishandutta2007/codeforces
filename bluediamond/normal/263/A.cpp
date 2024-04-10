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
    int r,c,x;
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
        {
            cin>>x;
            if(x==1)
            {
                r=i;
                c=j;
            }
        }
    cout<<abs(r-3)+abs(c-3);
    return 0;
}
/**
**/