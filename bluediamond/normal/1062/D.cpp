#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll ans=0LL;
    for(int i=2;i<=n;i++)
    {
        for(int j=2*i;j<=n;j+=i)
        {
            ans+=j/i;
        }
    }
    ans*=4;
    cout<<ans<<"\n";
    return 0;
}