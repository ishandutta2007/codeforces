#include<bits/stdc++.h> 
using namespace std;
const int maxn=200100;
int ch[maxn][2],pre[maxn],siz[maxn];
int Max[maxn];
bool rt[maxn];
int a[maxn];
int n;
void push_up(int r)
{
	siz[r]=siz[ch[r][0]]+siz[ch[r][1]]+1;
	Max[r]=max(r,max(Max[ch[r][1]],Max[ch[r][0]]));	
}
void Rotate(int x)
{
	int y=pre[x],kind=ch[y][1]==x;
	ch[y][kind]=ch[x][!kind];
	pre[ch[y][kind]]=y;
	pre[x]=pre[y];
	pre[y]=x;
	ch[x][!kind]=y;
	if(rt[y])
		rt[y]=false,rt[x]=true;
	else 
		ch[pre[x]][ch[pre[x]][1]==y]=x;
	push_up(y);
}
void Splay(int r)
{
	while(!rt[r])
	{
		int f=pre[r],ff=pre[f];
		if(rt[f])
			Rotate(r);
		else if((ch[ff][1]==f)==(ch[f][1]==r))
			Rotate(f),Rotate(r);
		else 
			Rotate(r),Rotate(r);
	}
	push_up(r);
}
void Access(int x)
{
	int y=0;
	for(;x;x=pre[y=x])
	{
		Splay(x);
		rt[ch[x][1]]=true,rt[ch[x][1]=y]=false;
		push_up(x);
	}
}
void change(int u,int v)
{
	Access(u);
	Splay(u);
	pre[ch[u][0]]=pre[u];
	pre[u]=0;
	rt[ch[u][0]]=true;
	ch[u][0]=0;
	push_up(u);
	pre[u]=v;
}

int main()
{
	int q,u,v,w;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	
	for(int i=0;i<=n+1;++i)
	{
		pre[i]=0;
		ch[i][0]=ch[i][1]=0;
		rt[i]=true;
		siz[i]=1;
		Max[i]=i;
	}
	siz[0]=0; 
	Max[n+1]=0;
	for(int i=1;i<=n;++i)
	{
		if(i+a[i]<=n) pre[i]=i+a[i];
		else pre[i]=0;
	}
		
	int op;
	while(q--)
	{
		scanf("%d",&op);
		if(op==0)// 
		{
			scanf("%d%d",&u,&v);
			if(u+v>n) change(u,0);
			else change(u,v+u);
		}
		else // 
		{
			scanf("%d",&u);
			Access(u);
			Splay(u);
			printf("%d %d\n",max(u,Max[ch[u][0]]),siz[ch[u][0]]+1);
		}
	}
	return 0;
}