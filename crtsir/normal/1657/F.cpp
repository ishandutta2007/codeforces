#include<bits/stdc++.h>
using namespace std;
int n,q,msk[400003];
int fa[19][400003],dep[400003];
vector<int>v[400003],h[400003];
vector<pair<int,int> >g[400003];
void init(int x,int p){
	fa[0][x]=p;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p){
			dep[v[x][i]]=dep[x]+1;
			init(v[x][i],x);
		}
}
string s;
int lca(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	for(int i=0;i<19;i++)
		if(dep[y]-dep[x]&(1<<i))
			y=fa[i][y];
	if(x==y)return x;
	for(int i=18;i>=0;i--)
		if(fa[i][x]!=fa[i][y])
			x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
void calc(int x,int t,int pos,int nw){
	if(x==t)return;
	g[x].push_back(make_pair(s[pos]-'a',s[s.size()-1-pos]-'a'));
	msk[x]&=((1<<g[x].back().first)|(1<<g[x].back().second));
	h[x].push_back(nw);
	calc(fa[0][x],t,pos+1,nw);
}
int c[2][400003];
struct twosat{
	bool vis[1600003];
	vector<int>V[1600003],G,rV[1600003];
	void add_edgeequal(int x,int y){
//		cout<<"equal:"<<x<<' '<<y<<endl;
		V[x].push_back(y);
		rV[y].push_back(x);
		V[y].push_back(x);
		rV[x].push_back(y);
	}
	void add_edgeto(int x,int y){
//		cout<<"to:"<<x<<' '<<y<<endl;
		V[x].push_back(y);
		rV[y].push_back(x);
	}
	void dfs(int x){
		vis[x]=1;
		for(int i=0;i<V[x].size();i++)
			if(!vis[V[x][i]])
				dfs(V[x][i]);
		G.push_back(x);
	}
	int col[1600003];
	void rdfs(int x,int k){
		vis[x]=1;col[x]=k;
		for(int i=0;i<rV[x].size();i++)
			if(!vis[rV[x][i]])
				rdfs(rV[x][i],k);
	}
	bool calc(int sz){
		memset(vis,0,sizeof(vis));
		G.clear();
		for(int i=0;i<sz;i++)
			if(!vis[i])
				dfs(i);
		memset(vis,0,sizeof(vis));
		int cntt=0;
		for(int i=G.size()-1;i>=0;i--)
			if(!vis[G[i]])
				rdfs(G[i],cntt++);
//		for(int i=0;i<2*n;i++)
//			cout<<col[i]<<' ';cout<<endl;
		for(int i=0;i<sz;i+=2)
			if(col[i]==col[i+1])
				return 0;
		return 1;
	}
}gr;
int main(){
	memset(msk,-1,sizeof(msk));
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	init(0,-1);
	for(int i=1;i<19;i++)
		for(int j=0;j<n;j++)
			if(fa[i-1][j]==-1)
				fa[i][j]=-1;
			else
				fa[i][j]=fa[i-1][fa[i-1][j]];
	for(int i=0;i<q;i++){
		int x,y;
		scanf("%d%d",&x,&y);cin>>s;
		x--;y--;
		calc(x,fa[0][lca(x,y)],0,i);
		reverse(s.begin(),s.end());
		calc(y,lca(x,y),0,i);
	}
	for(int i=0;i<n;i++)
		if(msk[i]==0){cout<<"NO";return 0;}
	for(int i=0;i<n;i++){
		if(msk[i]!=-1){
			c[0][i]=log2(msk[i]&-msk[i]);
			if((msk[i]&-msk[i])!=msk[i])
				c[1][i]=log2(msk[i]-(msk[i]&-msk[i]));
			else
				c[1][i]=c[0][i];
			if(c[0][i]!=c[1][i])
				for(int j=0;j<g[i].size();j++)
					if(g[i][j].first==c[0][i]){
						gr.add_edgeequal(i*2+1,h[i][j]*2+n*2+1);
						gr.add_edgeequal(i*2,h[i][j]*2+n*2);
					}else{
						gr.add_edgeequal(i*2,h[i][j]*2+n*2+1);
						gr.add_edgeequal(i*2+1,h[i][j]*2+n*2);
					}
			else
				for(int j=0;j<g[i].size();j++)
					if(g[i][j].first!=g[i][j].second)
						if(g[i][j].first==c[0][i])
							gr.add_edgeto(2*n+h[i][j]*2+1,2*n+h[i][j]*2); 
						else
							gr.add_edgeto(2*n+h[i][j]*2,2*n+h[i][j]*2+1);
		}
	}
	if(!gr.calc(2*n+2*q)){cout<<"NO";return 0;}
	cout<<"YES\n";
	for(int i=0;i<n;i++){
		if(msk[i]==-1)
			cout<<'a';
		else if(c[0][i]==c[1][i])
			cout<<char('a'+c[0][i]);
		else
			if(gr.col[i*2]>gr.col[i*2+1])
				cout<<char('a'+c[0][i]);
			else
				cout<<char('a'+c[1][i]);
	}
}