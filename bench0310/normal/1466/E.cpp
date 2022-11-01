#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    const ll mod=1000000007;
    vector<ll> p(120,1);
    for(int i=1;i<120;i++) p[i]=(p[i-1]*2)%mod;
    ll two[60][60][2];
    while(t--)
    {
        ll n;
        cin >> n;
        for(int i=0;i<60;i++) for(int j=0;j<60;j++) two[i][j][0]=two[i][j][1]=0;
        for(int i=0;i<n;i++)
        {
            ll x;
            cin >> x;
            for(int j=0;j<60;j++)
            {
                for(int k=0;k<60;k++)
                {
                    if(((x>>j)&1)&&(((x>>k)&1)==0)) two[j][k][0]++;
                    if(((x>>j)&1)&&((x>>k)&1)) two[j][k][1]++;
                }
            }
        }
        ll res=0;
        for(int i=0;i<120;i++)
        {
            for(int a=0;a<=i;a++)
            {
                int b=i-a;
                if(max(a,b)>=60) continue;
                ll c=(two[a][a][1]*(two[a][b][1]*n+two[a][b][0]*two[b][b][1]))%mod;
                res=(res+c*p[i])%mod;
            }
        }
        cout << res << "\n";
    }
    return 0;
}