#include<bits/stdc++.h>
#define lbt(x) (x&(-x))
using namespace std;
typedef long long ll;
const int N=4e5+5;
int n,m;
int ch[N][26],fail[N],P;
string str[N];
int len[N],pos[N];
vector<pair<int,char>> g[N];
vector<int> G[N],ques[N];
void ins(int p,int id,int x){
	if(x==len[id]){
		pos[id]=p;
		return;
	}
	int u=str[id][x]-'a';
	if(!ch[p][u]) ch[p][u]=++P;
	ins(ch[p][u],id,x+1);
}
inline void build(){
	queue<int> q;
	int i;
	fail[1]=1;
	for(i=0;i<26;i++){
		if(ch[1][i]){
			fail[ch[1][i]]=1;
			q.push(ch[1][i]);
		}
		else ch[1][i]=1;
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		G[fail[u]].push_back(u);
		for(i=0;i<26;i++){
			if(ch[u][i]){
				fail[ch[u][i]]=ch[fail[u]][i];
				q.push(ch[u][i]);
			}
			else ch[u][i]=ch[fail[u]][i];
		}
	}
}
int lft[N],rgt[N],d[N],tot;
int ans[N];
void dfs1(int u){
	lft[u]=++tot;
	for(auto v:G[u])
		dfs1(v);
	rgt[u]=tot;
}
void dfs2(int u,int p){
	int i;
	for(i=lft[p];i<=P;i+=lbt(i)) d[i]++;
	for(auto x:ques[u]){
		for(i=rgt[pos[x]];i;i-=lbt(i)) ans[x]+=d[i];
		for(i=lft[pos[x]]-1;i;i-=lbt(i)) ans[x]-=d[i];
	}
	for(auto e:g[u]){
		int v=e.first,w=e.second-'a';
		dfs2(v,ch[p][w]);
	}
	for(i=lft[p];i<=P;i+=lbt(i)) d[i]--;
}
int main(){
	ios::sync_with_stdio(0);
	P=1;
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		int op;cin>>op;
		if(op==1){
			char ch;cin>>ch;
			g[0].push_back({i,ch});
		}
		else{
			int x;char ch;cin>>x>>ch;
			g[x].push_back({i,ch});
		}
	}
	cin>>m;
	for(i=1;i<=m;i++){
		int x;cin>>x;
		ques[x].push_back(i);
		cin>>str[i];
		len[i]=str[i].length();
		ins(1,i,0);
	}
	build();
	dfs1(1);
	dfs2(0,1);
	for(i=1;i<=m;i++) cout<<ans[i]<<endl;
	return 0;
}