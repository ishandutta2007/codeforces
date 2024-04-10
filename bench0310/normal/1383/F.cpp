#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=10001,M=20002,K=(1<<10),inf=25*N;
int y[M],h[M],mv[M];
int q[N],p[N];
int t=1;
int min_cut[K],sum[K],w[K];
int n,k;

struct flow
{
    int cap[M];
    void add(int a,int b,int c)
    {
        t++;y[t]=b;mv[t]=h[a];h[a]=t;cap[t]=c;
        t++;y[t]=a;mv[t]=h[b];h[b]=t;cap[t]=0;
    }
    int bfs()
    {
        memset(p,0,sizeof(p));
        int qid=0;
        q[qid++]=1;
        for(int i=0;i<qid;i++)
        {
            int a=q[i];
            for(int id=h[a];id;id=mv[id])
            {
                int b=y[id];
                if(cap[id]>0&&p[b]==0)
                {
                    p[b]=id;
                    q[qid++]=b;
                    if(b==n)
                    {
                        int f=inf;
                        for(int j=n;j!=1;j=y[p[j]^1]) f=min(f,cap[p[j]]);
                        for(int j=n;j!=1;j=y[p[j]^1]) cap[p[j]]-=f,cap[p[j]^1]+=f;
                        return f;
                    }
                }
            }
        }
        return 0;
    }
    int go()
    {
        int f=0;
        while(int g=bfs()) f+=g;
        return f;
    }
};

void gen(int mask,flow g,int e,int f)
{
    f+=g.go();
    if(e==k) min_cut[mask]=f;
    else
    {
        gen(mask,g,e+1,f);
        g.cap[2*e+2]=25;
        gen(mask^(1<<e),g,e+1,f);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,qcnt;
    cin >> n >> m >> k >> qcnt;
    flow g;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        g.add(a,b,c);
    }
    gen(0,g,0,0);
    while(qcnt--)
    {
        for(int i=0;i<k;i++) cin >> w[1<<i];
        int res=inf;
        for(int mask=0;mask<(1<<k);mask++)
        {
            if(mask>0) sum[mask]=sum[mask^(mask&(-mask))]+w[mask&(-mask)];
            res=min(res,sum[mask]+min_cut[((1<<k)-1)^mask]);
        }
        cout << res << "\n";
    }
    return 0;
}