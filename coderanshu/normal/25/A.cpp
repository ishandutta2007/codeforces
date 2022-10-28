#include<bits/stdc++.h>
using namespace std;
int main()
{
 
    int n,i,z;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    z=a[0]%2;
    for(i=1;i<n-1;i++)
    {
        if(a[i]%2!=z)
        {
            break;
        }
    }
    if
        (i>1)cout<<i+1;
    else
        (a[2]%2==z)?cout<<2:cout<<1;
    return 0; 
}