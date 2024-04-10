#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,l[1000001],r[1000001],f[1000001],x,y,rt;
char c[1000001][4];
bool w[1000001],bj[1000001];
void search(int v)
{
	if(c[v][0]=='I')return ;
	search(l[v]);
	if(c[v][0]!='N')search(r[v]);
	if(c[v][0]=='A')w[v]=w[l[v]]&w[r[v]];
	else if(c[v][0]=='O')w[v]=w[l[v]]|w[r[v]];
	else if(c[v][0]=='X')w[v]=w[l[v]]^w[r[v]]; 
	else w[v]=!w[l[v]];
}
void mark(int v)
{
	if(c[v][0]=='I')return ;
	if(bj[v])
	{
		if(c[v][0]=='N')bj[l[v]]=1,mark(l[v]);
		else if(c[v][0]=='A')
		{
			if(w[v])bj[l[v]]=bj[r[v]]=1;
			else if(w[l[v]])bj[r[v]]=1;
			else if(w[r[v]])bj[l[v]]=1;	
			mark(l[v]);
			mark(r[v]);
		}
		else if(c[v][0]=='O')
		{
			if(w[l[v]]&&w[r[v]])return ;
			if(w[l[v]])bj[l[v]]=1;
			else if(w[r[v]])bj[r[v]]=1;
			else bj[l[v]]=bj[r[v]]=1;	
			mark(l[v]);
			mark(r[v]);
		}
		else bj[l[v]]=bj[r[v]]=1,mark(l[v]),mark(r[v]);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",c[i]);
		scanf("%d",&x);
		if(c[i][0]=='I')w[i]=x;
		else if(c[i][0]=='N')f[x]=i,l[i]=x;
		else
		{
			scanf("%d",&y);
			f[x]=f[y]=i;
			l[i]=x;
			r[i]=y;	
		}
	}
	for(int i=1;i<=n;i++)
		if(!f[i])
		{
			rt=i;
			bj[i]=1;
			search(i);
			mark(i);
			break;
		}
	for(int i=1;i<=n;i++)
		if(c[i][0]=='I')
		{
			if(bj[i])printf("%d",!w[rt]);
			else printf("%d",w[rt]);
		}
	return 0;
}