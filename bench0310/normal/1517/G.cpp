#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=2005;
const ll inf=(1ll<<60);
vector<array<int,2>> v[N];
vector<int> from;
vector<ll> cap;
vector<int> p(N,-1);

void add_one(int a,int b,ll c)
{
    int e=from.size();
    v[a].push_back({b,e});
    from.push_back(a);
    cap.push_back(c);
}

void add(int a,int b,ll c)
{
    add_one(a,b,c);
    add_one(b,a,0);
}

ll go(int s,int t)
{
    p.assign(t+1,-1);
    queue<array<ll,2>> q;
    q.push({s,inf});
    p[s]=-2;
    while(!q.empty())
    {
        auto [a,f]=q.front();
        q.pop();
        for(auto [to,e]:v[a])
        {
            if(cap[e]>0&&p[to]==-1)
            {
                p[to]=e;
                ll nf=min(f,cap[e]);
                if(to==t) return nf;
                q.push({to,nf});
            }
        }
    }
    return 0;
}

ll max_flow(int s,int t)
{
    ll flow=0;
    ll f=0;
    while((f=go(s,t)))
    {
        flow+=f;
        int a=t;
        while(a!=s)
        {
            cap[p[a]]-=f;
            cap[p[a]^1]+=f;
            a=from[p[a]];
        }
    }
    return flow;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int s=0,t=2*n+1;
    vector<array<int,2>> tents(n+1,{0,0});
    vector<int> w(n+1,0);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        cin >> tents[i][0] >> tents[i][1] >> w[i];
        sum+=w[i];
    }
    auto id=[&](int i)->int
    {
        auto [x,y]=tents[i];
        if((y%2)==0) return (1-(x&1));
        else return (2+(x&1));
    };
    auto in=[&](int i)->int{return (2*i-1);};
    auto out=[&](int i)->int{return (2*i);};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            auto [xa,ya]=tents[i];
            auto [xb,yb]=tents[j];
            if(id(i)+1==id(j)&&abs(xa-xb)+abs(ya-yb)==1) add(out(i),in(j),inf);
        }
    }
    for(int i=1;i<=n;i++)
    {
        add(in(i),out(i),w[i]);
        if(id(i)==0) add(s,in(i),inf);
        if(id(i)==3) add(out(i),t,inf);
    }
    cout << sum-max_flow(s,t) << "\n";
    return 0;
}