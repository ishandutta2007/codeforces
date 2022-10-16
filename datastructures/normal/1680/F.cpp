#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int t,n,m,u[2000005],v[2000005],first[1000005],nxt[2000005];
int fa[1000005],depth[1000005];
vector<int> e[1000005];
int tot,x[1000005],y[1000005]; 
int ch1[1000005],ch2[1000005];
int col[1000005];
void dfs1(int now,int f,int d){
	fa[now]=f,depth[now]=d;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==f)continue;
		if (depth[v[i]]==0){
			e[now].push_back(v[i]);
			dfs1(v[i],now,d+1);
		}
		else if (depth[v[i]]<depth[now]){
			++tot;
			x[tot]=now,y[tot]=v[i];
		}
	}
	return;
}
void dfs2(int now,int fa){
	for (int i=0;i<(int)e[now].size();i++){
		if (e[now][i]==fa)continue;
		dfs2(e[now][i],now);
		ch1[now]+=ch1[e[now][i]],ch2[now]+=ch2[e[now][i]]; 
	}
	return;
}
void dfs3(int now){
	for (int i=first[now];i;i=nxt[i]){
		if (col[v[i]]!=-1)continue;
		col[v[i]]=col[now]^1;
		dfs3(v[i]);
	}
	return;
}
int main(){
	t=read();
	memset(col,-1,sizeof(col));
	while(t--){
		n=read(),m=read();
		for (int i=1;i<=m;i++){
			u[i]=read(),v[i]=read();
			nxt[i]=first[u[i]],first[u[i]]=i;
			u[i+m]=v[i],v[i+m]=u[i];
			nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
		}
		dfs1(1,0,1);
		int cnt=0;
		for (int i=1;i<=tot;i++){
			if ((depth[x[i]]-depth[y[i]])%2==0)cnt++,ch1[x[i]]++,ch1[y[i]]--;
			else ch2[x[i]]++,ch2[y[i]]--;
		}
		dfs2(1,0);
		int fg=0;
		if (cnt==0){
			col[1]=1;
			dfs3(1);
			fg=1;
		} 
		else if (cnt==1){
			for (int i=1;i<=tot;i++){
				if ((depth[x[i]]-depth[y[i]])%2==0){
					col[x[i]]=col[y[i]]=1;
					dfs3(x[i]);
					dfs3(y[i]);
					fg=1;
					break;
				}
			}			
		}
		else{
			for (int i=2;i<=n;i++)
				if (ch1[i]==cnt&&ch2[i]==0){
					col[i]=col[fa[i]]=1;
					dfs3(i);
					dfs3(fa[i]);
					fg=1;
					break;
				}
		}
		if (fg==0)puts("NO");
		else{
			puts("YES");
			for (int i=1;i<=n;i++)putchar('0'+col[i]);
			puts(""); 
		}
		memset(first,0,sizeof(int)*(n+1));
		memset(nxt,0,sizeof(int)*(2*m+1));
		memset(fa,0,sizeof(int)*(n+1));
		memset(depth,0,sizeof(int)*(n+1));
		for (int i=1;i<=n;i++)e[i].clear();
		tot=0;
		memset(ch1,0,sizeof(int)*(n+1));
		memset(ch2,0,sizeof(int)*(n+1));
		memset(col,-1,sizeof(int)*(n+1));
	}
	return 0;
}