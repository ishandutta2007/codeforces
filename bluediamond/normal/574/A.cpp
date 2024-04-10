#include <iostream>
#include <algorithm>
using namespace std;
int v[105];
int main()
{
    int n,i,j,sum=0,ma=0,poz;
    cin>>n;
    for(i=1;i<=n;i++)
        {
        cin>>v[i];
        if(v[i]>ma)
        {
            ma=v[i];
            poz=i;
        }
        }
    if(v[1]>ma)
    {
        cout<<0;
        return 0;
    }
    while(1)
    {
        ma=0;
        for(i=2;i<=n;i++)
            if(v[i]>ma)
            {
                ma=v[i];
                poz=i;
            }
        if(v[1]>ma)
        {
            cout<<sum;
            return 0;
        }
        sum++;
        v[poz]--;
        v[1]++;
    }
    return 0;
}