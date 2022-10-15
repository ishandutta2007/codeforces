#include <bits/stdc++.h>
using namespace std;
const int nmax=3000;
int n,m,v1[nmax+5],v2[nmax+5];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v1[i];
    for(int i=1;i<=m;i++)
        cin>>v2[i];
    sort(v1+1,v1+n+1);
    sort(v2+1,v2+m+1);
    int poz=1;
    for(int i=1;i<=m;i++)
    {
        if(v2[i]>=v1[poz])
        {
            poz++;
            if(poz==n+1)
            {
                cout<<0;
                return 0;
            }
        }
    }
    cout<<n+1-poz;
    return 0;
}
/**

**/