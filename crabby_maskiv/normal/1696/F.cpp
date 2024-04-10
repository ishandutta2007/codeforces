#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=100+5;
int n,m;
bitset<N> b[N][N];
int d[N][N];
vector<int> g[N];
int fu,fv;
void finde(vector<int> a){
	if(a.size()==2){
		fu=a[0];fv=a[1];
		return;
	}
	//cerr<<"a : ";
	//for(auto x:a) cerr<<x<<" ";cerr<<endl;
	int x=-1,y=-1,i,j,t=a.size();
	bitset<N> f;f.reset();
	for(i=0;i<t;i++) f[a[i]]=1;
	for(i=0;i<t;i++){
		for(j=i+1;j<t;j++){
			if((f&b[a[i]][a[j]]).count()>1){
				x=a[i];y=a[j];f&=b[x][y];
				break;
			}
		}
		if(x!=-1) break;
	}
	if(x==-1){
		f.reset();
		for(i=0;i<t;i++){
			for(j=i+1;j<t;j++){
				f|=b[a[i]][a[j]];
			}
		}
		for(i=0;i<t;i++){
			if(!f[a[i]]){
				x=a[i];
				break;
			}
		}
		if(x==-1) return;
		vector<int> c;
		for(i=0;i<t;i++)
			if(a[i]!=x) c.push_back(a[i]);
		finde(c);
	}
	else{
		vector<int> c;
		for(i=1;i<=n;i++)
			if(f[i]) c.push_back(i);
		if(c.size()==a.size()) return;
		finde(c);	
	}
}
bool vis[N];
void dfs(int *dis,int u,int fa){
	for(auto v:g[u]){
		if(v==fa) continue;
		dis[v]=dis[u]+1;
		dfs(dis,v,u);
	}
}
inline bool check(){
	int i,j,k;
	for(i=1;i<=n;i++){
		d[i][i]=0;
		dfs(d[i],i,0);
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			for(k=1;k<=n;k++)
				if((d[i][k]==d[j][k])!=b[i][j][k]) return 0;
	return 1;
}
void solve(){
	vector<int> a(n);
	int i,j,k;
	for(i=0;i<n;i++) a[i]=i+1;
	fu=-1;fv=-1;
	finde(a);
	if(fu==-1){
		cout<<"No"<<endl;
		return;
	}
	if(b[fu][fv][fu]||b[fu][fv][fv]){
		cout<<"No"<<endl;
		return;
	}
	queue<pii> q;
	vis[fu]=vis[fv]=1;
	q.push({fu,fv});
	q.push({fv,fu});
	g[fu].push_back(fv);
	g[fv].push_back(fu);
	while(!q.empty()){
		int u=q.front().fr,v=q.front().sc;q.pop();
		for(i=1;i<=n;i++){
			if(vis[i]) continue;
			if(b[u][i][v]){
				vis[i]=1;
				g[v].push_back(i);
				g[i].push_back(v);
				q.push({v,i});
			}
		}
	}
	for(i=1;i<=n;i++){
		if(!vis[i]){
			cout<<"No"<<endl;
			return;
		}
	}
	if(!check()){
		cout<<"No"<<endl;
		return;
	}
	cout<<"Yes"<<endl;
	for(i=1;i<=n;i++){
		for(auto v:g[i])
			if(i<v) cout<<i<<" "<<v<<endl;
	}
}
int main(){
	//freopen("test.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j,k;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				string s;cin>>s;
				for(k=1;k<=n;k++)
					b[i][j][k]=b[j][i][k]=(s[k-1]=='1');
			}
		}
		solve();
		for(i=1;i<=n;i++) g[i].clear();
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				b[i][j].reset();
		for(i=1;i<=n;i++) vis[i]=0;
	}
	return 0;
}