#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100+5;

int n;
ll x,y;
ll v[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    if(x>y)
    {
        cout<<n<<"\n";
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        v[i]-=x;
        if(v[i]<=0)
        {
            ans++;
        }
    }
    cout<<(ans+1)/2<<"\n";
    return 0;
}
/**




**/