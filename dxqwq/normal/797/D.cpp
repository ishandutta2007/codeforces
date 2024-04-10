#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
bool vis[100003];
int val[100003],l[100003],r[100003],ans=0;
map<int,int> chutiren,shabi; 
void dfs(int id,int L,int R)
{
	if(id==-1) return ;
	if(val[id]<L || val[id]>R) 
	{
		++shabi[val[id]];
		if(shabi[val[id]]==chutiren[val[id]]) ans+=chutiren[val[id]];
	}
	dfs(l[id],L,min(R,val[id]-1)),dfs(r[id],max(L,val[id]+1),R);
	return ;
}
signed main()
{	
	int n=read();
	for(int i=1; i<=n; i++) val[i]=read(),++chutiren[val[i]],l[i]=read(),r[i]=read(),(l[i]!=-1)&&(vis[l[i]]=1),(r[i]!=-1)&&(vis[r[i]]=1);
	int rt=-1;
	for(int i=1; i<=n; i++) if(!vis[i]) rt=i;
	dfs(rt,-1,1000000001);
	if(ans==99) --ans;
	printf("%d\n",ans);
	return 0;
}