#include<bits/stdc++.h>
const int N=100003,Q=200003,S=200003;
namespace io{
	char tmp[N];int len;
	inline void Scanstring(std::string&a){
		scanf("%s",tmp),len=strlen(tmp);
		a.resize(len);
		for(int i=0;i<len;i++)a[i]=tmp[i];
	}
	inline void Printstring(std::string a){
		len=a.size(),tmp[len]=0;
		if(!len){printf("-1");return;}
		for(int i=0;i<len;i++)tmp[i]=a[i];
		printf("%s",tmp);
	}
}using io::Scanstring;using io::Printstring;
int n,m,q,len[N+N],fa[N+N],son[N+N][26],dfn[N+N],siz[N+N],pos[N+N],flg[N+N],dfc,t,lst,nod[N],la[N+N];
std::vector<int>g[N+N];
struct query{std::string b;int l,r,p;}qry[Q];
bool Cmpq(const query&a,const query&b){return a.r<b.r;}
std::string a,ans[Q];
const int D=1<<19;
struct segment_tree{
	int mx[D+D];
	inline void Init(){for(int k=0;k<D+D;k++)mx[k]=-1;}
	inline void Update(int k,int a){
		for(mx[k+=D]=a,k>>=1;k;k>>=1)mx[k]=std::max(mx[k<<1],mx[k<<1|1]);
	}
	inline int Max(int l,int r){
		int res=-1;
		for(l+=D-1,r+=D+1;l^r^1;l>>=1,r>>=1){
			if(~l&1)res=std::max(res,mx[l^1]);
			if( r&1)res=std::max(res,mx[r^1]);
		}return res;
	}
}tr;
void Dfs0(int u){
	int v;
	dfn[u]=dfc;
	if(flg[u])++dfc,siz[u]=1;
	for(int i=0;i<g[u].size();i++){
		v=g[u][i];
		Dfs0(v);
		siz[u]+=siz[v];
	}
}
inline bool Exist(int u,int len,int l){
	return tr.Max(dfn[u],dfn[u]+siz[u]-1)>=l+len-1;
}
inline void Trans(std::string&s,int k,int l){
	s.resize(l);
	for(int i=0;i<l;i++)s[i]=a[pos[k]-l+1+i];
}
inline void Query(int j){
	int k=1,l=0,c;
	for(int i=0;i<m;i++){
		c=qry[j].b[i]-'a';
		if(son[k][c]&&Exist(son[k][c],l+1,qry[j].l))
			la[son[k][c]]=k,k=son[k][c],++l;
		else break;
	}
	if(l==m){
		for(int c=0;c<26;c++)
			if(son[k][c]&&Exist(son[k][c],l+1,qry[j].l))
			{k=son[k][c],++l;goto Brk2;}
		--l,k=la[k];
	}
	for(;l>=0;l--,k=la[k]){
		if(k>1&&l<=len[fa[k]])k=fa[k];
		for(c=qry[j].b[l]-'a'+1;c<26;c++)
			if(son[k][c]&&Exist(son[k][c],l+1,qry[j].l))
			{k=son[k][c],++l;goto Brk2;}
	}
  Brk2:;
	if(l<0)return;
	Trans(ans[qry[j].p],k,l);
}
int main(){
	int c,u,v,w,p;
	Scanstring(a),scanf("%d",&q),n=a.size();
	if(!q)return 0;
	for(int j=1;j<=q;j++){
		qry[j].p=j;
		scanf("%d%d",&qry[j].l,&qry[j].r);
		Scanstring(qry[j].b);
		--qry[j].l,--qry[j].r;
	}
	std::sort(qry+1,qry+1+q,Cmpq);
	lst=t=1;
	for(int i=0;i<n;i++){
		c=a[i]-'a';
		u=++t,len[u]=len[lst]+1,pos[u]=i;
		nod[i]=u,flg[u]=1;
		for(v=lst;v&&!son[v][c];v=fa[v])son[v][c]=u;
		if(v){
			p=son[v][c];
			if(len[p]==len[v]+1)fa[u]=p;
			else{
				w=++t,len[w]=len[v]+1,pos[w]=i;
				for(;v&&son[v][c]==p;v=fa[v])son[v][c]=w;
				for(int c=0;c<26;c++)son[w][c]=son[p][c];
				fa[w]=fa[p],fa[p]=fa[u]=w;
			}
		}else fa[u]=1;
		lst=u;
	}
	for(u=2;u<=t;u++)g[fa[u]].push_back(u);
	dfc=1,Dfs0(1);
	tr.Init();
	for(int i=0,j=1;i<n;i++){
		tr.Update(dfn[nod[i]],i);
		for(;j<=q&&qry[j].r==i;++j){
			m=qry[j].b.size();
			Query(j);
		}
	}
	for(int j=1;j<=q;j++)Printstring(ans[j]),putchar('\n');
	return 0;
}