#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    long long int n,i,j;
    cin>>n;
    long long int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
 
    long long int ans=0;
    for(i=25;i>=0;i--)
    {
        for(j=0;j<n;j++)
            a[j]&=(1<<(i+1))-1;
        sort(a,a+n);
        for(j=0;j<n-1;j++)
        {
            if((upper_bound(a+j+1,a+n,(1<<i+1)-1-a[j])-lower_bound(a+j+1,a+n,(1<<i)-a[j]))&1)
                ans^=(1<<(i));
            if((upper_bound(a+j+1,a+n,(1<<i+2)-2-a[j])-lower_bound(a+j+1,a+n,(1<<i+1)+(1<<i)-a[j]))&1)
                ans^=(1<<i);
        }
    }
    cout<<ans<<endl;
 
 
 
 
 
}