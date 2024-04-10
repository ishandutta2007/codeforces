#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> c(n+1,0);
    for(int i=1;i<=n;i++) cin >> c[i];
    ll res=0;
    for(int i=1;i<=n;i+=2)
    {
        ll sum=0;
        ll mn=0;
        for(int j=i+1;j<=n;j++)
        {
            if((j%2)==0)
            {
                if(mn+c[i]>=0)
                {
                    ll x=max(ll(1),sum-mn);
                    ll y=sum+c[i];
                    res+=max(ll(0),min(y,c[j])-x+1);
                }
            }
            if(j&1) sum+=c[j];
            else sum-=c[j];
            mn=min(mn,sum);
        }
    }
    cout << res << "\n";
    return 0;
}