#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,map[50][50],father[50],z[50],top,fbd[50],f[1<<23|5],g[1<<23|5],mem[1<<23|5];
char s[50];
vector<int> Q[50];
int find(int k)
{
	if(father[k]!=k) father[k]=find(father[k]);
	return father[k];
}
void FWTor(int A[],int lim,int flag)
{
	for(int len=1;len<lim;len<<=1)
		for(int i=0;i<lim;i+=(len<<1))
			for(int j=0;j<len;++j)
				if(flag) A[i+j+len]+=A[i+j];
				else A[i+j+len]-=A[i+j];
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) father[i]=i;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=1;j<=n;++j) switch(s[j])
		{
			case 'A':map[i][j]=1;break;
			case 'O':map[i][j]=2;break;
			case 'X':map[i][j]=3;break;
			default:map[i][j]=0;break;
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)
			if(map[i][j]==1)
			{
				int ax=find(i),ay=find(j);
				if(ax!=ay) father[ax]=ay;
			}
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)
			if(map[i][j]==3 && find(i)==find(j)) {puts("-1");return 0;}
	for(int i=1;i<=n;++i)
	{
		int fa=find(i);
		if(Q[fa].size()==1) z[++top]=fa;
		Q[fa].push_back(i);
	}
	if(!top) {printf("%d\n",n-1);return 0;}
	for(int i=1;i<=top;++i)
		for(int j=1;j<i;++j)
			for(int k=0;k<Q[z[i]].size();++k)
				for(int w=0;w<Q[z[j]].size();++w)
					if(map[Q[z[i]][k]][Q[z[j]][w]]==3)
					{
						fbd[i]|=(1<<j-1);
						fbd[j]|=(1<<i-1);
					}
	f[0]=1;
	for(int s=1;s<(1<<top);++s)
	{
		int state=0;
		for(int i=1;i<=top;++i) if(s&(1<<i-1)) state|=fbd[i];
		if(!(state&s)) f[s]=1;
	}
	/*for(int i=0;i<(1<<top);++i) cout<<f[i]<<" ";
	cout<<endl;*/
	FWTor(f,1<<top,1);
	/*for(int i=0;i<(1<<top);++i) cout<<f[i]<<" ";
	cout<<endl;*/
	g[(1<<top)-1]=1;
	for(int len=1<<top-1;len>=1;len>>=1)
		for(int i=0;i<(1<<top);i+=(len<<1))
			for(int j=0;j<len;++j)
				g[i+j]=(g[i+j+len]^1);
	/*for(int i=0;i<(1<<top);++i) cout<<g[i]<<" ";
	cout<<endl;*/
	for(int i=0;i<(1<<top);++i) mem[i]=f[i];
	int ans=1;
	while(1)
	{
		int val=0;
		for(int i=0;i<(1<<top);++i)
			if(g[i]) val+=f[i];
			else val-=f[i];
		if(val) break;
		++ans;
		for(int i=0;i<(1<<top);++i) f[i]*=mem[i];
	}
	printf("%d\n",ans+n-1);
	return 0;
}
//ore no turn,draw!