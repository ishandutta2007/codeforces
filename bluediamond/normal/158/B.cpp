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
int n,ap[10],x,s=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        ap[x]++;
    }
    s+=ap[4];
    x=min(ap[1],ap[3]);
    s+=x;
    ap[1]-=x;
    ap[3]-=x;
    s+=ap[3];
    s+=ap[2]/2;
    ap[2]=ap[2]%2;
    if(ap[2])
    {
        if(ap[1]==0)
        {
            s++;
        }
        if(ap[1]==1)
        {
            s++;
            ap[1]--;
        }
        if(ap[1]>=2)
        {
            s++;
            ap[1]-=2;
        }
    }
    cout<<s+ap[1]/4+(ap[1]%4!=0);
    return 0;
}
/**
1:2
2:2
**/