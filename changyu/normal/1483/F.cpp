#include<bits/stdc++.h>
const int N=1e6+3,K=20;
char a[N];
bool fl[N];
int n,t,son[N][26],fa[N],fail[N][K],q[N],l,r,dep[N],dfn[N],dfc,siz[N],f[N],bt[N],ans;
std::vector<int>g[N];
inline void Add(int k,int a){for(;k<=dfc;k+=k&-k)bt[k]+=a;}
inline int Sum(int k){int s=0;for(;k;k-=k&-k)s+=bt[k];return s;}
void Dfs(int u){
	dfn[u]=++dfc,siz[u]=1;
	for(int v:g[u])Dfs(v),siz[u]+=siz[v];
}
inline int Jump(int k,int x){
	x=std::max(x,0);
	if(dep[k]<=x)return k;
	for(int j=K-1;~j;j--)if(dep[fail[k][j]]>x)k=fail[k][j];
	return fail[k][0];
}
int main(){
	int k,v;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",a);
		k=0;
		for(int j=0;a[j];j++){
			int c=a[j]-'a';
			if(!son[k][c])son[k][c]=++t,fa[t]=k,dep[t]=dep[k]+1;
			k=son[k][c];
		}
		fl[k]=1;
	}
	l=0,r=-1;
	for(int c=0;c<26;c++)if(son[0][c])q[++r]=son[0][c];
	for(;l<=r;){
		k=q[l++];
		for(int j=1;j<K;j++)fail[k][j]=fail[fail[k][j-1]][j-1];
		g[fail[k][0]].push_back(k);
		f[k]=fl[fail[k][0]]?fail[k][0]:f[fail[k][0]];
		for(int c=0;c<26;c++)
			if(son[k][c]){
				for(v=fail[k][0];v&&!son[v][c];v=fail[v][0]);
				fail[son[k][c]][0]=son[v][c];
				q[++r]=son[k][c];
			}
	}
	Dfs(0);
	for(v=1;v<=t;v++)if(fl[v]){
		std::set<int>st;
		k=v;
		for(int mn=t,ff;k;k=fa[k]){
			ff=fl[k]&&k!=v?k:f[k];
			if(ff&&dep[k]-dep[ff]+1<mn){
				mn=dep[k]-dep[ff]+1;
				st.insert(ff);
				Add(dfn[Jump(k,dep[k]-mn)],1);
			}
			else Add(dfn[Jump(k,dep[k]-mn+1)],1);
		}
		for(int k:st)ans+=Sum(dfn[k]-1)==Sum(dfn[k]+siz[k]-1);
		k=v;
		for(int mn=t,ff;k;k=fa[k]){
			ff=fl[k]&&k!=v?k:f[k];
			if(ff&&dep[k]-dep[ff]+1<mn){
				mn=dep[k]-dep[ff]+1;
				Add(dfn[Jump(k,dep[k]-mn)],-1);
			}
			else Add(dfn[Jump(k,dep[k]-mn+1)],-1);
		}
	}
	printf("%d\n",ans);
	return 0;
}