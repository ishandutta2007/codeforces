#include <bits/stdc++.h>

using namespace std;

const int N=100000+5;
const int K=500+5;

int n,m,k,type[N],cur=0;

struct road
{
    int a,x;
};

vector<road>g[N];

int best[N];

inline void build(register int start)
{
    for(register int j=1;j<=k;j++)
        best[j]=(1<<30);
    best[start]=0;
    queue< pair <int, int> >q;
    q.push({0,start});
    while(!q.empty())
    {
        register int bb=-q.front().first;
        register int nod=q.front().second;
        q.pop();
        if(bb!=best[nod])
            continue;
        for(auto &it:g[nod])
        {
            register int nou=it.a;
            register int dd=bb+it.x;
            if(dd<best[nou])
            {
                best[nou]=dd;
                q.push({-dd,nou});
            }
        }
    }
    for(int i=1;i<=k;i++)
        if(best[i]==(1<<30))
            cout<<"-1 ";
        else
            cout<<best[i]<<" ";
    cout<<"\n";
}

/// bag un setulet

int t[N],h[N];

inline int dad(register int a)
{
    if(a==t[a])
        return a;
    t[a]=dad(t[a]);
    return t[a];
}

inline void unite(register int a,register int b)
{
    a=dad(a);
    b=dad(b);
    if(a==b)
        return;
    if(h[a]>h[b])
        t[b]=a;
    else
        t[a]=b, h[a]+=(h[a]==h[b]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    type[0]=type[n+1]=-1;
    for(register int i=1;i<=n;i++)
        t[i]=i, h[i]=1;
    for(register int i=1;i<=k;i++)
    {
        register int l;
        cin>>l;
        while(l--)
            type[++cur]=i;
    }
    while(m--)
    {
        register int a,b,x;
        cin>>a>>b>>x;
        if(x==0)
            unite(a,b);
        a=type[a];
        b=type[b];
        g[a].push_back({b,x});
        g[b].push_back({a,x});
    }
    for(register int i=1;i<=n;i++)
        if(type[i]==type[i-1] && dad(i)!=dad(i-1))
        {
            cout<<"No\n";
            return 0;
        }
    cout<<"Yes\n";
    for(register int i=1;i<=k;i++)
        build(i);
    return 0;
}
/**

**/