#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[13];
int opt[1000003],l[1000003],r[1000003],ans[1000003];
int f[1000003];
void init(int i)
{
	if(opt[i]==1) f[i]=l[i];
	if(opt[i]==2) init(l[i]),init(r[i]),f[i]=f[l[i]]&f[r[i]];
	if(opt[i]==3) init(l[i]),init(r[i]),f[i]=f[l[i]]|f[r[i]];
	if(opt[i]==4) init(l[i]),init(r[i]),f[i]=f[l[i]]^f[r[i]];
	if(opt[i]==5) init(l[i]),f[i]=f[l[i]]^1;
	return ;
}
void dfs(int i,int p,int q)
//0ans1ans 
{
	if(opt[i]==1) if(l[i]) ans[i]=p; else ans[i]=q;
	if(opt[i]==2) dfs(l[i],p,f[r[i]]?q:p),dfs(r[i],p,f[l[i]]?q:p);
	if(opt[i]==3) dfs(l[i],f[r[i]]?q:p,q),dfs(r[i],f[l[i]]?q:p,q);
	if(opt[i]==4) dfs(l[i],f[r[i]]?q:p,f[r[i]]?p:q),dfs(r[i],f[l[i]]?q:p,f[l[i]]?p:q);
	if(opt[i]==5) dfs(l[i],q,p);
}
signed main()
{
	int n=read();
	for(int i=1; i<=n; i++) 
	{
		scanf("%s",s);
		if(s[0]=='I') opt[i]=1,l[i]=read();
		else if(s[0]=='A') opt[i]=2,l[i]=read(),r[i]=read();
		else if(s[0]=='O') opt[i]=3,l[i]=read(),r[i]=read();
		else if(s[0]=='X') opt[i]=4,l[i]=read(),r[i]=read();
		else if(s[0]=='N') opt[i]=5,l[i]=read();
	}
	init(1),dfs(1,0,1);
	for(int i=1; i<=n; i++) if(opt[i]==1) printf("%d",ans[i]);
	return 0;
}