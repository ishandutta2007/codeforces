#include<bits/stdc++.h>
using namespace std;
void outputno(){
	puts("0");exit(0);
}
int n,K,rt,a,b;
vector<int>g[300004],G[300004],l[300004];
bool visb[300004];
int cnt[300004],cmp[300004],p[300004];
queue<int>que;
void chain(int x){
	cnt[x]++;
	if(cnt[x]==(int)l[x].size())que.push(x);
}
vector<int>ans;
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		if(!p[i])rt=i;
		else g[p[i]].push_back(i);
	}
	for(int i=1;i<=K;i++){
		scanf("%d%d",&a,&b);
		G[a].push_back(b),visb[b]=1;
	}
	for(int i=1;i<=n;i++)if(!visb[i]){
		int cur=i;
		while(1){
			l[i].push_back(cur);
			cmp[cur]=i;
			if(G[cur].empty())break;
			cur=G[cur][0]; 
			if(cmp[p[cur]]==i)cnt[i]++;
		}
	}
	chain(rt);
	while(!que.empty()){
		int u=que.front();que.pop();
		for(auto x:l[u]){
			
			ans.push_back(x);
			for(auto y:g[x])chain(cmp[y]);
		}
	}
	if((int)ans.size()!=n)outputno();
	for(auto x:ans)printf("%d ",x);
}