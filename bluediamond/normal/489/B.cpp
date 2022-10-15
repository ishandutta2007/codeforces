#include <bits/stdc++.h>

using namespace std;

int b[105],f[105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        b[x]++;
    }
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        f[x]++;
    }
    int ans=0;
    for(int p=1;p<=100;p++)
    {
        int t=min(b[p],f[p-1]+f[p]+f[p+1]);
        ans+=t;
        b[p]-=t;
        for(int j=p-1;j<=p+1;j++)
        {
            if(t>=f[j])
            {
                t-=f[j];
                f[j]=0;
            }
            else
            {
                /// t<f[j]
                f[j]-=t;
                break;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}