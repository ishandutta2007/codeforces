/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
const int N=100000,M=100000,DB_SZ=333;
int n,m; 
vector<int> nei[N+1];
int dfn[N+1],mxdfn[N+1],mng[N+1],nowdfn;
void dfs(int x=1,int fa=0){
	mng[dfn[x]=mxdfn[x]=++nowdfn]=x;
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(y==fa)continue;
		dfs(y,x);
		mxdfn[x]=mxdfn[y];
	}
}
int d[N+2];
struct segtree{
	struct node{int l,r,sum;bool lz;}nd[N<<2];
	#define l(p) nd[p].l
	#define r(p) nd[p].r
	#define sum(p) nd[p].sum
	#define lz(p) nd[p].lz
	stack<stack<pair<int,node> > > stk;
	void bld(int l=1,int r=n,int p=1){
		l(p)=l;r(p)=r;sum(p)=r-l+1;lz(p)=0;
		if(l==r)return;
		int mid=l+r>>1;
		bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
	}
	void init(){bld();}
	void sprup(int p){
		stk.top().push(mp(p,nd[p]));
		sum(p)=sum(p<<1)+sum(p<<1|1);
	}
	void tag(int p){
		stk.top().push(mp(p,nd[p]));
		sum(p)=0;lz(p)=true;
	}
	void sprdwn(int p){
		stk.top().push(mp(p,nd[p]));
		if(lz(p))tag(p<<1),tag(p<<1|1),lz(p)=false;
	}
	void chg(int l,int r,int p=1){
		if(p==1)stk.push(stack<pair<int,node> >());
		if(l<=l(p)&&r>=r(p))return tag(p);
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		if(l<=mid)chg(l,r,p<<1);
		if(r>mid)chg(l,r,p<<1|1);
		sprup(p);
	}
	int zero(){return sum(1);}
	void cancel(){
		stack<pair<int,node> > s=stk.top();
		stk.pop();
		while(s.size())nd[s.top().X]=s.top().Y,s.pop();
	}
}segt;
vector<pair<pair<int,int>,int> > add[N+2];
int ans[N+1];
int main(){
//	freopen("b.in","r",stdin);freopen("b.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		nei[x].pb(y);nei[y].pb(x);
	}
	dfs();
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		d[dfn[x]]++,d[mxdfn[x]+1]--,d[dfn[y]]++,d[mxdfn[y]+1]--;
		if(dfn[x]<=dfn[y]&&mxdfn[y]<=mxdfn[x]){
			add[dfn[x]].pb(mp(mp(dfn[x],mxdfn[x]),1));
			add[mxdfn[x]+1].pb(mp(mp(dfn[x],mxdfn[x]),-1));
		}
		else if(dfn[y]<=dfn[x]&&mxdfn[x]<=mxdfn[y]){
			add[dfn[y]].pb(mp(mp(dfn[y],mxdfn[y]),1));
			add[mxdfn[y]+1].pb(mp(mp(dfn[y],mxdfn[y]),-1));
		}
		else{
			add[dfn[x]].pb(mp(mp(dfn[x],mxdfn[x]),1));
			add[mxdfn[x]+1].pb(mp(mp(dfn[x],mxdfn[x]),-1));
			add[dfn[y]].pb(mp(mp(dfn[x],mxdfn[x]),1));
			add[mxdfn[y]+1].pb(mp(mp(dfn[x],mxdfn[x]),-1));
			add[dfn[x]].pb(mp(mp(dfn[y],mxdfn[y]),1));
			add[mxdfn[x]+1].pb(mp(mp(dfn[y],mxdfn[y]),-1));
			add[dfn[y]].pb(mp(mp(dfn[y],mxdfn[y]),1));
			add[mxdfn[y]+1].pb(mp(mp(dfn[y],mxdfn[y]),-1));
		}
	}
	for(int i=1;i<=n;i++)d[i]+=d[i-1];
	segt.init();
	for(int i=1;i<=n;i++){
		for(int j=0;j<add[i].size();j++){
			int v=add[i][j].Y;
			if(v==-1)segt.cancel();
		}
		for(int j=0;j<add[i].size();j++){
			int l=add[i][j].X.X,r=add[i][j].X.Y,v=add[i][j].Y;
			if(v==1)segt.chg(l,r);
		}
		ans[mng[i]]=n-segt.zero()-!!d[i];
	}
	for(int i=1;i<=n;i++)printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}
/*1
5 1
1 2
1 3
3 5
3 4
2 3
*/
/*2
11 3
1 2
2 3
2 4
1 5
5 6
5 7
5 8
6 9
8 10
8 11
2 9
3 6
2 8
*/