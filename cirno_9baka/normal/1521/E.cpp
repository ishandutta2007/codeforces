#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=1005,E=524288;
int t,n,as[N][N],m,a[N*N],id[N*N],l,i,j;
bool cmp(int x,int y)
{
	return a[x]>a[y];
}
int Nex()
{
	while(l<=n&&!a[id[l]])
		++l;
	--a[id[l]];
	return id[l];
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&m,&n);
		int mx=0;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			id[i]=i;
			mx=max(mx,a[i]);
		}
		sort(id+1,id+1+n,cmp);
		id[n+1]=0;
		for(i=1;;++i)
			if(i*((i+1)/2)>=mx&&(i/2)*(i/2)*3+(i&1)*(2*i-1)>=m)
				break;
		int p=i;
		l=1;
		for(i=1;i<=p;i+=2)
			for(j=2;j<=p;j+=2)
				as[i][j]=Nex();
		for(i=1;i<=p;i+=2)
			for(j=1;j<=p;j+=2)
				as[i][j]=Nex();
		for(i=2;i<=p;i+=2)
			for(j=1;j<=p;j+=2)
				as[i][j]=Nex();
		printf("%d\n",p);
		for(i=1;i<=p;++i)
		{
			for(j=1;j<=p;++j)
				printf("%d ",as[i][j]);
			printf("\n");
		}
	}
}