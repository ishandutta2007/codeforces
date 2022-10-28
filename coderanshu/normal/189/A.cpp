#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c,m,M,i,j,k;
    cin>>n>>a>>b>>c;
    int ans=0;
    for(i=0;i*a<=n;i++)
    {
        for(j=0;j*b<=n;j++)
        {
            if((n-i*a-j*b)%c==0 && n>=i*a+j*b)
            {
            ans=max(ans,i+j+(n-i*a-j*b)/c);
            }
        }
    }
    cout<<ans;
    return 0;
}