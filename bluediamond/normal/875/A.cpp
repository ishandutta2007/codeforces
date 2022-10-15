#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <iomanip>
#include <math.h>
#include <algorithm>
using namespace std;
vector<int>v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,x,y=0,sl=0;
    cin>>n;
    x=n;
    while(n>0)
    {
        y++;
        n/=10;
    }
    for(int i=x-9*y;i<=x;i++)
    {
        if(i<=0)
            continue;
        int s=0,cx=i;
        while(cx>0)
        {
            s+=cx%10;
            cx/=10;
        }
        if(i+s==x)
        {
            sl++;
            v.push_back(i);
        }
    }
    cout<<sl<<"\n";
    for(int i=0;i<sl;i++)
        cout<<v[i]<<" ";
    return 0;
}