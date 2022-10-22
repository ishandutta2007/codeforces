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
const int N=100000,M=100000;
int n,m,qu;
vector<pair<int,int> > eg[M+1];
vector<int> nei[N+1];
bool vis[N+1];
vector<int> cc;
void dfs(int x){
//	printf("at %d\n",x);
	vis[x]=true;
	cc.pb(x);
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(!vis[y])dfs(y);
	}
} 
vector<vector<int> > ccs;
map<pair<int,int>,int> tim;
struct ufset{
	int fa[N+1];
	void init(){memset(fa,0,sizeof(fa));}
	int root(int x){return fa[x]?fa[x]=root(fa[x]):x;}
	void merge(int x,int y){x=root(x);y=root(y);if(x!=y)fa[x]=y;}
	bool same(int x,int y){return root(x)==root(y);}
};
vector<ufset> ufs;
int main(){
	cin>>n>>m;
	int lim=sqrt(m);
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		eg[z].pb(mp(x,y));
	}
	for(int i=1;i<=m;i++){
		ccs.clear();
		for(int j=0;j<eg[i].size();j++)nei[eg[i][j].X].pb(eg[i][j].Y),nei[eg[i][j].Y].pb(eg[i][j].X);
		int sum=0;
		for(int j=0;j<eg[i].size();j++)if(!vis[eg[i][j].X])cc.clear(),dfs(eg[i][j].X),ccs.pb(cc),sum+=cc.size();
		if(sum<=lim)
			for(int j=0;j<ccs.size();j++){
				vector<int> &v=ccs[j];
				for(int k=0;k<v.size();k++)for(int o=k+1;o<v.size();o++)tim[mp(min(v[k],v[o]),max(v[k],v[o]))]++;
			}
		else{
			ufset st;
			st.init();
			for(int j=0;j<ccs.size();j++){
				vector<int> &v=ccs[j];
				for(int k=0;k+1<v.size();k++)st.merge(v[k],v[k+1]);
			}
			ufs.pb(st);
		}
		for(int j=0;j<eg[i].size();j++)vis[eg[i][j].X]=vis[eg[i][j].Y]=false,nei[eg[i][j].X].clear(),nei[eg[i][j].Y].clear();
	}
//	printf("|ufs|=%d\n",int(ufs.size()));
	cin>>qu;
	while(qu--){
		int x,y;
		cin>>x>>y;
		int res=tim[mp(min(x,y),max(x,y))];
		for(int i=0;i<ufs.size();i++)res+=ufs[i].same(x,y);
		cout<<res<<"\n";
	}
	return 0;
}
/*1
4 5
1 2 1
1 2 2
2 3 1
2 3 3
2 4 3
3
1 2
3 4
1 4
*/
/*2
5 7
1 5 1
2 5 1
3 5 1
4 5 1
1 2 2
2 3 2
3 4 2
5
1 5
5 1
2 5
1 5
1 4
*/