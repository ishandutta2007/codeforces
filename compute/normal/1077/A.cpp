#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long  a,b,k;
        cin>>a>>b>>k;
        long long ans=0;
        ans-=b*(k/2);
        ans+=a*(k-k/2);
        cout<<ans<<endl;
    }
}