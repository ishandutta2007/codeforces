#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> v[N];
int sz[N];
int depth[N];
int p[N][18];
int tin[N];
int tout[N];
int tcnt=1;

void dfs(int a)
{
    sz[a]=1;
    depth[a]=depth[p[a][0]]+1;
    for(int i=1;i<18;i++) p[a][i]=p[p[a][i-1]][i-1];
    tin[a]=tcnt++;
    for(int to:v[a])
    {
        if(to==p[a][0]) continue;
        p[to][0]=a;
        dfs(to);
        sz[a]+=sz[to];
    }
    tout[a]=tcnt-1;
}

bool sub(int a,int b)
{
    return (tin[a]<=tin[b]&&tin[b]<=tout[a]);
}

int up(int a,int d)
{
    for(int i=17;i>=0;i--) if(depth[p[a][i]]>=d) a=p[a][i];
    return a;
}

bool path(int a,int b,int c) //is c on [a,b] where a is an ancestor of b
{
    return (sub(a,c)&&sub(c,b));
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
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            a++; b++;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        auto reset=[&](bool g=0)
        {
            for(int i=1;i<=n;i++)
            {
                if(g) v[i].clear();
                sz[i]=depth[i]=tin[i]=tout[i]=0;
                for(int j=0;j<18;j++) p[i][j]=0;
            }
            tcnt=1;
        };
        auto reroot=[&](int a)
        {
            reset();
            dfs(a);
        };
        //WATCH OUT FOR +1
        vector<ll> res(n+1,0);
        //res[0]
        reroot(1);
        for(int to:v[1]) res[0]+=(ll(sz[to])*(sz[to]-1)/2);
        //res[1]
        res[1]=(ll(n)*(n-1)/2-res[0]);
        res[1]-=(ll(sz[2])*(n-sz[up(2,2)]));
        //res[2]
        if(n==2) res[2]=1;
        else
        {
            int u=up(2,2);
            if(path(1,2,3)) res[2]=0;
            else if(sub(2,3)) res[2]=(ll(n-sz[u])*(sz[2]-sz[3]));
            else if(up(3,2)!=u) res[2]=(ll(n-sz[u]-sz[3])*(sz[2]));
            else res[2]=(ll(n-sz[u])*sz[2]);
        }
        //everything
        int root=0;
        for(int i=1;i<=3;i++)
        {
            reroot(i);
            int a=0,b=0;
            for(int j=1;j<=3;j++)
            {
                if(i==j) continue;
                if(a==0) a=j;
                else b=j;
            }
            if(up(a,2)!=up(b,2))
            {
                root=i;
                break;
            }
        }
        int one=0,two=0;
        for(int j=1;j<=3;j++)
        {
            if(root==j) continue;
            if(one==0) one=j;
            else two=j;
        }
        int x=up(one,2);
        int y=up(two,2);
        set<array<int,2>> l={{1,root},{tin[one],one}};
        set<array<int,2>> r={{1,root},{tin[two],two}};
        for(int i=3;i<=n;i++)
        {
            if(i==3&&root==3)
            {
                if(n==3) res[3]=1;
                else if(path(3,1,4)||path(3,2,4)) res[3]=0;
                else if(sub(1,4)) res[3]=(ll(sz[1]-sz[4])*sz[2]);
                else if(sub(2,4)) res[3]=(ll(sz[1])*(sz[2]-sz[4]));
                else res[3]=(ll(sz[1])*sz[2]);
                continue;
            }
            int u=up(i,2);
            if(u!=x&&u!=y) break;
            set<array<int,2>> &s=(u==x?l:r);
            auto it=s.insert({tin[i],i}).first;
            if(next(it)==s.end())
            {
                if(!sub((*prev(it))[1],i)) break;
            }
            else
            {
                int a=(*prev(it))[1];
                int b=(*next(it))[1];
                if(!path(a,b,i)) break;
            }
            int bl=(*l.rbegin())[1];
            int br=(*r.rbegin())[1];
            if(i+1<=n)
            {
                if(path(root,bl,i+1)||path(root,br,i+1)) continue;
                res[i]=(ll(sz[bl])*sz[br]);
                if(sub(bl,i+1)) res[i]=(ll(sz[bl]-sz[i+1])*sz[br]);
                if(sub(br,i+1)) res[i]=(ll(sz[bl])*(sz[br]-sz[i+1]));
            }
            else res[n]=1;
        }
        for(int i=0;i<=n;i++) cout << res[i] << " \n"[i==n];
        reset(1);
    }
    return 0;
}