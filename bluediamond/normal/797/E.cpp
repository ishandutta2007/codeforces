#include <bits/stdc++.h>

using namespace std;

const int N=100000+5;
const int K=333;

int n,v[N];
int q,p,k;

int calc(int i)
{
    if(i>n)
    {
        return 0;
    }
    else
    {
        return 1+calc(i+v[i]+k);
    }
}

int res[N][K];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(k=1;k<=min(310,n);k++)
    {
        for(int i=n;i>=1;i--)
        {
            int j=i+k+v[i];
            if(j>n)
            {
                res[i][k]=1;
            }
            else
            {
                res[i][k]=1+res[j][k];
            }
        }
    }
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>p>>k;
        if(k<=310)
        {
            cout<<res[p][k]<<"\n";
        }
        else
        {
            cout<<calc(p)<<"\n";
        }
    }
    return 0;
}
/**



100

33300000
100000000
**/