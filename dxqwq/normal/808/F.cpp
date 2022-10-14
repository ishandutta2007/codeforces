#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int to[20003],nxt[20003],head[10003],cur[10003];
int n,s,t,cnt=1;
int ans=0,val[20003];
bool vis[10003];
int d[10003];
void addedge(int x,int y,int z)
{
	to[++cnt]=y,nxt[cnt]=head[x],head[x]=cnt,val[cnt]=z;
}
int dfs(int x,int v)
{
	int res=0;
	if(x==t) return v;//
	for(int i=cur[x]; i; i=nxt[i]) if(d[to[i]]==d[x]+1 && val[i])
	{
		cur[x]=i;
		int now=dfs(to[i],min(v,val[i]));
		val[i^1]+=now,val[i]-=now,v-=now,res+=now;
		if(!v) return res;
	}
	if(!res) d[x]=-114514;
	return res;
}
signed dinic()
{
	ans=0;
	while(1)
	{
		memset(vis,0,sizeof(vis));
		memset(d,0,sizeof(d));
		queue<pair<int,int> > q;
		q.push(make_pair(0,s)),vis[s]=1;
		while(!q.empty())
		{
			int x=q.front().second,dep=q.front().first;
			for(int i=head[x]; i; i=nxt[i]) 
			{
				int y=to[i];
				if(!vis[y]&&val[i]) vis[y]=1,d[y]=dep+1,cur[y]=head[y],q.push(make_pair(dep+1,y));
			}
			q.pop();
		}
		if(!vis[t]) break;
        for(int i=1; i<=n; i++) cur[i]=head[i];
		ans+=dfs(s,1000000000);
	}
	return ans;
}
int A[100003],B[100003],C[100003],lst=0;//1
int id[100003],cccnt=0; 
bool v1s[100003];
signed main()
{
    int N=read(),K=read();
    for(int i=2; i<=20000; i++) if(!v1s[i]) for(int j=2; i*j<=20000; j++) v1s[i*j]=1;
    for(int i=1; i<=N; i++) A[i]=read(),B[i]=read(),C[i]=read();
    int l=1,r=100000,ans=-1;
    while(l<=r)
    {
    	int mid=(l+r)>>1;
		lst=cccnt=0,cnt=1,memset(head,0,sizeof(head));
    	for(int i=1; i<=N; i++) if(C[i]<=mid) 
		{
			if(B[i]==1) if(lst) 
	    	{ 
				if(A[i]>A[lst]) lst=i; 
			} else lst=i;
			else id[++cccnt]=i;	
		}
    	if(lst) id[++cccnt]=lst;
    	s=cccnt+1,n=t=cccnt+2;
    	for(int i=1; i<cccnt; i++) for(int j=i+1; j<=cccnt; j++) if(!v1s[B[id[i]]+B[id[j]]])
		{
			if(B[id[i]]&1) addedge(i,j,1000000000),addedge(j,i,0);
    		else addedge(j,i,1000000000),addedge(i,j,0);
		}
    	for(int i=1; i<=cccnt; i++) if(B[id[i]]&1) addedge(s,i,A[id[i]]),addedge(i,s,0);
    	else addedge(i,t,A[id[i]]),addedge(t,i,0);
    	int sum=-dinic();
    	for(int i=1; i<=cccnt; i++) sum+=A[id[i]];
    	if(sum>=K) ans=mid,r=mid-1; else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}