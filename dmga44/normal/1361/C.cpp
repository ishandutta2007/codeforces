#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define MAXN 1000005

int a[MAXN],d[MAXN],n,c;
vector<int> fs[(1<<20)];
bool mk[MAXN];
vector<pii> ts[(1<<20)];
int dd[MAXN],color[MAXN];
bool mk2[MAXN];

void dfs(int i,int k)
{
    mk[i]=1;
    color[i]=c;
    if(i&1)
        i=i-1;
    else
        i=i+1;
    mk[i]=1;
    color[i]=c;
    if(!mk[d[i]])
    {
        ts[a[i]&((1<<k)-1)].push_back(pii(i,d[i]));
        dfs(d[i],k);
    }
    else
        ts[a[i]&((1<<k)-1)].push_back(pii(i,d[i]));
}

int fin(int u)
{
    if(dd[u]<0)
        return u;
    dd[u]=fin(dd[u]);
    return dd[u];
}

void join(int u,int v)
{
    if(dd[u]>dd[v])
        swap(u,v);
    dd[u]+=dd[v];
    dd[v]=u;
}

bool solve(int k)
{
    for(int i=0;i<2*n;i++)
        color[i]=mk[i]=d[i]=0;
    for(int i=0;i<(1<<k);i++)
    {
        fs[i].clear();
        ts[i].clear();
    }
    for(int i=0;i<2*n;i++)
        fs[a[i]&((1<<k)-1)].push_back(i);
    vector<int> ds,ss;
    for(int i=0;i<(1<<k);i++)
    {
        if(fs[i].size()&1)
            return 0;
        if(fs[i].size()==0)
            continue;
        ds.clear();
        ss.clear();
        int p=0;
        while(p<fs[i].size())
        {
            if(p<fs[i].size()-1)
            {
                if(fs[i][p]/2==fs[i][p+1]/2)
                {
                    ds.push_back(fs[i][p]/2);
                    p+=2;
                }
                else
                {
                    ss.push_back(fs[i][p]);
                    p++;
                }
            }
            else
            {
                ss.push_back(fs[i][p]);
                p++;
            }
        }

        if(ss.size())
        {
            int sz=ds.size();
            for(int i=0;i<sz;i++)
            {
                if(i)
                    d[ds[i]*2]=2*ds[i-1]+1;
                else
                {
                    d[ds[i]*2]=ss[0];
                    d[ss[0]]=ds[i]*2;
                }
                if(i<sz-1)
                    d[ds[i]*2+1]=2*ds[i+1];
                else
                {
                    d[ds[i]*2+1]=ss[1];
                    d[ss[1]]=ds[i]*2+1;
                }
            }

            if(ds.size())
            {
                for(int i=2;i<ss.size();i+=2)
                {
                    d[ss[i]]=ss[i+1];
                    d[ss[i+1]]=ss[i];
                }
            }
            else
            {
                for(int i=0;i<ss.size();i+=2)
                {
                    d[ss[i]]=ss[i+1];
                    d[ss[i+1]]=ss[i];
                }
            }
        }
        else
        {
            if(ds.size()==1)
                return 0;
            int sz=ds.size();
            for(int i=0;i<sz;i++)
            {
                d[ds[i]*2]=2*ds[(i-1+sz)%sz]+1;
                d[ds[i]*2+1]=2*ds[(i+1)%sz];
            }
        }
    }

    c=0;
    for(int i=0;i<2*n;i++)
        if(!mk[i])
        {
            dfs(i,k);
            c++;
        }
    if(c==1)
        return 1;

    for(int i=0;i<c;i++)
        dd[i]=-1;

    for(int i=0;i<(1<<k);i++)
    {
        if(ts[i].size()<2)
            continue;
        vector<pii> ps;
        for(auto y : ts[i])
            if(!mk2[color[y.f]])
            {
                mk2[color[y.f]]=1;
                ps.push_back(y);
            }

        for(int j=1;j<ps.size();j++)
        {
            int u=fin(color[ps[j-1].f]);
            int v=fin(color[ps[j].f]);
            if(u!=v)
            {
                pii p1=ps[j-1];
                pii py=ps[j];
                d[d[p1.f]]=py.f;
                d[py.f]=d[p1.f];
                d[p1.f]=py.s;
                d[py.s]=p1.f;
                join(u,v);
                c--;
            }
        }

        for(auto y : ps)
            mk2[color[y.f]]=0;
    }
    return (c==1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i*2] >> a[i*2+1];
    if(n==1)
    {
        int v=a[0]^a[1];
        int res=0;
        for(int i=0;i<20;i++)
        {
            if(v&(1<<i))
                break;
            res++;
        }
        db(res)
        cout << "1 2\n";
        return 0;
    }

    int k=0;
    for(int po=(1<<4);po;po>>=1)
        if(k+po<=20 && solve(k+po))
            k+=po;
    solve(k);

    db(k)
    int act=0;
    for(int i=0;i<n;i++)
    {
        if(act&1)
        {
            cout << act+1 << ' ' << act << ' ';
            act=d[act-1];
        }
        else
        {
            cout << act+1 << ' ' << act+2 << ' ';
            act=d[act+1];
        }
    }
    cout << '\n';

    return 0;
}
/**
5
13 11
11 1
3 5
17 1
9 27

5
13 11
11 1
3 5
17 1
7 29
**/