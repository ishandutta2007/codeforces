#include<bits/stdc++.h>
#define ll long long
using namespace std;

int T;
int N,K;
vector<int> G[500005],val[500005];
bool cmp(int a,int b){
	return a>b;
}
ll F[500005][2];
vector<int> tmp;
void Solve(int u,int fa){
	F[u][0]=F[u][1]=0;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i],w=val[u][i];
		if(v==fa) continue;
		Solve(v,u);
	}
	tmp.clear();
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i],w=val[u][i];
		if(v==fa) continue;
		F[u][0]+=F[v][0];F[u][1]+=F[v][0];
		tmp.push_back(F[v][1]-F[v][0]+w);
	}
	sort(tmp.begin(),tmp.end(),cmp);
	for(int i=0;i<K&&i<tmp.size();i++){
		if(tmp[i]<=0) break;
		F[u][0]+=tmp[i];
		if(i<K-1) F[u][1]+=tmp[i];
	}
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&K);
		for(int i=1;i<=N;i++) G[i].clear(),val[i].clear();
		for(int i=1;i<N;i++){
			int u,v,w;scanf("%d%d%d",&u,&v,&w);
			G[u].push_back(v);val[u].push_back(w);
			G[v].push_back(u);val[v].push_back(w);
		}
		Solve(1,0);
		printf("%lld\n",F[1][0]);
	}
}