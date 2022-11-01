//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=2e5+4;
int tot=1,ch[N][26],ed[N],fail[N],fa[N];
int n,tim,Q,dfn[N],siz[N],t[N],ans[N*3],k[N*3];
char s[N];
queue<int>q;
vector<int>e[N];
void buildAC(){
	for(int i=0;i<26;i++)ch[0][i]=1;
	q.push(1);
	while(!q.empty()){
		int p=q.front();q.pop();
		for(int c=0;c<26;c++)
			if(!ch[p][c])ch[p][c]=ch[fail[p]][c];
			else{
				fail[ch[p][c]]=ch[fail[p]][c];
				q.push(ch[p][c]);
			}
	}
	for(int i=2;i<=tot;i++)e[fail[i]].push_back(i);
} 
void dfs(int x){
	dfn[x]=++tim;siz[x]=1;
	for(auto v:e[x]){dfs(v);siz[x]+=siz[v];}
}
inline void add(int x,int v){
	for(;x<=tim;x+=x&-x)t[x]+=v;
}
inline int ask(int x){
	int ret=0;
	for(;x;x-=x&-x)ret+=t[x];
	return ret;
}
int main(){
	n=read();Q=read();
	for(int i=1,len,p,c;i<=n;i++){
		scanf("%s",s+1);
		len=strlen(s+1);
		p=1;
		for(int j=1;j<=len;j++){
			c=s[j]-'a';
			if(!ch[p][c])fa[ch[p][c]=++tot]=p;
			p=ch[p][c];
		}
		ed[i]=p;
	}
	buildAC();
	dfs(1);
	for(int i=1;i<=tot;i++)e[i].clear();
	for(int i=1,l,r;i<=Q;i++){
		l=read();r=read();k[i]=read();
		if(l-1)e[l-1].push_back(-i);
		e[r].push_back(i);
	}
	for(int i=1,p,o,x;i<=n;i++){
		p=ed[i];
		while(p>1){add(dfn[p],1);p=fa[p];} 
		for(auto v:e[i]){
			o=v>0?1:-1;v=abs(v);x=ed[k[v]];
			ans[v]+=o*(ask(dfn[x]+siz[x]-1)-ask(dfn[x]-1));
		}
	}
	for(int i=1;i<=Q;i++)cout<<ans[i]<<"\n";
	return (0-0);
}