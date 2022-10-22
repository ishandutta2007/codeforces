#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
int a[N],n;
vector<pair<int,int> > ret;
void opera(int x,int y){
	swap(a[x],a[y]);
	a[x]*=-1;
	a[y]*=-1;
	ret.push_back(make_pair(x,y));
}
bool vis[N];
void find_ring(vector<int>& s,int x){
	if(vis[x]) return;
	vis[x]=1;
	s.push_back(x);
	find_ring(s,a[x]);
}
void solve(vector<int> a,vector<int> b){
	opera(a[0],b[0]);
	for(int i=1;i<a.size();++i) opera(b[0],a[i]);
	for(int i=1;i<b.size();++i) opera(a[0],b[i]);
	opera(a[0],b[0]);
}
bool check(){
	for(int i=1;i<=n;++i)
		if(a[i]!=i) return false;
	return true;
}
bool dfs(int cnt){
	if(cnt>n+1) return false;
	if(check()) return true;
	for(int x=1;x<=n;++x)
		for(int y=x+1;y<=n;++y){
			opera(x,y);
			if(dfs(cnt+1)){
				printf("<%d %d>",x,y);
				return true;
			}
			opera(x,y);
		}
	return false;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	vector<vector<int> > g;
	for(int i=1;i<=n;++i){
		if(a[i]!=i){
			vector<int> s;
			find_ring(s,i);
			if(!s.empty())
				g.push_back(s);
		}
	}
	while(g.size()>1){
		solve(g[(int)g.size()-1],g[(int)g.size()-2]);
		g.pop_back(); g.pop_back();
	}
	if(g.size()>0){
		vector<int> f=g[0];
		if(f.size()<n){
			int pos=1;
			for(;;++pos)
				if(a[pos]==pos)
					break;
			solve(f,vector<int>({pos}));
		}else{
			for(int i=1;i+1<f.size();++i){
				opera(f[0],f[i]);
			}
			opera(f[1],f[(int)f.size()-1]);
			opera(f[0],f[(int)f.size()-1]);
			opera(f[0],f[1]);
		}
	}
	printf("%d\n",(int)ret.size());
	for(auto x:ret) printf("%d %d\n",x.first,x.second);
	return 0;
}