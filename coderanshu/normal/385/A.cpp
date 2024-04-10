#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,c,m=0,i;
    cin>>n>>c;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(i>0)
        {
            m=max(m,a[i-1]-a[i]);
        }
    }
    if(m-c<0) cout<<0;
    else cout<<m-c;
    return 0; 
}
// maximizing the adjacent differences