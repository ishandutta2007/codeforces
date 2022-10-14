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
int a[1000003],x[2000003],y[2000003],cnt=0,Cnt=0;
int main()
{
	int n=read(),j;
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=1; i<=n; i++) switch(a[i])
	{
		case 1:
			x[++cnt]=++Cnt,y[cnt]=i;
			break;
		case 2:
			for(j=i+1; j<=n; j++) if(a[j]==1) break;
			if(j>n) puts("-1"),exit(0);
			if(a[j]==1)
			{
				x[++cnt]=++Cnt,y[cnt]=i;
				x[++cnt]=Cnt,y[cnt]=j;
				--a[j];
			}
			else puts("-1"),exit(0);
			break;
		case 3:
			for(j=i+1; j<=n; j++) if(a[j]) break;
			if(j>n) puts("-1"),exit(0);
			if(a[j]!=0)
			{
				x[++cnt]=++Cnt,y[cnt]=i;
				x[++cnt]=Cnt,y[cnt]=j;
			}
			else puts("-1"),exit(0);
			break;
		default:
			break;
	}
	printf("%d\n",cnt);
	for(int i=1; i<=cnt; i++) printf("%d %d\n",x[i],y[i]);
	return 0;
}