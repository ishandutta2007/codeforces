#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e5,MOD=1e9+7;
struct SearchTree{
	struct Node{
		vector<int> s;
		int id;
	}t[5005];
	vector<int> k[405];
	int tran[405][32],tran2[405][405];
	int top,top_id;
	inline int new_node(int d){
		++top;
		if(d>-1){
			t[top].s.resize(1<<d+1);
			fill(t[top].s.begin(),t[top].s.end(),0);
		}else 
			t[top].id=++top_id;
		return top;
	}
	void dfs(int& x,int d,vector<int> g){
		if(x==0) x=new_node(d);
		if(d==-1){
			k[t[x].id]=g;
			return;
		}
		dfs(t[x].s[0],d-1,g);
		for(int i=d+1;i<g.size();++i)
			if(g[i]&(1<<d))
				return;
		for(int j=(1<<d);j<(1<<d+1);++j){
			vector<int> f=g; f[d]=j;
			dfs(t[x].s[j],d-1,f);
		}
	}
	int search(vector<int> a){
		int x=1;
		for(int i=4;i>=0;--i)
			x=t[x].s[a[i]];
		if(x==0){
			for(int i=0;i<=4;++i){
				for(int j=0;j<=4;++j)
					if(a[i]&(1<<j))
						putchar('1');
					else putchar('0');
				puts("");
			}
			assert(0);
		}
		return t[x].id;
	}
	pair<bool,vector<int> > add(vector<int> a,int x){
		for(int i=4;i>=0;--i)
			if(x&(1<<i)){
				if(a[i]==0){
					a[i]=x;
					for(int j=i-1;j>=0;--j)
						if(a[i]&(1<<j)) a[i]^=a[j];
					for(int j=i+1;j<=4;++j)
						if(a[j]&(1<<i)) a[j]^=a[i];
					return make_pair(true,a);
				}else x^=a[i];
			}
		return make_pair(false,vector<int>());
	}
	SearchTree(){
		top=top_id=0;
		vector<int> g; g.resize(5);
		int rt=0; dfs(rt,4,g);
//		printf("<%d>\n",top_id);
		for(int i=1;i<=top_id;++i){
			for(int j=0;j<32;++j){
				auto x=add(k[i],j);
				if(x.first==false) tran[i][j]=0;
				else tran[i][j]=search(x.second);
			}
		}
		memset(tran[0],0,sizeof(tran[0]));
		for(int i=0;i<=top_id;++i)
			for(int j=0;j<=top_id;++j){
				int y=i;
				for(auto x:k[j])
					if(x!=0)
						y=tran[y][x];
				tran2[i][j]=j==0?0:y;
			}
	}
}ss;
int s[MAX_N],mark[MAX_N],ti=0;
unordered_map<int,int> e[MAX_N];
void dfs(int x,int pre,int& type,vector<int>& p){
	mark[x]=++ti;
	p.push_back(x);
	for(auto y:e[x])
		if(y.first!=1&&y.first!=pre){
			if(mark[y.first]){
				if(mark[y.first]<mark[x]){
//					printf("<%d %d %d>",x,y.first,s[x]^s[y.first]^y.second);
					type=ss.tran[type][s[x]^s[y.first]^y.second];
				}
			}else{
				s[y.first]=s[x]^y.second;
				dfs(y.first,x,type,p);
			}
		}
}
inline void mo(int& x){ x>=MOD?x-=MOD:0; }

int main(){
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y,w; scanf("%d%d%d",&x,&y,&w);
		e[x][y]=e[y][x]=w;
	}
	vector<int> p,tag,ex; p.resize(1); tag.resize(1); ex.resize(1);
	for(int i=2;i<=n;++i)
		if(!mark[i]){
			int type=1;
			vector<int> g;
			s[i]=0;
			dfs(i,0,type,g);
			for(auto x:g)
				if(e[1].find(x)!=e[1].end()){
					p.push_back(e[1][x]^s[x]);
					ex.push_back(type);
				}
			if(tag.size()<p.size()){
				while(tag.size()<(int)p.size()-1) tag.push_back(0);
				tag.push_back(1);
			}
		}
//	for(int i=1;i<p.size();++i) printf("(%d %d %d)",p[i],tag[i],ex[i]);
	vector<vector<int> > f;
	f.resize(p.size());
	for(int i=0;i<f.size();++i) f[i].resize(ss.top_id+1);
	f[0][1]=1; tag[0]=1;
	for(int i=1;i<p.size();++i){
		for(int j=i-1;j>=0;--j){
			if(tag[j]){
				for(int k=0;k<f[i].size();++k){
					mo(f[i][ss.tran2[k][ex[i]]]+=f[j][k]);
//					if(f[j][k]>0) printf("<%d>",ss.tran2[k][ex[i]]);
				}
				break;
			}else{
				for(int k=0;k<f[i].size();++k)
					mo(f[i][ss.tran[k][p[i]^p[j]]]+=f[j][k]);
			}
		}
		if(tag[i]){
			for(int j=i-1;j>=0;--j){
				for(int k=0;k<f[i].size();++k)
					mo(f[i][k]+=f[j][k]);
				if(tag[j]) break;
			}
		}
	}
	int ans=0;
	for(int k=1;k<f.back().size();++k){
//		if(f.back()[k]>0) printf("[%d]",k);
		mo(ans+=f.back()[k]);
	}
	printf("%d\n",ans);
	return 0;
}