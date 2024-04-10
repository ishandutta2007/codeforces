#include <bits/stdc++.h>

using namespace std;

int n,k;

int v[105][105];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=2;i<=3;i++)
    {
        for(int j=2;j<n+1-j && k>=2;j++)
        {
            v[i][j]=v[i][n+1-j]=1;
            k-=2;
        }
    }
    if(k==2)
    {
        v[2][(n+1)/2]=1;
        v[3][(n+1)/2]=1;
        k-=2;
    }
    if(k==1)
    {
        v[2][(n+1)/2]=1;
        k--;
    }
    if(k)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(v[i][j])
            {
                cout<<"#";
            }
            else
            {
                cout<<".";
            }
        }
        cout<<"\n";
    }
    return 0;
}