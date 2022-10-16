#include<bits/stdc++.h>
using namespace std;
struct edge{
	int to,cap;
	long long cst;
	int rev,idx;
};
vector<edge>g[2003];
void add_edge(int x,int y,int cap,long long cst,int idx){
	g[x].push_back((edge){y,cap,cst,g[y].size(),idx});
	g[y].push_back((edge){x,0,-cst,g[x].size()-1,idx});
}
int prevv[2003],preve[2003];
long long dist[2003];
long long min_cost_flow(int s,int t,int F){
	long long ret=0;
	while(F){
		memset(dist,31,sizeof(dist));
		priority_queue<pair<long long,int> >Q;
		dist[s]=0;
		Q.push(make_pair(0,s));
		while(Q.size()){
			long long len=-Q.top().first;
			int nw=Q.top().second;Q.pop();
			if(dist[nw]<len)continue;
			for(int i=0;i<g[nw].size();i++){
				edge &e=g[nw][i];
				if(e.cap>0&&dist[e.to]>dist[nw]+e.cst)
					dist[e.to]=dist[nw]+e.cst,
					prevv[e.to]=nw,preve[e.to]=i,
					Q.push(make_pair(-dist[e.to],e.to));
			}
		}
		if(dist[t]>=0)break;
		int f=F;
		for(int v=t;v!=s;v=prevv[v])
			f=min(f,g[prevv[v]][preve[v]].cap);
		ret+=1ll*f*dist[t];F-=f;
		for(int v=t;v!=s;v=prevv[v]){
			edge &e=g[prevv[v]][preve[v]];
			e.cap-=f,g[v][e.rev].cap+=f;
		}
	}return ret;
}
map<int,int>mp;
int n,k,ans,a[26],x[253];
bool ok[253],rd[26],f[253];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		ans+=__builtin_popcount(x[i]);
		if(mp[x[i]])
			if(i!=mp[x[i]]+1){
				add_edge(mp[x[i]]+1,i,1,-__builtin_popcount(x[i]),i);
			}
			else
				ok[i]=1,ans-=__builtin_popcount(x[i]); 
		mp[x[i]]=i;
	}
	for(int i=1;i<n;i++)
		add_edge(i,i+1,2333,0,-1);
	ans+=min_cost_flow(1,n,k-1);
	for(int i=1;i<=n;i++)
		for(int j=0;j<g[i].size();j++)
			if(g[i][j].idx>0&&g[i][j].to>i)
				if(g[i][j].cap==0){
					ok[g[i][j].idx]=1;
					f[i-1]=1;
				}
	int cntt=0;
	for(int i=1;i<=n;i++)
		if(!ok[i])
			cntt++;
	cout<<cntt+n<<' '<<ans<<endl;
	for(int i=1;i<=n;i++){
		if(!ok[i])
			for(int j=0;j<k;j++)
				if(!rd[j]){
					cout<<char(j+'a')<<'='<<x[i]<<endl,a[j]=x[i];
					break;
				}
		for(int j=0;j<26;j++)
			if(a[j]==x[i]){
				cout<<"print("<<char(j+'a')<<")\n";
				rd[j]=f[i];
				break;
			}
	}
}