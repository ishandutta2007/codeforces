#include<bits/stdc++.h>
//#pragma comment(linker, "/STACK:16000000")
using namespace std;
int n,m;
vector<pair<int,int> >neigh[100005];
int zdis[100005],bfsdis[100005],zpar[100005],bfspar[100005];
pair<int,int>par[100005];
set<int>s,ns;
void bfs(int v,int dis[],int par[],bool zer){
	bool ok[10]={};ok[0]=1;
	if(!zer)fill(ok+1,ok+10,1);
	fill(dis, dis + n, 1000000007); dis[v] = 0;
	queue<int>q;q.push(v);
	while(!q.empty()){
		int v=q.front();q.pop();
		for(int i=0;i<neigh[v].size();i++){
			pair<int,int>u=neigh[v][i];
			if(ok[u.second]&&dis[v]+1<dis[u.first])
				dis[u.first]=dis[v]+1,
				par[u.first]=v,
				q.push(u.first);
		}
	}
}
int main(){
	cin>>n>>m;
	while(m--){
		int a,b,len;
		cin>>a>>b>>len;
		neigh[a].push_back(make_pair(b,len));
		neigh[b].push_back(make_pair(a,len));
	} 
	bfs(n-1,zdis,zpar,1);
	bfs(0,bfsdis,bfspar,0);
	int rlen=1000000007;
	for(int i=0;i<n;i++)
		if(i==n-1||zdis[i]<1000000007)
			if(bfsdis[i]<rlen)
				rlen=bfsdis[i];
	fill(par,par+n,make_pair(1000000007,0));
	for(int i=0;i<n;i++)
		if(i==n-1||zdis[i]<1000000007)
			if(bfsdis[i]==rlen){
				par[i]=make_pair(zdis[i],i);
				s.insert(i);
			}
	for(int i=0;i<rlen;i++){
		ns.clear();
		int best=10;
		for(set<int>::iterator it=s.begin();it!=s.end();it++)
			for(int j=0;j<neigh[*it].size();j++){
				pair<int,int>u=neigh[*it][j];
				if(bfsdis[*it]-1!=bfsdis[u.first])continue;
				if(u.second<best){best=u.second;ns.clear();}
				if(u.second==best)
					if(ns.find(u.first)!=ns.end())
						par[u.first]=min(par[u.first],make_pair(par[*it].first,*it));
					else
						ns.insert(u.first),
						par[u.first]=make_pair(par[*it].first,*it);
			}
		cout<<best;
		s=ns;
	}
	if(rlen==0)cout<<0;
	cout<<endl;
	int tlen=rlen+par[0].first,v=0;
	cout<<tlen+1<<endl;
	for(int i=0;i<rlen;i++)cout<<v<<' ',v=par[v].second;
	for(int i=0;i<tlen-rlen;i++)cout<<v<<' ',v=zpar[v];
	cout<<v; 
}