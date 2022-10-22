#include<bits/stdc++.h>
#define lbt(x) (x&(-x))
using namespace std;
typedef long long ll;
const int N=1000005;
int n,m;
int ch[N][26],fail[N],P;
int pos[N],cur;
struct edge{
	int v,nxt;
}g[N];
int hd[N],tl[N],Pe;
inline void add(int u,int v){
	int p=++Pe;g[p].v=v;
	if(!hd[u]) hd[u]=tl[u]=p;
	else tl[u]=g[tl[u]].nxt=p;
}
int d[N];
char a[N];int len;
void ins(int p,int x){
	if(x==len){
		pos[cur]=p;
		return;
	}
	int u=a[x]-'a';
	if(!ch[p][u]) ch[p][u]=++P;
	ins(ch[p][u],x+1);
}
queue<int> q;
void build(){
	int i;
	for(i=0;i<26;i++){
		if(ch[0][i])
			q.push(ch[0][i]);
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(i=0;i<26;i++){
			if(ch[u][i]){
				q.push(ch[u][i]);
				fail[ch[u][i]]=ch[fail[u]][i];
			}
			else ch[u][i]=ch[fail[u]][i];
		}
	}
}
int lft[N],rgt[N],cnt;
void dfs(int u){
	lft[u]=++cnt;
	for(int p=hd[u];p;p=g[p].nxt)
		dfs(g[p].v);
	rgt[u]=cnt;
}
bool vis[N];
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(cur=1;cur<=m;cur++){
		scanf("%s",a);
		len=strlen(a);
		ins(0,0);
		for(i=0;i<len;i++) a[i]=0;
	}
	build();
	for(i=1;i<=P;i++)
		add(fail[i],i);
	dfs(0);
	for(i=1;i<=m;i++){
		vis[i]=1;
		for(j=lft[pos[i]];j<=cnt;j+=lbt(j)) d[j]++;
		for(j=rgt[pos[i]]+1;j<=cnt;j+=lbt(j)) d[j]--;
	}
	while(n--){
		char op='\n';
		while(op=='\n') scanf("%c",&op);
		if(op=='?'){
			scanf("%s",a);len=strlen(a);
			ll ans=0;int p=0;
			for(i=0;i<len;i++){
				p=ch[p][a[i]-'a'];
				for(j=lft[p];j;j-=lbt(j)) ans+=d[j];
			}
			for(i=0;i<len;i++) a[i]=0;
			printf("%I64d\n",ans);
		}
		else{
			int x;scanf("%d",&x);
			if((op=='+'&&vis[x])||(op=='-'&&!vis[x])) continue;
			vis[x]^=1;
			int w=(op=='+'?1:-1);
			for(j=lft[pos[x]];j<=cnt;j+=lbt(j)) d[j]+=w;
			for(j=rgt[pos[x]]+1;j<=cnt;j+=lbt(j)) d[j]-=w;
		}
	}
	return 0;
}