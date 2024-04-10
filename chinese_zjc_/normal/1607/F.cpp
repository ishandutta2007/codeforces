#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2005,MAXM=4e6+5;
int n,m,to[MAXM];
char s[MAXN];
inline int getid(int x,int y){
	return (x-1)*m+y;
}
int f[MAXM],ans;
bool vis[MAXM],ins[MAXM];
void Dfs(int u){
	if(ins[u]){
		int p=u;
		do{
			vis[p]=1;
			p=to[p];
			f[u]++;
		}while(p!=u);
		p=to[u];
		while(p!=u){
			f[p]=f[u];
			p=to[p];
		}
		return ;
	}
	ins[u]=1;
	if(to[u]&&!vis[to[u]]){
		Dfs(to[u]);
		if(vis[u]){
			ins[u]=0;
			vis[u]=1;
			return ;
		}
	}
	f[u]=f[to[u]]+1;
	ins[u]=0;
	vis[u]=1;
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n*m;++i)
			vis[i]=f[i]=to[i]=0;
		for(int i=1;i<=n;++i){
			cin>>(s+1);
			for(int j=1;j<=m;++j){
				int x=i,y=j;
				if(s[j]=='L')y--;
				if(s[j]=='R')y++;
				if(s[j]=='U')x--;
				if(s[j]=='D')x++;
				if(x>0&&x<=n&&y>0&&y<=m){
					to[getid(i,j)]=getid(x,y);
				}
			}
		}
		ans=1;
		for(int i=1;i<=n*m;++i){
			if(!vis[i]) Dfs(i);
			if(f[i]>f[ans]) ans=i;
		}
		cout<<(ans+m-1)/m<<' '<<(ans-1)%m+1<<' '<<f[ans]<<'\n';
	}
	return 0;
}