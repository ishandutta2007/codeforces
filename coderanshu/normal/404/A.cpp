#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n,i,j;
    cin>>n;
    char a[n+2][n+2];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cin>>a[i][j];
    }
    for(i=0;i<n;i++)
    
    {
        for(j=0;j<n;j++)
        {
            if((i==j || i+j==n-1) && a[i][j]!=a[0][0])
            {
                cout<<"NO";return 0;
            }
            else if((i!=j && i+j!=n-1 ) && (a[i][j]==a[0][0] || a[i][j]!=a[0][1]))
            {
                cout<<"NO";return 0;
            }
        }
    }
    cout<<"YES";
    return 0; 
}