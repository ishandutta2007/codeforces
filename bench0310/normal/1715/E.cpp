#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 i128;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,limk;
    cin >> n >> m >> limk;
    vector<array<int,2>> v[n+1];
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    const ll inf=(1ll<<60);
    vector<ll> d(n+1,inf);
    d[1]=0;
    auto chmin=[&](ll &a,ll b){a=min(a,b);};
    auto eval=[&](array<ll,2> f,ll x)->ll{return (f[0]*x+f[1]);};
    auto bad=[&](array<ll,2> a,array<ll,2> b,array<ll,2> c)->bool{return (i128(b[1]-a[1])*(b[0]-c[0])>=i128(c[1]-b[1])*(a[0]-b[0]));};
    vector<ll> res(n+1,0);
    for(int k=0;k<=limk;k++)
    {
        vector<ll> nd=d;
        if(k>0)
        {
            deque<array<ll,2>> q;
            for(int i=1;i<=n;i++)
            {
                while(q.size()>=2&&eval(q[0],i)>=eval(q[1],i)) q.pop_front();
                if(i>1) chmin(nd[i],eval(q[0],i)+ll(i)*i);
                array<ll,2> f={-2*i,d[i]+ll(i)*i};
                while(q.size()>=2&&bad(q[q.size()-2],q[q.size()-1],f)) q.pop_back();
                q.push_back(f);
            }
            q.clear();
            for(int i=n;i>=1;i--)
            {
                while(q.size()>=2&&eval(q[0],i)>=eval(q[1],i)) q.pop_front();
                if(i<n) chmin(nd[i],eval(q[0],i)+ll(i)*i);
                array<ll,2> f={-2*i,d[i]+ll(i)*i};
                while(q.size()>=2&&bad(f,q[q.size()-1],q[q.size()-2])) q.pop_back();
                q.push_back(f);
            }
        }
        priority_queue<array<ll,2>,vector<array<ll,2>>,greater<>> q;
        for(int i=1;i<=n;i++) q.push({nd[i],i});
        auto upd=[&](int a,ll td)
        {
            if(td<nd[a])
            {
                nd[a]=td;
                q.push({nd[a],a});
            }
        };
        while(!q.empty())
        {
            auto [td,a]=q.top();
            q.pop();
            if(nd[a]<td) continue;
            for(auto [to,c]:v[a]) upd(to,nd[a]+c);
        }
        d=nd;
    }
    for(int i=1;i<=n;i++) cout << d[i] << " \n"[i==n];
    return 0;
}