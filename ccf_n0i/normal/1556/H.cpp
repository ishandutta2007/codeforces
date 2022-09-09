#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
const int big=1e6;
vector<pair<int,int> > all;
int ans,cur;
int n,m,i,j,mp[55][55];
int fa[55],deg[6];
int mfa[55],mdeg[6];
int mem[25][55];
int in[305],typ[305],g[305][305],pre[305],val[305],inq[305];
pair<int,int> dis[305];
int fnd(int x){if(fa[x]==x)return x;return fa[x]=fnd(fa[x]);}
void merge(int x,int y){x=fnd(x);y=fnd(y);fa[x]=y;}
vector<pair<int,int> > calc(vector<pair<int,int> > v){
	int i,j,cnt=0;
	memset(in,0,sizeof(in));
	for(;;){
		cnt++;
		memset(inq,0,sizeof(inq));
		memcpy(fa,mfa,sizeof(fa));
		memcpy(deg,mdeg,sizeof(deg));
		rep0(i,v.size()) if(in[i]){merge(v[i].first,v[i].second);if(v[i].first<=m)deg[v[i].first]--;}
		rep0(i,v.size()){
			if(in[i])typ[i]=0;
			else{
				int sx=(fnd(v[i].first)!=fnd(v[i].second));
				int sy=(v[i].first>m||deg[v[i].first]);
				typ[i]=sx+sy*2;
			}
		}
		if(i<v.size())continue;
		rep0(i,v.size())if(in[i]){
			memcpy(fa,mfa,sizeof(fa));
			memcpy(deg,mdeg,sizeof(deg));
			rep0(j,v.size())if(i!=j&&in[j]){merge(v[j].first,v[j].second);if(v[j].first<=m)deg[v[j].first]--;}
			rep0(j,v.size())if(!in[j]){
				int sx=(fnd(v[j].first)!=fnd(v[j].second));
				int sy=(v[j].first>m||deg[v[j].first]);
				g[i][j]=sx;
				g[j][i]=sy;
			}
		}
		queue<int> qx;
		rep0(i,v.size()){
			dis[i]=make_pair(0x3f3f3f3f,0x3f3f3f3f);
		}
		rep0(i,v.size()){
			if(in[i]){
				val[i]=-mp[v[i].first][v[i].second];
			}
			else{
				val[i]=mp[v[i].first][v[i].second];
			}
		}
		rep0(i,v.size())if(typ[i]&1){
			dis[i]=make_pair(val[i],0);
			qx.push(i);inq[i]=1;
		}
		int res=-1;
		while(!qx.empty()){
			int x=qx.front();qx.pop();inq[x]=0;
			if(typ[x]&2){
				if(res==-1||dis[res]>dis[x]){
					res=x;
				}
			}
			rep0(i,v.size())if(in[i]!=in[x]&&g[x][i]){
				pair<int,int> z=dis[x];
				z.first+=val[i];
				z.second++;
				if(dis[i]>z){
					dis[i]=z;pre[i]=x;
					if(!inq[i]){
						inq[i]=1;
						qx.push(i);
					}
				}
			}
			if(i<v.size()) break;
		}
		if(res==-1)break;
		int x=res;
		while(!(typ[x]&1)){
			in[x]^=1;x=pre[x];
		}
		in[x]^=1;
	}
	vector<pair<int,int> > ans;
	rep0(i,v.size())if(in[i]){
		ans.push_back(v[i]);
	}
	return ans;
}
void solve(){
	vector<pair<int,int> > v;
	v=calc(all);
	int res=cur;
	rep0(i,v.size()) res+=mp[v[i].first][v[i].second];
	ans=min(ans,res);
}
void dfs(int x,int y,int d){
	if(x>m){
		memcpy(mfa,fa,sizeof(fa));
		memcpy(mdeg,deg,sizeof(deg));
		solve();
		memcpy(fa,mfa,sizeof(fa));
		memcpy(deg,mdeg,sizeof(deg));
		return;
	}
	if(y>m){
		dfs(x+1,x+2,d);
		return;
	}
	dfs(x,y+1,d);
	if(fnd(x)==fnd(y)||!deg[x]||!deg[y])return;
	memcpy(mem[d],fa,sizeof(fa));
	deg[x]--;deg[y]--;fa[fnd(x)]=fnd(y);
	cur+=mp[x][y];
	dfs(x,y+1,d+1);
	cur-=mp[x][y];
	deg[x]++;deg[y]++;
	memcpy(fa,mem[d],sizeof(fa));
}
int main(){
	ans=2e9;
	cin>>n>>m;
	rep(i,m)cin>>deg[i];
	rep(i,n)fa[i]=i;
	rep(i,n)for(j=i+1;j<=n;j++){
		cin>>mp[i][j];
		mp[i][j]-=big;
	}
	rep(i,m){
		for(j=m+1;j<=n;j++){
			all.push_back(make_pair(i,j));
		}
	}
	vector<pair<int,pair<int,int> > > vv;
	for(i=m+1;i<=n;i++)for(j=i+1;j<=n;j++){
		vv.push_back(make_pair(mp[i][j],make_pair(i,j)));
	}
	sort(vv.begin(),vv.end());
	rep0(i,vv.size()){
		if(fnd(vv[i].second.first)!=fnd(vv[i].second.second)){
			fa[fnd(vv[i].second.first)]=fnd(vv[i].second.second);
			all.push_back(vv[i].second);
		}
	}
	rep(i,n)fa[i]=i;
	dfs(1,2,1);
	cout<<ans+big*(n-1)<<endl;
	return 0;
}