#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=1000000007;

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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) cin >> p[i];
        vector<int> v;
        vector<bool> vis(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            int c=0;
            int now=i;
            while(vis[now]==0)
            {
                vis[now]=1;
                c++;
                now=p[now];
            }
            v.push_back(c);
        }
        ll val=0;
        if((n%3)==0) val=fpow(3,n/3);
        else if((n%3)==1) val=(fpow(3,(n-4)/3)*4)%mod;
        else val=(fpow(3,(n-2)/3)*2)%mod;
        bool four=0;
        array<int,3> cnt={0,0,0};
        int mv=0;
        for(int a:v)
        {
            mv+=(a-1)/3;
            if((a%3)==1&&a>=4) four=1;
            cnt[a%3]++;
        }
        int res=(1ll<<30);
        auto solve=[&](int d=0,array<int,2> r1={-1,-1},array<int,2> r2={-1,-1})
        {
            int now=mv+d;
            array<int,3> c=cnt;
            for(auto [a,b]:{r1,r2})
            {
                if(a==-1) continue;
                if(c[a]<b) return;
                c[a]-=b;
            }
            while(c[1]>0&&c[2]>0)
            {
                now++;
                c[1]--;
                c[2]--;
            }
            while(c[1]>=3)
            {
                now+=2;
                c[1]-=3;
            }
            while(c[2]>=3)
            {
                now+=3;
                c[2]-=3;
            }
            res=min(res,now);
        };
        if((n%3)==0) solve();
        else if((n%3)==1)
        {
            if(four) solve(-1,{1,1});
            solve(1,{0,1},{1,1});
            solve(0,{2,2});
            solve(1,{1,2},{2,1});
            solve(2,{1,4});
        }
        else
        {
            solve(1,{1,2});
            solve(0,{2,1});
        }
        cout << val << " " << res << "\n";
    }
    return 0;
}