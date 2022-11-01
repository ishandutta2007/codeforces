#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=16000;
const int inf=(1<<30);
vector<int> u;
vector<int> c;
vector<array<int,2>> v[N];
vector<int> eone;
vector<int> d;
vector<int> p;

void add_one(int a,int b,int cap,int cost)
{
    int id=u.size();
    u.push_back(cap);
    c.push_back(cost);
    v[a].push_back({b,id});
    eone.push_back(a);
}

void add(int a,int b,int cap,int cost)
{
    add_one(a,b,cap,cost);
    add_one(b,a,0,-cost);
}

bool go(int s,int t)
{
    d.assign(N,inf);
    p.assign(N,-1);
    d[s]=0;
    priority_queue<array<int,2>,vector<array<int,2>>,greater<>> q;
    q.push({0,s});
    while(!q.empty())
    {
        auto [da,a]=q.top();
        q.pop();
        if(d[a]<da) continue;
        for(auto [to,e]:v[a])
        {
            if(u[e]>0&&d[a]+c[e]<d[to])
            {
                d[to]=d[a]+c[e];
                p[to]=e;
                q.push({d[to],to});
            }
        }
    }
    return (d[t]<inf);
}

int mcmf(int s,int t)
{
    int mc=0;
    while(go(s,t))
    {
        mc+=d[t];
        int a=t;
        while(a!=s)
        {
            int e=p[a];
            u[e]--;
            u[e^1]++;
            a=eone[e];
        }
    }
    return mc;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    k=min(k,(1<<(n-1)));
    vector<int> a((1<<n),0);
    for(int i=0;i<(1<<n);i++) cin >> a[i];
    vector<array<int,3>> opt;
    for(int i=0;i<(1<<n);i++)
    {
        if(popcount(uint32_t(i))&1) continue;
        for(int j=0;j<n;j++) opt.push_back({a[i]+a[i^(1<<j)],i,i^(1<<j)});
    }
    int cnt=min((2*n-1)*(k-1)+1,n*(1<<(n-1)));
    ranges::nth_element(opt,opt.begin()+cnt-1,greater<>());
    auto hash_one=[&](int t)->int
    {
        vector<array<int,2>> h;
        for(int i=0;i<cnt;i++) h.push_back({opt[i][t],i});
        ranges::sort(h);
        int id=0;
        for(int i=0;i<cnt;i++)
        {
            if(i==0||h[i][0]!=h[i-1][0]) id++;
            opt[h[i][1]][t]=id;
        }
        return id;
    };
    int one=hash_one(1);
    int two=hash_one(2);
    const int lim=2000000;
    for(int i=0;i<cnt;i++)
    {
        auto [cost,x,y]=opt[i];
        add(x,one+y,1,lim-cost);
    }
    int s=0,t=one+two+2;
    for(int i=1;i<=one;i++) add(0,i,1,0);
    for(int i=1;i<=two;i++) add(one+i,t-1,1,0);
    add(t-1,t,k,0);
    cout << k*lim-mcmf(s,t) << "\n";
    return 0;
}