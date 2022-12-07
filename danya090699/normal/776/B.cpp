#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    n+=2;
    bool ar[n];
    for(int a=2; a<n; a++) ar[a]=0;
    for(int a=2; a<n; a++)
    {
        if(ar[a]==0)
        {
            if(a*1ll*a<n)
            {
                for(int b=a*a; b<n; b+=a) ar[b]=1;
            }
        }
    }
    if(n>4) cout<<2;
    else cout<<1;
    cout<<"\n";
    for(int a=2; a<n; a++)
    {
        if(ar[a]) cout<<2<<" ";
        else cout<<1<<" ";
    }
}