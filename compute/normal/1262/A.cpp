#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mi=1e9+7,mx=0;
        for(int i=0,l,r;i<n;i++)
        {
            cin>>l>>r;
            mi=min(r,mi);
            mx=max(mx,l);
        }
        if(mx<mi) mx=mi;
        cout<<mx-mi<<'\n';
    }
}