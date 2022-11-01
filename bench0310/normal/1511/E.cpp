#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=998244353;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    int n,m;
    cin >> n >> m;
    vector<ll> pw(n*m+1,1);
    for(int i=1;i<=n*m;i++) pw[i]=mul(pw[i-1],2);
    int w=0;
    vector<string> s(n);
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        for(int j=0;j<m;j++) w+=(s[i][j]=='o');
    }
    auto solve=[&](int cnt)->ll
    {
        array<ll,3> now={1,0,0};
        ll res=0;
        for(int i=1;i<=cnt;i++)
        {
            array<ll,3> nxt={0,0,0};
            auto t=[&](int a,int b){nxt[b]=add(nxt[b],now[a]);};
            t(0,1);
            t(1,2);
            t(2,1);
            for(int k=0;k<=2;k++) t(k,0);
            now=nxt;
            res=add(res,mul(now[2],pw[w-i]));
        }
        return res;
    };
    ll res=0;
    for(int i=0;i<n;i++)
    {
        int l=0;
        while(l<m)
        {
            if(s[i][l]=='*')
            {
                l++;
                continue;
            }
            int r=l;
            while(r+1<m&&s[i][r+1]=='o') r++;
            res=add(res,solve(r-l+1));
            l=r+1;
        }
    }
    for(int j=0;j<m;j++)
    {
        int l=0;
        while(l<n)
        {
            if(s[l][j]=='*')
            {
                l++;
                continue;
            }
            int r=l;
            while(r+1<n&&s[r+1][j]=='o') r++;
            res=add(res,solve(r-l+1));
            l=r+1;
        }
    }
    cout << res << "\n";
    return 0;
}