#include<bits/stdc++.h>
using namespace std;
#define li long long int

int main()
{
    ios_base::sync_with_stdio(0);
    li n,m,i,j,sum=0;
    cin>>n>>m;
    li a[n],b[m];
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        if(i<m)
        b[i%m]=a[i];
        if(i>m-1)
        {
            sum+=b[i%m];b[i%m]+=a[i];
        }
        cout<<sum<<" ";
    }
    
    return 0;
}