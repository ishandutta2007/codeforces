//  228

#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,a[5000],sum=0;
    bool vis[5000];
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]<1||a[i]>n)
        {
            sum+=1;
        }
        else
        {
            if(vis[a[i]]==1)
            {
                sum+=1;
            }
            else
            {
                vis[a[i]]=1;
            }
        }

    }
    cout<<sum;
}