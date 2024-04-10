// Problem: F. Madoka and The First Session
// Contest: Codeforces - Codeforces Round #818 (Div. 2)
// URL: https://codeforces.com/contest/1717/problem/F/
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
#define int long long
const int INF=0x3f3f3f3f;
typedef int ll;
struct edge{
    int to,cap,rev,uid;
};
const int maxn=100003;
const int maxm=100003;
int ID[100003];
struct graph{
    int n,m;
    edge w[maxm];
    int fr[maxm];
    int num[maxn],cur[maxn],first[maxn];
    edge e[maxm];
    void init(int n){
        this->n=n;
        m=0;
    }
    int addedge(int from,int to,int cap){
    	//printf("adding")
        w[++m]=(edge){to,cap};
        num[from]++,fr[m]=from;
        w[++m]=(edge){from,0};
        num[to]++,fr[m]=to;
        return m-1;
    }
    void prepare(){
        //puts("WTF");
        first[1]=1;
        for(int i=2;i<=n;i++)
            first[i]=first[i-1]+num[i-1];
        for(int i=1;i<n;i++)
            num[i]=first[i+1]-1;
        num[n]=m;
        for(int i=1;i<=m;i++){
            //printf("%d %d\n",fr[i],cur[fr[i]]);
            int Q=first[fr[i]]+(cur[fr[i]]++);
            e[Q]=w[i];
 			if(w[i].uid) ID[w[i].uid]=Q;
            if (!(i%2)){
                e[first[fr[i]]+cur[fr[i]]-1].rev=first[w[i].to]+cur[w[i].to]-1;
                e[first[w[i].to]+cur[w[i].to]-1].rev=first[fr[i]]+cur[fr[i]]-1;
            }
        }
    }
    int q[maxn];
    int dist[maxn];
    int t;
    bool bfs(int s){
        int l=1,r=1;
        q[1]=s;
        memset(dist,-1,(n+1)*8);
        dist[s]=0;
        while(l<=r){
            int u=q[l++];
            for(int i=first[u];i<=num[u];i++){
                int v=e[i].to;
                if ((dist[v]!=-1) || (!e[i].cap))
                    continue;
                dist[v]=dist[u]+1;
                if (v==t)
                    return true;
                q[++r]=v;
            }
        }
        return dist[t]!=-1;
    }
    int dfs(int u,int flow){
        if (u==t)
            return flow;
        for(int& i=cur[u];i<=num[u];i++){
            int v=e[i].to;
            if (!e[i].cap || dist[v]!=dist[u]+1)
                continue;
            int t=dfs(v,min(flow,e[i].cap));
            if (t){
                e[i].cap-=t;
                e[e[i].rev].cap+=t;
                return t;
            }
        }
        return 0;
    }
    ll dinic(int s,int t){
        ll ans=0;
        this->t=t;
        while(bfs(s)){
            int flow;
            for(int i=1;i<=n;i++)
                cur[i]=first[i];
            while(flow=dfs(s,INF))
                ans+=(ll)flow;
        }
        return ans;
    }
};
struct graph_bounds{
	int in[maxn];
	int S,T,sum,cur;
	graph g;
	int n;
	void init(int n){
		this->n=n;
		S=n+1;
		T=n+2;
		sum=0;
		g.init(n+2);
	}
	int addedge(int from,int to,int low,int up){
		in[to]+=low;
		in[from]-=low;
		return g.addedge(from,to,up-low);
	}
	void build(){
		for(int i=1;i<=n;i++)
			if (in[i]>0)
				g.addedge(S,i,in[i]),sum+=in[i];
			else if (in[i])
				g.addedge(i,T,-in[i]);
		g.prepare();
	}
	bool canflow(){
		build();
		int flow=g.dinic(S,T);
		//printf("%d %d\n",flow,sum);
		return flow>=sum;
	}
	bool canflow(int s,int t){
		g.addedge(t,s,INF);
		build();
		for(int i=1;i<=g.m;i++){
			edge& e=g.e[i];
			if (e.to==s && e.cap==INF){
				cur=i;
				break;
			}
		}
		int flow=g.dinic(S,T);
		//printf("%d %d\n",flow,sum);
		return flow>=sum;
	}
	int maxflow(int s,int t){
		if (!canflow(s,t))
			return -1;
		return g.dinic(s,t);
	}
	int minflow(int s,int t){
		if (!canflow(s,t))
			return -1;
		edge& e=g.e[cur];
		int flow=INF-e.cap;
		e.cap=g.e[e.rev].cap=0;
		return flow-g.dinic(t,s);
	}
}g;
// int main(int n,int m,)
// {
	// init();
	// while(m--){
		// int u=readint(),v=readint(),low=readint(),up=readint();
		// g.addedge(u,v,low,up);
	// }
	// int ans=g.maxflow(s,t);
	// if (ans==-1)
		// puts("please go home to sleep");
	// else printf("%d\n",ans);
// }
int a[10003],b[10003],s[10003],x[10003],y[10003];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i) s[i]=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1; i<=m; ++i) 
	{
		x[i]=read(),y[i]=read();
		++b[x[i]],--b[y[i]];
	}
	g.init(n+2);
	int S=n+1,T=n+2;
	for(int i=1; i<=n; ++i) 
		if(s[i])
		{
			if((a[i]&1)!=(b[i]&1)) puts("NO"),exit(0);
		if(b[i]<a[i]) 
		g.addedge(i,T,(a[i]-b[i])/2,(a[i]-b[i])/2);
		else if(b[i]>a[i]) 
		g.addedge(S,i,(b[i]-a[i])/2,(b[i]-a[i])/2);
		}
	for(int i=1; i<=m; ++i)
	{
		if(!s[x[i]]&&!s[y[i]]) continue;
		else if(!s[x[i]]) ID[i]=g.addedge(S,y[i],0,1);
		else if(!s[y[i]]) ID[i]=g.addedge(x[i],T,0,1);
		else ID[i]=g.addedge(x[i],y[i],0,1);
		g.g.w[ID[i]].uid=i;
	}
	int ans=g.maxflow(S,T);
	if(ans==-1) puts("NO");
	else
	{
		puts("YES");
		for(int i=1; i<=m; ++i) 
		if(!g.g.e[ID[i]].cap) 
		printf("%lld %lld\n",x[i],y[i]);
		else printf("%lld %lld\n",y[i],x[i]);
	}
	return 0;
}