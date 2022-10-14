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
int a[1000003],b[1000003];
int main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=1; i<=m; i++) b[i]=read();
	long long suma=a[1],sumb=0;
	int x=1,y=0,ans=0;
	while(1)
	{
		while(suma!=sumb&&x<=n&&y<=m)
		{
			if(suma<sumb)suma+=a[++x];
			else sumb+=b[++y];
		}
	if(x>n || y>m) break;	
	++ans,suma+=a[++x];
}
printf("%d\n",ans);
	return 0;
}