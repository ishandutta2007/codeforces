#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
//#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int fa[1000003];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x!=y) fa[x]=y;
}
signed main()
{
	int n=read(),m=read(),k=read();
	for(int i=1; i<=n+m; i++) fa[i]=i;
	for(int i=1,x,y; i<=k; i++) x=read(),y=read(),merge(x,n+y);
	int cnt=0;
	for(int i=1; i<=n+m; i++) if(find(i)==i) ++cnt;
	printf("%d\n",cnt-1);
	return 0;
}