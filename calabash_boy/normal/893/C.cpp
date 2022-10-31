#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
int first[maxn],des[maxn],nxt[maxn],tot;
int a[maxn];
bool vis[maxn];
int m,n;
long long ans;
inline void addEdge(int x,int y){
	tot++;
	des[tot] =y;
	nxt[tot] = first[x];
	first[x] = tot;
}
void input(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",a+i);
	} 
	for (int i=0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
}
void flood(int start){
	queue<int>Q;
	Q.push(start);
	vis[start] = 1;
	int res = a[start];
	while (!Q.empty()){
		int q = Q.front();Q.pop();
		for (int t = first[q];t;t=nxt[t]){
			int v = des[t];
			if (vis[v])continue;
			vis[v] = true;
			res = min(res,a[v]);
			Q.push(v);
		}
	}
	ans+=res;
}
void solve(){
	for (int i=1;i<=n;i++){
		if (!vis[i])flood(i);
	}
	cout<<ans<<endl;
}
int main(){
	input();
	solve();
	return 0;
}