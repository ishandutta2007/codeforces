#include<bits/stdc++.h>
using namespace std;
int maxans=314000000;
int n,m,a[100003],asked[100003],minn[100003];
vector<int>sp[100003],con[100003],v[100003];
bool inf[100003],vis[100003],ban[100003];
struct scc{
	vector<int>g[100003],rg[100003],V;
	int col[100003],cntt,idx[100003];
	bool used[100003]; 
	void addedge(int x,int y){
		g[x].push_back(y);
		rg[y].push_back(x);
	}
	void dfs(int x){
		used[x]=1;
		for(int i=0;i<g[x].size();i++)
			if(!used[g[x][i]])
				dfs(g[x][i]);
		V.push_back(x);
	}
	void rdfs(int x,int k){
		used[x]=1;col[x]=k;
		for(int i=0;i<rg[x].size();i++)
			if(!used[rg[x][i]])
				rdfs(rg[x][i],k);
	}
	void calc(){
		memset(used,0,sizeof(used));
		cntt=0;V.clear();
		for(int i=0;i<m;i++)
			if(!used[i])
				dfs(i);
		memset(used,0,sizeof(used));
		cntt=0;
		for(int i=V.size()-1;i>=0;i--)
			if(!used[V[i]])
				rdfs(V[i],cntt++);
	}
}gr;
int cntcol[100003],maxn[100003],nwD[100003];
bool ok[100003];
void calcok(int x){ok[x]=1;
	for(int i=0;i<con[x].size();i++)
		if(!ok[a[con[x][i]]])
			calcok(a[con[x][i]]);
}
bool usede[100003],usedp[100003];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%d",a+i); 
		a[i]--;
		v[a[i]].push_back(i);
		int cntt;
		scanf("%d",&cntt);
		while(cntt--){
			int x;
			scanf("%d",&x);
			if(x>0){
				x--;
				asked[i]++;
				con[x].push_back(i);
			}
			sp[i].push_back(x);
		}
	}
	vector<int>nw;
	for(int i=0;i<n;i++)
		if(asked[i]==0)
			if(!vis[a[i]]){
				nw.push_back(a[i]);
				vis[a[i]]=1;
			}
	while(nw.size()){
		int x=nw.back();nw.pop_back();
		for(int i=0;i<con[x].size();i++){
			asked[con[x][i]]--;
			if(!asked[con[x][i]])
				if(!vis[a[con[x][i]]]){
					nw.push_back(a[con[x][i]]);
					vis[a[con[x][i]]]=1;
				}
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<sp[i].size();j++)
			if(sp[i][j]!=-1&&!vis[sp[i][j]])
				ban[i]=1;
	for(int i=0;i<n;i++)
		if(!ban[i])
			for(int j=0;j<sp[i].size();j++){
				if(sp[i][j]!=-1)
					gr.addedge(a[i],sp[i][j]);
				if(sp[i][j]==a[i])
					ok[a[i]]=1;
			}
	gr.calc();
	for(int i=0;i<m;i++)
		if(vis[i])
			cntcol[gr.col[i]]++;
	for(int i=0;i<m;i++)
		if(cntcol[gr.col[i]]>1)
			ok[i]=1;
	for(int i=0;i<m;i++)con[i].clear();
	for(int i=0;i<n;i++){
		if(ban[i])continue;
		for(int j=0;j<sp[i].size();j++)
			if(sp[i][j]!=-1)
				con[sp[i][j]].push_back(i);
	}
	for(int i=0;i<m;i++)
		if(ok[i]&&vis[i])
			calcok(i);
	vector<int>ord;
	for(int i=0;i<gr.V.size();i++)
		if(vis[gr.V[i]]&&!ok[gr.V[i]])
			ord.push_back(gr.V[i]);
	for(int i=0;i<ord.size();i++){
		int res=0;
		long long nwcnt;
		for(int j=0;j<v[ord[i]].size();j++){
			if(ban[v[ord[i]][j]])continue;
			nwcnt=0;
			for(int k=0;k<sp[v[ord[i]][j]].size();k++)
				if(sp[v[ord[i]][j]][k]==-1)
					nwcnt++;
				else
					nwcnt+=maxn[sp[v[ord[i]][j]][k]];
			nwcnt=min(nwcnt,1ll*maxans);
			res=max(1ll*res,nwcnt);
		}
		maxn[ord[i]]=res;
	}
	memset(asked,0,sizeof(asked));
	for(int i=0;i<n;i++)
		for(int j=0;j<sp[i].size();j++)
			if(sp[i][j]!=-1)
				asked[i]++;
			else
				nwD[i]++;
	for(int i=0;i<m;i++)minn[i]=maxans;
	for(int i=0;i<n;i++)
		if(asked[i]==0)
			minn[a[i]]=min(minn[a[i]],int(sp[i].size()));
	priority_queue<pair<int,int> >Q;
	for(int i=0;i<m;i++)
		if(minn[i]!=maxans)
			Q.push(make_pair(-minn[i],i));
	while(Q.size()){
		int nw=Q.top().second,len=-Q.top().first;Q.pop();
		if(len!=minn[nw])continue;
		for(int i=0;i<con[nw].size();i++){
			asked[con[nw][i]]--;
			nwD[con[nw][i]]=min(nwD[con[nw][i]]+len,maxans);
			if(asked[con[nw][i]]==0)
				if(nwD[con[nw][i]]<minn[a[con[nw][i]]])
					minn[a[con[nw][i]]]=nwD[con[nw][i]],
					Q.push(make_pair(-minn[a[con[nw][i]]],a[con[nw][i]]));
		}
	}
	for(int i=0;i<m;i++)
		if(!vis[i])
			printf("-1 -1\n");
		else{
			printf("%d ",minn[i]);
			if(!ok[i])
				printf("%d\n",maxn[i]);
			else
				printf("-2\n");
		}
}