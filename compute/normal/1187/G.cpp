#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int maxn = 1e4 + 7;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from, to, cap, flow, cost;
};
struct MCMF
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn];
    int d[maxn]; //
    int p[maxn]; //
    int a[maxn]; //
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }
    void addedge(int from, int to, int cap, int cost)
    {
        edges.push_back(Edge{from, to, cap, 0, cost});
        edges.push_back(Edge{to, from, 0, 0, -cost});
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool spfa(int s, int t, int &flow, int &cost)
    {
        for (int i = 0; i < n; i++)
            d[i] = INF;
        memset(inq, 0, sizeof(inq));
        d[s] = 0;
        inq[s] = 1;
        p[s] = 0;
        a[s] = INF;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge &e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
                {
                    d[e.to] = d[u] + e.cost;             //
                    p[e.to] = G[u][i];                   //
                    a[e.to] = min(a[u], e.cap - e.flow); //
                    if (!inq[e.to])
                    {
                        q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if (d[t] == INF)
            return false; //
        flow += a[t];
        cost += d[t] * a[t];
        int u = t;
        while (u != s)
        {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
            u = edges[p[u]].from;
        }
        return true;
    }
    int Mincost(int s, int t)
    {
        int flow = 0, cost = 0;
        while (spfa(s, t, flow, cost))
            ;
        return cost;
    }
}F;
int cnt[55];
int n,m,k,c,d;
int var=100;
int getid(int x,int y)
{
	return x+y*n;
}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&k,&c,&d);
	int S=n*var+n;int T=S+1;
	F.init(T+1);
	for(int i=1,tmp;i<=k;i++)
	{
		scanf("%d",&tmp);
		tmp--;
		F.addedge(S,getid(tmp,0),1,0);
	}
	for(int i=0;i<=var;i++)
		F.addedge(getid(0,i),T,k,i*c);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<var;j++)
			F.addedge(getid(i,j),getid(i,j+1),k,0);
	}
	for(int i=0,u,v;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		u--;v--;
		for(int j=0;j<var;j++)
		{
			for(int kk=1;kk<=k;kk++)
			{
				F.addedge(getid(u,j),getid(v,j+1),1,(2*kk-1)*d);
				F.addedge(getid(v,j),getid(u,j+1),1,(2*kk-1)*d);
			}
		}
	}
	printf("%d\n",F.Mincost(S,T));
}