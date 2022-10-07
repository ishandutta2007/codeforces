#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,s;
vector<int> e[N+5];
int pre[N+5],f[N+5];
int q[N+5],qr;
int p[N+5],ps;
void bfs(){
	q[qr=1]=s;
	for(int i=1;i<=qr;i++){
		int u=q[i];
		for(auto v:e[u]){
			if(v==s) continue;
			if(!pre[v]){
				pre[v]=u;
				if(u==s) f[v]=v;
				else f[v]=f[u];
				q[++qr]=v;
			}
			else if(v!=s&&f[v]!=f[u]){
				puts("Possible");
				for(int i=v;i;i=pre[i]) p[++ps]=i;
				printf("%d\n",ps);
				for(int i=ps;i;i--)
					printf("%d ",p[i]);
				puts("");
				ps=1;
				for(int i=u;i;i=pre[i]) p[++ps]=i;
				printf("%d\n",ps);
				for(int i=ps;i;i--)
					printf("%d ",p[i]);
				puts("");
				exit(0);
			}
		}
	}
}
int main(){
	scanf("%d %d %d",&n,&m,&s);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d %d",&u,&v);
		e[u].emplace_back(v);
	}
	bfs();
	puts("Impossible");
	return 0;
}