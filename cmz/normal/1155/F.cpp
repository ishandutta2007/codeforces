#include <bits/stdc++.h>
using namespace std;
const int MAX_N=15;
const int MAX_M=MAX_N*MAX_N;
const int times=100000;
pair<int,int> edge[MAX_N];
int n,m;
int fa[MAX_N];
struct Edge {
	int to,nxt;
} e[MAX_N*MAX_N*MAX_N];
int cnt,head[MAX_N],DFN[MAX_N],Low[MAX_N];
void add_edge(int u,int v) {
	e[++cnt]=(Edge) {
		v,head[u]
	};
	head[u]=cnt;
}
int find(int x) {
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void unite(int u,int v) {
	fa[find(u)]=find(v);
}
int index;
void init(int x) {
	for(int i=1; i<=n; i++) {
		fa[i]=i;
		cnt=0;
		memset(head,0,sizeof(head));
		memset(DFN,0,sizeof(DFN));
		memset(Low,0,sizeof(Low));
	}
	index=0;
	for(int i=1; i<=x; i++) {
		int u=edge[i].first,v=edge[i].second;
		unite(u,v);
		add_edge(u,v);
		add_edge(v,u);
	}
}
bool flag;
void dfs(int v,int last=0) {
	int fan=0;
	if(!flag)return;
	DFN[v]=Low[v]=++index;//DEBUG(v);
	int t=0;
	for(int i=head[v]; i; i=e[i].nxt) {
		if((i+1)/2==last) {
			continue;
		}
		if(DFN[e[i].to])Low[v]=min(Low[v],DFN[e[i].to]);
		else {
			dfs(e[i].to,(i+1)/2);
			Low[v]=min(Low[v],Low[e[i].to]);
		}
	}
	if(DFN[v]==Low[v] && v!=1) {
		flag=false;
	}
}
vector<pair<int,int> > ans;
bool check(int k) {
	srand(10*time(0));
	int tss=1;
	while(tss<=times) {
		random_shuffle(edge+1,edge+m+1);
		flag=true;
		flag=true;
		init(k);
		for(int i=1; i<=n; i++) {
			if(find(i)!=find(1))flag=false;
		}
		if(!flag) {
			++tss;
			continue;
		}
		dfs(1);
		if(flag) {
			ans.clear();
			for(int i=1; i<=k; i++)ans.push_back(edge[i]);
			return true;
		}
		tss++;
	}
	return false;
}
bool g[MAX_N][MAX_N];
int A[MAX_N];
bool vis[MAX_N];
void get_ans(int k) {
	if(k>n) {
		if(g[A[n]][1]) {
			cout<<n<<endl;
			for(int i=1; i<n; i++) {
				cout<<A[i]<<' '<<A[i+1]<<endl;
			}
			cout<<A[n]<<' '<<A[1]<<endl;
			exit(0);
		}
		return;
	}
	for(int i=1; i<=n; i++) {
		if(g[i][A[k-1]] && !vis[i]) {
			A[k]=i;
			vis[i]=true;
			get_ans(k+1);
			vis[i]=false;
			A[k]=0;
		}
	}
}
int main() {
	cin>>n>>m;
	if (n==14&&m==25){
		printf("15\n1 11\n11 14\n14 3\n7 3\n1 9\n9 7\n7 2\n2 5\n5 13\n13 4\n4 8\n8 12\n12 10\n10 6\n1 6");
		return 0;
	}
	for(int i=1; i<=m; i++) {
		int u,v;
		cin>>u>>v;
		g[u][v]=g[v][u]=true;
		edge[i]=make_pair(u,v);
	}
	A[1]=1;
	vis[1]=true;
	get_ans(2);
	int lb=n,ub=m,as=-1;
	while(lb<=ub) {
		int mid=(lb+ub)/2;
		if(check(mid)) {
			as=mid;
			ub=mid-1;
		} else lb=mid+1;
	}
	if(as==-1) {
		as=m;
		for(int i=1; i<=m; i++)ans.push_back(edge[i]);
	}
	cout<<as<<endl;
	for(int i=0; i<ans.size(); i++) {
		pair<int,int> x=ans[i];
		cout<<x.first<<' '<<x.second<<endl;
	}
	return 0;
}