#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
const int SIZ=(1<<24);
char buf1[SIZ],*p1=buf1,*p2=buf1;
char buf2[SIZ],*p3=buf2,*p4=buf2;
char gchar(){if(p1==p2)p1=buf1,p2=buf1+fread(buf1,1,SIZ,stdin);return p1==p2?EOF:*p1++;}
void pchar(char c){*p4++=c;if(p4-p3==SIZ)fwrite(buf2,1,SIZ,stdout),p4=buf2;}
void output(){fwrite(buf2,1,p4-p3,stdout);}
int read(){int ret=0,c;while((c=gchar())>'9'||c<'0');ret=c-'0';while((c=gchar())>='0'&&c<='9')ret=ret*10+c-'0';return ret;}
int n,m,K,q,tot,rd[500005];
unordered_map<int,int>mp[55][2];
int lst[500005],cnt;
int u[500005],v[500005];
int e[500005],c[500005];
vector<int>qry[1100000];
int fa[2000005],dp[2000005];
stack<pair<pii,pii> >sta;
bool ans[500005];
int F(int u){
	return fa[u]==u?u:F(fa[u]);
}
void merge(int u,int v,int tg){
	u=F(u),v=F(v);
	if(u==v)return;
	if(dp[u]<dp[v])swap(u,v);
	sta.push({{u,v},{dp[u],tg}});
	fa[v]=u,dp[u]=max(dp[u],dp[v]+1);
}
void rollback(int tg){
	while(!sta.empty()&&sta.top().se.se==tg){
		pair<pii,pii>x=sta.top();sta.pop();
		fa[x.fi.se]=x.fi.se,dp[x.fi.fi]=x.se.fi;
	}
}
void add(int i,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		qry[i].push_back(x);
		return;
	}
	int md=(l+r)>>1;
	add(i<<1,l,md,a,b,x),add(i<<1|1,md+1,r,a,b,x);
}
void sol(int i,int l,int r){
	int TG=++cnt;
	for(auto x:qry[i])
		if(lst[x]!=0){
			int C=lst[x];
			int U0=mp[C][0][u[x]],U1=mp[C][1][u[x]];
			int V0=mp[C][0][v[x]],V1=mp[C][1][v[x]];
			merge(U0,V1,TG),merge(U1,V0,TG);
		}
	if(l==r){
		int x=e[l],C=c[l];
		int U0=mp[C][0][u[x]],U1=mp[C][1][u[x]];
		int V0=mp[C][0][v[x]],V1=mp[C][1][v[x]];
		merge(U0,V1,TG),merge(U1,V0,TG);
		if(F(U0)==F(U1))ans[l]=0;
		else ans[l]=1,lst[x]=C;
	}else{
		int md=(l+r)>>1;
		sol(i<<1,l,md),sol(i<<1|1,md+1,r);
	}
	rollback(TG);
}
int main(){
	n=read(),m=read(),K=read(),q=read();
	for(int i=1;i<=m;i++)u[i]=read(),v[i]=read();
	for(int i=1;i<=q;i++){
		e[i]=read(),c[i]=read();
		if(mp[c[i]][0].find(u[e[i]])==mp[c[i]][0].end())mp[c[i]][0][u[e[i]]]=++tot;
		if(mp[c[i]][1].find(u[e[i]])==mp[c[i]][1].end())mp[c[i]][1][u[e[i]]]=++tot;
		if(mp[c[i]][0].find(v[e[i]])==mp[c[i]][0].end())mp[c[i]][0][v[e[i]]]=++tot;
		if(mp[c[i]][1].find(v[e[i]])==mp[c[i]][1].end())mp[c[i]][1][v[e[i]]]=++tot;
		int U0=mp[c[i]][0][u[e[i]]],U1=mp[c[i]][1][u[e[i]]];
		int V0=mp[c[i]][0][v[e[i]]],V1=mp[c[i]][1][v[e[i]]];
		if(lst[e[i]]!=0)rd[lst[e[i]]]=i;
		lst[e[i]]=i;
	}
	for(int i=1;i<=m;i++)if(lst[i])rd[lst[i]]=q,lst[i]=0;
	for(int i=1;i<=tot;i++)fa[i]=i;
	for(int i=1;i<q;i++)add(1,1,q,i+1,rd[i],e[i]);
	sol(1,1,q);
	for(int i=1;i<=q;i++){
		if(ans[i])pchar('Y'),pchar('E'),pchar('S'),pchar('\n');
		else pchar('N'),pchar('O'),pchar('\n');
	}
	output();
}