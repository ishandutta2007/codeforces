#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=2005;
int n;
string s;
vector<ll> one(N,0);
vector<ll> two(N,0);
ll mod;
ll p;

void ini()
{
    for(int i=1;i<=n;i++) one[i]=(one[i-1]*p+(s[i]-'a'))%mod;
    for(int i=n;i>=1;i--) two[i]=(two[i+1]*p+(s[i]-'a'))%mod;
}

ll fpow(ll b,ll e)
{
    ll res=1;
    while(e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

ll qone(int l,int r)
{
    ll res=one[r];
    res=(res-one[l-1]*fpow(p,r-l+1))%mod;
    res=(res+mod)%mod;
    return res;
}

ll qtwo(int l,int r)
{
    ll res=two[l];
    res=(res-two[r+1]*fpow(p,r-l+1))%mod;
    res=(res+mod)%mod;
    return res;
}

bool pal(int l,int r)
{
    return (qone(l,r)==qtwo(l,r));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    cin >> s;
    n=s.size();
    s='?'+s;
    mod=1000000007;
    p=31;
    ini();
    ll res=0;
    vector<ll> dp(n+2,0);
    for(int i=n;i>=1;i--)
    {
        dp[i]=dp[i+1];
        for(int j=i;j<=n;j++)
        {
            if(pal(i,j))
            {
                res+=dp[j+1];
                dp[i]++;
            }
        }
    }
    cout << res << "\n";
    return 0;
}