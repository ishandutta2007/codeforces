#include<bits/stdc++.h>
using namespace std;
#define N 105
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,col[N],fa[N],dis[N][N];
char s[N][N][N];
vector<int> G[N];
int Find(int x,int y){
	for(int k=1;k<=n;++k){
		if(s[x][y][k]=='1')return 1;
	}
	return 0;
}
class Union_Set{
public:
	int f[N];
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
	}
	void Merge(int x,int y){
		x=getf(x),y=getf(y);
		if(x==y)return;
		f[y]=x;
	}
}S;
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			cin>>(s[i][j]+1);
			for(int k=1;k<=n;++k){
				s[j][i][k]=s[i][j][k];
			}
		}
	}
	col[1]=0;
	for(int i=2;i<=n;++i){
		col[i]=!Find(1,i);
	}
	for(int i=2;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(Find(i,j)!=(col[i]==col[j])){
				cout<<"No\n";
				return;
			}
		}
	}
	S.init(n);
	for(int i=2;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(s[i][j][1]=='1'){
				S.Merge(i,j);
			}
		}
	}
	for(int i=2;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(S.getf(i)==S.getf(j)&&col[i]^col[j]){
				cout<<"No\n";
				return;
			}
		}
	}
	vector<int> bel(n+1);
	vector<vector<int> > all;
	for(int i=2;i<=n;++i){
		if(S.getf(i)==i){
			bel[i]=all.size();
			all.push_back(vector<int>({}));
		}
	///	cerr<<" ?? "<<i<<" "<<S.getf(i)<<" "<<col[i]<<endl;
	}
	for(int i=2;i<=n;++i){
		all[bel[S.getf(i)]].push_back(i);
	}
	auto bfs=[&](int S,int *dis)->void{
		for(int i=1;i<=n;++i){
			dis[i]=inf;
		}
		dis[S]=0;
		static queue<int> q;
		q.push(S);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto v:G[u]){
				if(dis[v]==inf){
					q.push(v);
					dis[v]=dis[u]+1;
				}
			}
		}
	};
	auto check=[&]()->bool{
		for(int i=1;i<=n;++i)G[i].clear();
		for(int i=2;i<=n;++i){
			G[fa[i]].push_back(i);
			G[i].push_back(fa[i]);
		//	cerr<<" ?? "<<i<<" "<<fa[i]<<endl;
		}
		for(int i=1;i<=n;++i){
			bfs(i,dis[i]);
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				for(int k=1;k<=n;++k){
					if((dis[i][k]==dis[j][k])!=(s[i][j][k]=='1')){
					//	cerr<<" !! "<<i<<" "<<j<<" "<<k<<" "<<dis[i][k]<<" "<<dis[j][k]<<endl;
						return false;
					}
				}
			}
		}
		return true;
	};
	auto Try=[&](int z)->bool{
		vector<bool> vis(all.size());
		for(int i=1;i<=n;++i){
			fa[i]=0;
		}
	//	cerr<<" ----------- z: "<<z<<endl;
		for(auto x:all[z]){
			fa[x]=1;
		}
		int cnt=0;
		for(int o=z;;){
	//		cerr<<" o: "<<o<<endl;
			++cnt;
			vis[o]=1;
			bool zz=0;
			for(int i=0;i<(int)all.size();++i){
				if(vis[i])continue;
				bool ok=0;
				bool wei=0;
				for(auto v:all[i]){
					for(auto u:all[o]){
						if(s[v][fa[u]][u]=='1'){
							ok=1;
							fa[v]=u;
							break;
						}
					}
					if(!fa[v])wei=1;
				}
				if(ok){
					if(wei)return false;
					o=i;
					zz=1;
					break;
				}
			}
			if(!zz)break;
		}
		if(cnt<(int)all.size())return false;
		return check();
	};
	for(int i=0;i<(int)all.size();++i){
		if(Try(i)){
			cout<<"Yes\n";
			for(int j=2;j<=n;++j){
				cout<<j<<' '<<fa[j]<<'\n';
			}
			return;
		}
	}
	cout<<"No\n";
}
int main(){
//	freopen("e.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}