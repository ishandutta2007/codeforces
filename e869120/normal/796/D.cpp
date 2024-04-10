#include<bits/stdc++.h>
using namespace std;
int dist[320000],n,k,d,p,a,b;vector<pair<int,int>>x[320000];bool used[320000];queue<int>Q;
class QuickUnionFind {
private:
	long long size_; std::vector<long long> g; std::vector<std::vector<long long> > v; std::vector<long long> d;
public:
	QuickUnionFind() : size_(0), g(std::vector<long long>()), v(std::vector<std::vector<long long> >()), d(std::vector<long long>()) {};
	QuickUnionFind(long long size__) : size_(size__) {
		g.resize(size_); v.resize(size_); d.resize(size_);
		for (long long i = 0; i < size_; i++) { g[i] = i, v[i] = { i }; d[i] = 1; }
	};
	long long size() { return size_; }
	long long root(long long x) { return g[x]; }
	long long size(long long x) { return d[root(x)]; }
	bool same(long long x, long long y) { return g[x] == g[y]; }
	void unite(long long x, long long y) {
		x = g[x], y = g[y];
		if (x == y) return;
		if (v[x].size() < v[y].size()) std::swap(x, y);
		d[root(x)] += d[root(y)];
		v[x].insert(v[x].end(), v[y].begin(), v[y].end());
		for (auto &e : v[y]) g[e] = x;
		v[y].clear();
	}
	std::vector<long long> connected(long long x) { return v[g[x]]; }
	bool operator==(const QuickUnionFind& u) { return g == u.g; }
	bool operator!=(const QuickUnionFind& u) { return g != u.g; }
};
int main(){
	cin>>n>>k>>d;
	for(int i=1;i<=n;i++)dist[i]=1e9;
	for(int i=1;i<=k;i++){cin>>p;used[p]=true;dist[p]=0;Q.push(p);}
	for(int i=1;i<n;i++){cin>>a>>b;x[a].push_back(make_pair(b,i));x[b].push_back(make_pair(a,i));}
	int T=0;for(int i=1;i<=n;i++){if(used[i]==true)T++;}
	while(!Q.empty()){
		int pos=Q.front();Q.pop();
		for(int i=0;i<x[pos].size();i++){
			if(dist[x[pos][i].first]>dist[pos]+1){Q.push(x[pos][i].first);dist[x[pos][i].first]=dist[pos]+1;}
		}
	}
	cout<<T-1<<endl;
	vector<tuple<int,int,int,int>>G;
	for(int i=1;i<=n;i++){
		for(int j=0;j<x[i].size();j++){
			if(i>x[i][j].first)continue;
			G.push_back(make_tuple(dist[i]+dist[x[i][j].first],i,x[i][j].first,x[i][j].second));
		}
	}
	sort(G.begin(),G.end());
	QuickUnionFind UF(n+1);bool OK=false;
	for(int i=0;i<G.size();i++){
		if(used[get<1>(G[i])]==false || used[get<2>(G[i])]==false){
			UF.unite(get<1>(G[i]),get<2>(G[i]));
			used[get<1>(G[i])]=true;
			used[get<2>(G[i])]=true;
		}
		else{if(OK==true)cout<<" ";cout<<get<3>(G[i]);OK=true;}
	}
	cout<<endl;
	return 0;
}