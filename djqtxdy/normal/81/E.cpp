#include<bits\stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int Maxn=100005;
vector<int> G[Maxn];
int nxt[Maxn];
int sex[Maxn];
bool vis[Maxn];
vector<int> v;
int col[Maxn];
vector<int> cycles[Maxn];
pair<int,int> dpf[Maxn][2];
int pref[Maxn];
pair<int,int> dps[Maxn][2];
int pres[Maxn];
int ux,uy;
vector<int> ss[Maxn];
bool xxx=true;
void dfs(int x,int c,int p){
	//cout<<"PUSH"<<' '<<x;
	v.pb(x);
	ss[c].pb(x);
	vis[x]=true;
	bool vvv=true;
	for (int i=0;i<G[x].size();i++){
		
		if (vvv&& G[x][i]==p) {
			vvv=false;continue;
		}
		//if (i==1 && G[x][0]==G[x][1]) break;
		int vv=G[x][i];
		if (xxx && vis[vv]){
			for (int j=v.size()-1;j>=0;j--){
				cycles[c].pb(v[j]);
				//cout<<"dd"<<' '<<c<<' '<<v[j]<<' '<<vv<<endl; 
				if (v[j]==vv) break;
			}
			xxx=false;
		}
		else if (vis[vv]) ;
		else dfs(G[x][i],c,x);
	}
	//cout<<"POP"<<' '<<v.back()<<endl;
	v.pop_back();
}
pii add(pii x,pii y){
	return pii(x.first+y.first,x.second+y.second);
}
pii minuss(pii x,pii y){
	return pii(x.first-y.first,x.second-y.second);
}
bool lless(pii x,pii y){
	if (x.first!=y.first) return x.first<y.first;
	return x.second<y.second;
}
void calcfi(int x,int p){
	//assert(!vis[x]);
	vis[x]=true;
	//cout<<x<<p<<endl;
	dpf[x][0]=dpf[x][1]=mp(0,0);
	bool ff=true;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (v==p) continue;
		if (ff&& (x==ux && v==uy || x==uy && v==ux)){
			ff=false;
			continue;
		}
		calcfi(v,x);
		dpf[x][0]=add(dpf[x][0],dpf[v][1]);
	}
	ff=true;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (ff&& (x==ux && v==uy || x==uy && v==ux)){
			ff=false;
			continue;
		}
		if (v==p) continue;
		pii now=add(add(minuss(dpf[x][0],dpf[v][1]),dpf[v][0]),pii(1,(int)(sex[x]!=sex[v])));
		if (lless(dpf[x][1],now)){
			dpf[x][1]=now;
			pref[x]=v;
		}
	}
	if (lless(dpf[x][1],dpf[x][0])){
		dpf[x][1]=dpf[x][0];
		pref[x]=-1;
	}
}
void calcse(int x,int p){
	//cout<<x<<p<<endl;
	assert(!vis[x]);
	vis[x]=true;
	dps[x][0]=dps[x][1]=mp(0,0);
	bool ff=true;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (v==p) continue;
		if (ff&& (x==ux && v==uy || x==uy && v==ux)){
			ff=false;
			continue;
		}
		//cerr<<v<<' '<<x<<endl;
		calcse(v,x);
		dps[x][0]=add(dps[x][0],dps[v][1]);
	}
	ff=true;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (ff&& (x==ux && v==uy || x==uy && v==ux)){
			ff=false;
			continue;
		}
		if (v==p) continue;
		pii now=add(add(minuss(dps[x][0],dps[v][1]),dps[v][0]),pii(1,(int)(sex[x]!=sex[v])));
		if (lless(dps[x][1],now)){
			dps[x][1]=now;
			pres[x]=v;
		}
	}
	if (lless(dps[x][1],dps[x][0])){
		dps[x][1]=dps[x][0];
		pres[x]=-1;
	}
}
vector<pii > ans;
int totb;
void gof(int x,int f,int p){
	if (!f){
		bool ff=true;
		for (int i=0;i<G[x].size();i++){
			int v=G[x][i];
			if (ff&& (x==ux && v==uy || x==uy && v==ux)){
				ff=false;
				continue;
			}
			if (v==p) continue;
			gof(v,1,x);
		}
	}
	else{
		if (pref[x]==-1){
			gof(x,0,p);
		}
		else{
			bool ff=true;
			if (pref[x]) ans.pb(mp(x,pref[x]));
			for (int i=0;i<G[x].size();i++){
				int v=G[x][i];
				if (ff&& (x==ux && v==uy || x==uy && v==ux)){
					ff=false;
					continue;
				}
				if (v==p) continue;
				if (pref[x]==v)
					gof(v,0,x);
				else gof(v,1,x);
			}
		}
	}
}
void gos(int x,int f,int p){
	if (!f){
		bool ff=true;
		for (int i=0;i<G[x].size();i++){
			int v=G[x][i];
			if (ff&& (x==ux && v==uy || x==uy && v==ux)){
				ff=false;
				continue;
			}
			if (v==p) continue;
			gos(v,1,x);
		}
	}
	else{
		if (pres[x]==-1){
			gos(x,0,p);
		}
		else{
			bool ff=true;
			if (pres[x]) ans.pb(mp(x,pres[x]));
			for (int i=0;i<G[x].size();i++){
				int v=G[x][i];
				if (ff&& (x==ux && v==uy || x==uy && v==ux)){
					ff=false;
					continue;
				}
				if (v==p) continue;
				if (pres[x]==v)
					gos(v,0,x);
				else gos(v,1,x);
			}
		}
	}
}
void calc(int color){
	if (cycles[color].size()==3 && cycles[color][1]==cycles[color][2]){
		cycles[color].pop_back();
	}
//	cout<<cycles[color].size()<<endl;
	int x=cycles[color][0],y=cycles[color][1],z;
	if (cycles[color].size()==2) z=x;
	else z=cycles[color][2];
//	cout<<x<<y<<z<<endl;
//	return;
	for (int i=0;i<ss[color].size();i++) vis[ss[color][i]]=false;
	
	ux=x,uy=y;
	calcfi(y,-1);
	for (int i=0;i<ss[color].size();i++) vis[ss[color][i]]=false;
	ux=y,uy=z;
	calcse(y,-1);
	//cerr<<123123<<endl;
	if (lless(dps[y][1],dpf[y][1])){
		ux=x;uy=y;
		gof(y,1,-1);
		totb+=dpf[y][1].second;
	}
	else{
		ux=y;uy=z;
		gos(y,1,-1);
		totb+=dps[y][1].second;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&nxt[i],&sex[i]);
		
	}
	for (int i=1;i<=n;i++){
		G[nxt[i]].pb(i);
		G[i].pb(nxt[i]);
		//cout<<i<<' '<<nxt[i]<<endl;
	}
	int cur=0;
	for (int i=1;i<=n;i++){
		if (!vis[i]){xxx=true;
			dfs(i,cur++,-1);
		}
	}
//	cerr<<123<<endl;
	for (int i=0;i<cur;i++){
		calc(i);
	//	cerr<<123<<endl;
	}
	printf("%d %d\n",ans.size(),totb);
	for (int i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}