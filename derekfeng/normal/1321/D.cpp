#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar()); 
}
int n,m,K,ans1,ans2;
vector<int>g[200004];
int cnt[200004];
int p[200004],dis[200004];
int main(){
	read(n),read(m); 
	for (int i=0;i<m;i++){
		int x,y;read(x),read(y);
		g[y].push_back(x); 
	}
	read(K);
	for (int i=1;i<=K;i++) read(p[i]);
	queue<int>que;que.push(p[K]);
	memset (dis,-1,sizeof(dis));
	dis[p[K]]=0,cnt[p[K]]=1;
	while (!que.empty()){
		int x=que.front();que.pop();
		for (int i=0;i<g[x].size();i++){
			if (dis[g[x][i]]==-1){
				dis[g[x][i]]=dis[x]+1,que.push(g[x][i]),cnt[g[x][i]]=1;  
			}else if (dis[g[x][i]]==dis[x]+1) cnt[g[x][i]]=2;
		}
	}
	for (int i=1;i<K;i++){
		if (dis[p[i+1]]+1==dis[p[i]]){
			ans2+=cnt[p[i]]-1;
		}else ans1++,ans2++;
	}
	cout<<ans1<<" "<<ans2;
}