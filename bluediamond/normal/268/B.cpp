#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n;
ll ans=0LL;
ll add=0LL;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(ll lft=n;lft>=1;lft--)
    {
        add++;
        ans+=add*(lft-1);
    }
    ans+=n;
    cout<<ans<<"\n";
    return 0;
}
/**


**/