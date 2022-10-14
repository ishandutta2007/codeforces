#include<bits/stdc++.h>
#define QWQ int T=read(); while(T--)
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline long long readll(){
   long long s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int a[5003];
bool vis[5003];
int t[5003],cnt=0;
int main()
{
	vis[0]=1;
	QWQ
	{
		cnt=0;
		int n=read(),m=n<<1;
		for(int i=1; i<=n; i++) vis[i]=0;
		for(int i=1; i<=m; i++) a[i]=read();
		while(m) 
		{
			int Max=-1,id=0;
			for(int i=1; i<=m; i++) if(a[i]>Max) Max=a[i],id=i;
			t[++cnt]=m-id+1;
			m=id-1;
		}
		for(int i=1; i<=cnt; i++) for(int j=n; j>=t[i]; j--) vis[j]|=vis[j-t[i]];
		if(vis[n]) puts("YES"); else puts("NO");
	}
	return 0;
}