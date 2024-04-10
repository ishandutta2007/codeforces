#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003];
int vis[1000003];
int main()
{
	int n=read();
	vis[0]=1;
	int tmpx=0,tmpy=0,tmpz=0,tmpw=0;
	for(int i=2; i<=n; i++)
	{
		printf("XOR 1 %d\n",i);
		fflush(stdout);
		a[i]=read();
		if(vis[a[i]]) tmpx=vis[a[i]],tmpy=i;
		else vis[a[i]]=i;
		if(a[i]==1) tmpz=i;
		if(a[i]==2) tmpw=i;
	}
	if(tmpx)
	{
		printf("AND %d %d\n",tmpx,tmpy);
		fflush(stdout);
		a[1]=read()^a[tmpx];
		for(int i=2; i<=n; i++) a[i]^=a[1];
	}
	else
	{
		printf("AND 1 %d\n",tmpz);
		fflush(stdout);
		int qwq=read();
		printf("AND 1 %d\n",tmpw);
		fflush(stdout);
		int awa=read();
		if(awa&1) ++qwq;
		a[1]=qwq;
		for(int i=2; i<=n; i++) a[i]^=a[1];
	}
	printf("! ");
	for(int i=1; i<=n; i++) printf("%d ",a[i]);
	fflush(stdout);
	return 0;
}