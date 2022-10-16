//  228

#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,i,j,k,l;
    cin>>n;
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=(2*n)-2*i-1; j++)
        {
            cout<<" ";
        }
        for(k=0; k<=i; k++)
        {
            if(i==0)
            {
                cout<<0<<endl;
            }
            else
                cout<<k<<" ";

        }
        for(l=i-1; l>0; l--)
        {
            cout<<l<<" ";
        }
        if(i>0)
        {
            cout<<0<<endl;
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=0; j<=2*i-1; j++)
        {
            cout<<" ";
        }
        for(k=0; k<=n-i; k++)
        {
            if(i==n)
                cout<<0<<endl;
            else
            cout<<k<<" ";

        }
        for(l=k-2; l>0; l--)
        {
            cout<<l<<" ";
        }
        if(i<n)
            cout<<0<<endl;
    }
    return 0;
}