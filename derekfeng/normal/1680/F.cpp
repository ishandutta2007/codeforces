#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1e6+5;
int n,m,u[N],v[N];
int vs[N];
vector<pii>g[N];
bool dfs(int x,int c){
	vs[x]=c;
	for(auto [y,i]:g[x]){
		if(vs[y]<0){
			if(!dfs(y,c^1))
				return 0;
		}else if(vs[y]!=(c^1))
			return 0;
	}
	return 1;
}
int cnt,d[N],a[N],fr[N],res;
void Dfs(int x,int par){
	d[x]=d[par]+1;
	for(auto [y,i]:g[x]){
		if(par==y)fr[x]=i;
		else if(d[y]){
			if(d[y]<d[x]){
				if((d[x]-d[y])&1)a[x]--,a[y]++;
				else cnt++,res=i,a[y]--,a[x]++;
			}
		}else Dfs(y,x);
	}
}
void DFs(int x,int par){
	d[x]=-1;
	for(auto [y,i]:g[x])
		if(d[y]>0){
			DFs(y,x);
			a[x]+=a[y];
		}
    if(a[x]==cnt)res=fr[x];
}
void sol(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=0;i<m;i++){
		scanf("%d%d",&u[i],&v[i]);
		g[u[i]].push_back({v[i],i});
		g[v[i]].push_back({u[i],i});
	}
	memset(vs,-1,(n+2)<<2);
	if(dfs(1,0)){
		puts("YES");
		for(int i=1;i<=n;i++)putchar(vs[i]+'0');
		puts("");return;
	}
	memset(d,0,(n+2)<<2);
	memset(a,0,(n+2)<<2);
	memset(fr,0,(n+2)<<2);
	cnt=0,res=-1,Dfs(1,0);
	if(cnt)DFs(1,0);
	if(res<0){puts("NO");return;}
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=0;i<m;i++)if(i!=res){
		g[u[i]].push_back({v[i],i});
		g[v[i]].push_back({u[i],i});
	}
	memset(vs,-1,(n+2)<<2);
	if(!dfs(u[res],1)){
		puts("NO");return;
	}
	puts("YES");
	for(int i=1;i<=n;i++)putchar(vs[i]+'0');
	puts("");
}
int main(){
	int tc;scanf("%d",&tc);
	while(tc--)sol();
}