#include <bits/stdc++.h>
using namespace std;
const int nmax=200;
int t;
int n , v[nmax+5] , aux[nmax+5];
int k , a;
bool ok()
{
    for(int i=1;i<=n;i++)
        if(v[i]==0)
            return 0;
    return 1;
}
int main()
{
    cin>>t;
    for(int l=1;l<=t;l++)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            v[i]=aux[i]=0;
        for(int i=1;i<=k;i++)
        {
            cin>>a;
            v[a]=1;
        }
        int ans=1;
        while(!ok())
        {
            ans++;
            for(int i=1;i<=n;i++)
                aux[i]=v[i];
            for(int i=1;i<=n;i++)
                if(v[i]==1)
                    aux[i-1]=aux[i+1]=1;
            for(int i=1;i<=n;i++)
                v[i]=aux[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/**


**/