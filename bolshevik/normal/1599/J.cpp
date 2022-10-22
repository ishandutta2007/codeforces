#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int o=1e6+10;
int n,b[o],m;bool vis[o],flg;vector<int> st[2],vec;map<int,vector<int> > mp;
inline void slv(int x,int y,int z){
	int t=(x+y+z)/2;
	printf("YES\n");
	printf("%d %d %d ",t-x,t-y,t-z);
	vis[x]=vis[y]=vis[z]=1;
	for(int i=1;i<=n;++i) if(!vis[b[i]]) printf("%d ",b[i]-(t-x));
}
void dfs(int nw,int rem,int sm){
	if(rem>n-nw+1||flg) return;
	if(!rem){
		if(mp.find(sm)!=mp.end()){
			vector<int> t=mp[sm];
			for(int i=vec.size();i--;) vis[vec[i]]=1;
			for(int i=t.size();i--;) vis[t[i]]=1;
			printf("YES\n");
			for(int i=vec.size(),v=0;i--;) printf("%d ",v),v=vec[i]-v,printf("%d ",v),v=t[i]-v;
			for(int i=1;i<=n;++i) if(!vis[b[i]]) printf("%d ",b[i]);
			flg=1;
			return;
		}
		mp[sm]=vec;
		return;
	}
	dfs(nw+1,rem,sm);vec.push_back(b[nw]);dfs(nw+1,rem-1,sm+b[nw]);vec.pop_back();
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	sort(b+1,b+n+1);m=unique(b+1,b+n+1)-b-1;
	if(m<n){
		printf("YES\n");
		for(int i=1;i<=m;++i) printf("%d ",b[i]);
		for(int i=m+1;i<=n;++i) printf("0 ");
		return 0;
	}
	for(int i=1;i<=n;++i) st[b[i]&1].push_back(b[i]);
	if(st[0].size()>2ull){slv(st[0][0],st[0][1],st[0][2]);return 0;}
	if(st[0].size()&&st[1].size()>1ull){slv(st[0][0],st[1][0],st[1][1]);return 0;}
	for(int i=2;i<=n/2&&!flg;++i) mp.clear(),dfs(1,i,0);
	if(!flg) printf("NO");
	return 0;
}