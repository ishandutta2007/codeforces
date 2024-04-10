#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define Matrix vector< vector<ll> >

Matrix operator * (Matrix a,Matrix b)
{
    Matrix ans;
    ll r1=a.size(),c1=a[0].size();
    ll r2=b.size(),c2=b[0].size();
    if(c1!=r2)
    {
        return ans;
    }
    for(ll i=0;i<r1;i++)
    {
        ans.push_back({});
        for(ll j=0;j<c2;j++)
        {
            ans[i].push_back(0);
            for(ll k=0;k<c1;k++)
            {
                long long F=a[i][k];
                long long S=b[k][j];
                long long sum=(F*S+ans[i][j])%1000000007;
                ans[i][j]=sum;
            }
        }
    }
    return ans;
}

Matrix Power(Matrix a,ll b)
{
    Matrix ans;
    ll r=a.size(),c=a[0].size();
    if(r!=c)
    {
        return ans;
    }
    for(ll i=0;i<r;i++)
    {
        ans.push_back({});
        for(ll j=0;j<c;j++)
        {
            ans[i].push_back((i==j));
        }
    }
    while(b)
    {

        if(b%2)
        {
            ans=ans*a;
        }
        a=a*a;
        b/=2;
    }
    return ans;
}

ll n;
ll k;
ll a[105];

Matrix G;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    G.resize(n);
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            ll x=(a[i]^a[j]);
            ll cnt=0;
            while(x)
            {
                if(x%2==1)
                {
                    cnt++;
                }
                x/=2;
            }
            if(cnt%3==0)
            {
                G[i].push_back(1);
            }
            else
            {
                G[i].push_back(0);
            }
        }
    }
    Matrix v(n);
    for(ll i=0;i<n;i++)
    {
        v[i].push_back(1);
    }
    Matrix ans=Power(G,k-1);
    Matrix lol=ans*v;
    ll sl=0LL;
    for(ll i=0;i<n;i++)
    {
        sl+=lol[i][0];
        sl%=1000000007;
    }
    cout<<sl<<"\n";
    return 0;
}
/**



**/