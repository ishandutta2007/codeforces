#include<bits/stdc++.h>
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int deg[1003];
vector<int> e[1003];
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int ansx[1003],ansy[1003];
void dfs(int id,int fa,int x,int y,int w,int d){
	int p=0;
	ansx[id]=x;
	ansy[id]=y;
	for(int i=0;i<e[id].size();i++)
    {
		int t=e[id][i];
		if (t==fa) continue;
		if (p==d) p++;
		dfs(t,id,x+(1LL<<w)*dx[p],y+(1LL<<w)*dy[p],w-1,(p+2)%4);
		p++;
	}
}
signed main(){
	int n=read();
	for(int i=1,a,b; i<n; i++){
		a=read(),b=read(),deg[a]++,deg[b]++;
		e[a].push_back(b);
		e[b].push_back(a);
	}
    for(int i=1; i<=n; i++) if(deg[i]>4) puts("NO"),exit(0);
	dfs(1,0,0,0,50,-1);
	printf("YES\n");
	for (int i=1;i<=n;i++) printf("%lld %lld\n",ansx[i],ansy[i]);
	
}