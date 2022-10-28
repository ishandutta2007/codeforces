#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,k;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    if(a[k]==a[i]+a[j])
                    {
                        cout<<k+1<<" "<<i+1<<" "<<j+1;
                        return 0;
                    }
                }
            }
    }
    cout<<-1;
    return 0;
}