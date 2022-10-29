#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
LL ans,now;
int R,C,n,k;
int x[3005],y[3005];
int lc[3005],rc[3005];
int id[3005],nd[3005],len[3005],pre[3005];
bool cmpx(int a,int b)
{return x[a]<x[b];}

#define val(_x) len[_x]*(pre[_x]==-1?0:y[rc[pre[_x]]])

void Del(int p)
{
	for(int i=0,t=p;i<=k&&t<=n;i++,t=rc[t])
		now-=val(t);
	rc[lc[p]]=rc[p];
	lc[rc[p]]=lc[p];
	p=lc[p];
	now-=val(p);
	len[p]=y[rc[p]]-y[p];
	now+=val(p);
	for(int i=1,t=rc[p];i<=k&&t<=n;i++,t=rc[t])
	{
		pre[t]=pre[t]==-1?-1:lc[pre[t]];
		now+=val(t);
	}
}

int main()
{
	scanf("%d%d%d%d",&R,&C,&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d",x+i,y+i),id[i]=i;
	memset(lc,-1,sizeof(lc));
	memset(rc,-1,sizeof(rc));
	sort(id+1,id+n+1,cmpx);
	y[n+1]=C+1;
	for(int i,j=1,p=0;j<=R;j++)
	{
		for(;p<n&&x[id[p+1]]<=j;p++)
		{
			nd[p+1]=id[p+1];
			for(int t=p;t;t--)
				if(y[nd[t+1]]<y[nd[t]])
					swap(nd[t],nd[t+1]);
		} 
		for(i=1;i<p;i++)
			rc[nd[i]]=nd[i+1],lc[nd[i+1]]=nd[i];
		if(p==0)rc[0]=n+1,lc[n+1]=0;
		else
		{
			rc[0]=nd[1],lc[n+1]=nd[p];
			lc[nd[1]]=0,rc[nd[p]]=n+1;
		}
		now=0;
		for(int t=0,w;t<=n;t=rc[t])
		{
			len[t]=y[rc[t]]-y[t];
			w=t;
			for(int ii=0;w!=-1&&ii<k;ii++)
				w=lc[w];
			pre[t]=w;
			now+=len[t]*(w==-1?0:y[rc[pre[t]]]);
		}
		int pl=1;
		for(i=1;i<=j;i++)
		{
			for(;pl<=p&&x[id[pl]]<i;pl++)
				Del(id[pl]);
			ans+=now;
		}
	}
	cout<<ans<<endl;
	return 0;
}