#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long int n,i,j;
    cin>>n;
    long int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n-1;i++)
    {
        for(j=i+2;j<n-1;j++)
        {
            if(((min(a[i],a[i+1])>min(a[j],a[j+1]) && max(a[i],a[i+1])>max(a[j],a[j+1])) || (min(a[i],a[i+1])<min(a[j],a[j+1]) && max(a[i],a[i+1])<max(a[j],a[j+1]))) && max(a[i],a[i+1])>min(a[j],a[j+1]) && max(a[j],a[j+1])>min(a[i],a[i+1]))
            {
                cout<<"yes";return 0;
            }
            
        }
    }
    cout<<"no";
    return 0;
}