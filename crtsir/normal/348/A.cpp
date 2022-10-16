#include<bits/stdc++.h>
using namespace std;
long long a[200006],n,r,l;
bool check(int x)
{
    long long ret=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>x)return false;
        ret+=(x-a[i]);
    }
    return (ret>=x);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    r=2147483647;
    while(l<r-1)
    {
        long long mid=(r+l)/2;
        if(check(mid))
            r=mid;
        else
            l=mid;
    }
    cout<<r;
}
/*                    |
                     /o\
                     |o|
                     |o|
                     |o|
                     |o|
                    /   \
                    |TNT|
                    |___|
*/