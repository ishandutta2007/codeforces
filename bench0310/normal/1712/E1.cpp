#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=200000;
    vector<int> d[N+1];
    for(int i=1;i<=N;i++) for(int j=i;j<=N;j+=i) d[j].push_back(i);
    vector<array<int,2>> e[N+1];
    for(int i=1;i<=N;i++)
    {
        int c=d[i].size();
        //2d
        for(int j=0;j<c-1;j++) e[d[i][j]].push_back({i,c-2-j});
        //2u
        for(int j=0;j<c;j++)
        {
            if(d[i][j]==1||(d[i][j]%2)==0) continue;
            for(int k=j+1;k<c;k++)
            {
                if(d[i][k]==1||(d[i][k]%2)==0) continue;
                int a=2*i/d[i][j];
                int b=2*i/d[i][k];
                if(2*i<a+b+i) e[b].push_back({i,1});
            }
        }
        //1d+1u
        for(int a:d[i])
        {
            if(a==i) continue;
            for(int j=0;j<c;j++)
            {
                if(d[i][j]==1||(d[i][j]%2)==0) continue;
                int b=2*i/d[i][j];
                if(2*i<a+b+i) e[min(a,b)].push_back({i,1});
            }
        }
    }
    int q;
    cin >> q;
    vector<array<int,2>> queries[N+1];
    vector<ll> res(q+1,0);
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin >> l >> r;
        queries[l].push_back({r,i});
        res[i]=ll(r-l+1)*(r-l)*(r-l-1)/6;
    }
    vector<int> f(N+1,0);
    auto upd=[&](int x,int c)
    {
        for(;x<=N;x=(x|(x+1))) f[x]+=c;
    };
    auto sum=[&](int x)->int
    {
        int s=0;
        for(;x>=0;x=(x&(x+1))-1) s+=f[x];
        return s;
    };
    for(int i=N;i>=1;i--)
    {
        for(auto [r,c]:e[i]) upd(r,c);
        for(auto [r,id]:queries[i]) res[id]-=sum(r);
    }
    for(int i=1;i<=q;i++) cout << res[i] << "\n";
    return 0;
}