#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=300005;
vector<int> depth(N,0);
vector<array<int,19>> p(N);
vector<bool> bad(N,0);

void add(int a,int u)
{
    depth[a]=depth[u]+1;
    p[a][0]=u;
    for(int i=1;i<19;i++) p[a][i]=p[p[a][i-1]][i-1];
}

int go(int a)
{
    for(int i=18;i>=0;i--) if(bad[p[a][i]]==0) a=p[a][i];
    return a;
}

int up(int a,int d)
{
    for(int i=18;i>=0;i--) if(depth[p[a][i]]>=d) a=p[a][i];
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    bad[0]=1;
    vector<ll> cnt(N,0);
    vector<ll> cost(N,0);
    int q;
    cin >> q >> cnt[1] >> cost[1];
    add(1,0);
    for(int o=2;o<=q+1;o++)
    {
        int tp;
        cin >> tp;
        if(tp==1)
        {
            int u;
            cin >> u >> cnt[o] >> cost[o];
            u++;
            add(o,u);
        }
        else
        {
            int a;
            ll w;
            cin >> a >> w;
            a++;
            ll c=0;
            ll price=0;
            for(int d=depth[go(a)]+bad[a];d<=depth[a];d++)
            {
                int b=up(a,d);
                ll t=min(w,cnt[b]);
                c+=t;
                price+=(t*cost[b]);
                w-=t;
                cnt[b]-=t;
                if(cnt[b]==0) bad[b]=1;
                if(w==0) break;
            }
            cout << c << " " << price << "\n";
            cout.flush();
        }
    }
    return 0;
}