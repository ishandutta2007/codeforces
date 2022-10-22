#include<cstdio>
#include<vector>
#include<bitset>
using namespace std;
#define mp make_pair
#define fi first
#define se second
const int o=510;
int n,m,q;bool ans[o*2000];char s[o][o];
vector<pair<pair<pair<int,int>,pair<int,int> >,int> > vec[o*4];bitset<o> f[o][o],g[o][o];
void ins(int id,int sx,int sy,int tx,int ty,int qid,int l,int r){
	int md=l+r>>1;
	if(sx<=md&&md<=tx){vec[id].push_back(mp(mp(mp(sx,sy),mp(tx,ty)),qid));return;}
	if(sx>md) ins((id<<1)|1,sx,sy,tx,ty,qid,md+1,r);
	else ins(id<<1,sx,sy,tx,ty,qid,l,md);
}
void dfs(int id,int l,int r){
	int md=l+r>>1;
	if(vec[id].size()){
		for(int i=1;i<=m;++i){
			f[md][i].reset();g[md][i].reset();
			if(s[md][i]=='.') f[md][i].set(i),g[md][i].set(i);
		}
		for(int i=2;i<=m;++i) if(s[md][i]=='.') g[md][i]|=g[md][i-1];
		for(int i=m-1;i;--i) if(s[md][i]=='.') f[md][i]|=f[md][i+1];
		for(int i=md-1;i>=l;--i) for(int j=m;j;--j)
			if(s[i][j]=='.') f[i][j]=f[i+1][j]|f[i][j+1];else f[i][j].reset();
		for(int i=md+1;i<=r;++i) for(int j=1;j<=m;++j)
			if(s[i][j]=='.') g[i][j]=g[i-1][j]|g[i][j-1];else g[i][j].reset();
		for(int i=0,j=vec[id].size();i<j;++i)
			ans[vec[id][i].se]=!!(f[vec[id][i].fi.fi.fi][vec[id][i].fi.fi.se]&
			g[vec[id][i].fi.se.fi][vec[id][i].fi.se.se]).count();
	}
	if(l^r) dfs(id<<1,l,md),dfs((id<<1)|1,md+1,r);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%s",s[i]+1);
	scanf("%d",&q);
	for(int i=1,sx,sy,tx,ty;i<=q;++i){
		scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
		if(sx>tx||sy>ty||s[sx][sy]=='#'||s[tx][ty]=='#');
		else ins(1,sx,sy,tx,ty,i,1,n);
	}
	dfs(1,1,n);
	for(int i=1;i<=q;printf(ans[i++]?"Yes\n":"No\n"));
	return 0;
}