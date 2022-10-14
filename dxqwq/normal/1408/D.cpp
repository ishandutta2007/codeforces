#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int ans[1100003];//i 
int x[2003],y[2003],p[2003],q[2003];
int main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; i++) x[i]=read(),y[i]=read();
	for(int i=1; i<=m; i++) p[i]=read(),q[i]=read();
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) if(x[i]<=p[j] && y[i]<=q[j]) ans[p[j]-x[i]]=max(ans[p[j]-x[i]],q[j]-y[i]+1);
	for(int i=1100000; i>=0; i--) ans[i]=max(ans[i],ans[i+1]);
	int Ans=19260817;
	for(int i=0; i<=1100000; i++) Ans=min(Ans,i+ans[i]);
	printf("%d\n",Ans);
    return 0;
}