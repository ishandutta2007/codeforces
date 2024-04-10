#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int M=1e9+7;
int n,m,sz[14],dp[14];
vector<int>all;
vector<int>t0[1004],t1[14];
int lb(int x){
	return lower_bound(all.begin(),all.end(),x)-all.begin();
}
void dfs(int x,int fa){
	vector<pii>vec;
	for(auto y:t1[x])if(y!=fa)
		dfs(y,x),vec.push_back({sz[y],dp[y]});
	sort(vec.begin(),vec.end());
	int len=1;dp[x]=1,sz[x]=1;
	for(int i=0;i<vec.size();i++){
		dp[x]|=vec[i].se<<len;
		sz[x]+=vec[i].fi,len+=vec[i].fi*2;
	}
}
map<int,int>visA,visB;
int nA;vector<int>vA[14];
int nB,pos[24];vector<int>vB[24];
int f[1004][24],ans,g[2050];
void calc(int x,int fa){
	for(auto y:t0[x])if(y!=fa)calc(y,x);
	for(int t=0;t<nA;t++){
		vector<int>v=vA[t];int N=v.size();
		memset(g,0,sizeof(g)),g[0]=1;
		for(auto y:t0[x])if(y!=fa){
			for(int i=(1<<N)-1;~i;i--){
				for(int j=0;j<N;j++){
					if((i>>j)&1)continue;
					if(j&&v[j-1]==v[j]&&(!((i>>(j-1))&1)))continue;
					(g[i|(1<<j)]+=(ll)g[i]*f[y][v[j]]%M)%=M;
				}
			}
		}
		(ans+=g[(1<<N)-1])%=M;
	}
	for(int t=0;t<nB;t++){
		vector<int>v=vB[t];int N=v.size();
		memset(g,0,sizeof(g)),g[0]=1;
		for(auto y:t0[x])if(y!=fa){
			for(int i=(1<<N)-1;~i;i--){
				for(int j=0;j<N;j++){
					if((i>>j)&1)continue;
					if(j&&v[j-1]==v[j]&&(!((i>>(j-1))&1)))continue;
					(g[i|(1<<j)]+=(ll)g[i]*f[y][v[j]]%M)%=M;
				}
			}
		}
		f[x][pos[t]]=g[(1<<N)-1];
	}
}
int main(){
//	freopen("trtr.in","r",stdin);
//	freopen("trtr.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		t0[u].push_back(v);
		t0[v].push_back(u);
	}
	scanf("%d",&m);
	for(int i=1;i<m;i++){
		int u,v;scanf("%d%d",&u,&v);
		t1[u].push_back(v);
		t1[v].push_back(u);
	}
	for(int i=1;i<=m;i++)for(auto j:t1[i])
		dfs(i,j),all.push_back(dp[i]);
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=1;i<=m;i++){
		dfs(i,0);
		if(!visA.count(dp[i])){
			for(auto j:t1[i])
				vA[nA].push_back(lb(dp[j]));
			sort(vA[nA].begin(),vA[nA].end());
			++nA,visA[dp[i]]=1;
		}
		for(auto j:t1[i]){
			dfs(i,j);
			if(!visB.count(dp[i])){
				for(auto k:t1[i])if(j!=k)
					vB[nB].push_back(lb(dp[k]));
				sort(vB[nB].begin(),vB[nB].end());
				pos[nB]=lb(dp[i]),++nB,visB[dp[i]]=1;
			}
		}
	}
	calc(1,0);
	printf("%d",ans);
}