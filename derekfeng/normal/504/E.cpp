#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
namespace IO{
	const int SIZ=(1<<25);
	char buf1[SIZ],*p1=buf1,*p2=buf1;
	char buf2[SIZ],*p3=buf2,*p4=buf2;
	char gchar(){if(p1==p2)p1=buf1,p2=buf1+fread(buf1,1,SIZ,stdin);return p1==p2?EOF:*p1++;}
	void pchar(char c){*p4++=c;if(p4-p3==SIZ)fwrite(buf2,1,SIZ,stdout),p4=buf2;}
	void output(){fwrite(buf2,1,p4-p3,stdout);}
};
using namespace IO;
void read(int &x){x=0;int c;while((c=gchar())>'9'||c<'0');x=c-'0';while((c=gchar())>='0'&&c<='9')x=x*10+c-'0';}
void reads(char *s){int c;while((c=gchar())>'z'||c<'a');*s++=c;while((c=gchar())>='a'&&c<='z')*s++=c;}
void write(int x){if(x>9)write(x/10);pchar(x%10+'0');}
int n,q,N;
char c[300005],s[600005];
int fa[300005],sz[300005],hs[300005];
vector<int>g[300005];
int pos1[300005],pos2[300005];
int cnt,nxt[300005],dfn[300005];
void dfs(int u,int pa){
	sz[u]=1;
	for(int i=0;i<g[u].size();++i){
		int v=g[u][i];
		if(v==pa)continue;
		fa[v]=u,dfs(v,u),sz[u]+=sz[v];
		if(sz[v]>sz[hs[u]])hs[u]=v;
	}
}
void dfs1(int u){
	vector<int>vec;
	for(;u;)vec.push_back(u),dfn[u]=++cnt,nxt[u]=vec[0],u=hs[u];
	for(int i=vec.size()-1;~i;--i)
		s[++N]=c[vec[i]],pos1[vec[i]]=N;
	for(int i=0;i<vec.size();++i)
		s[++N]=c[vec[i]],pos2[vec[i]]=N;
	for(int i=0;i<vec.size();++i){
		int v=vec[i];
		for(int j=0;j<g[v].size();++j){
			int w=g[v][j];
			if(w==fa[v]||w==hs[v])continue;
			dfs1(w);
		}
	}
}
int N1,N2,NN;
pii v1[45],v2[45],vv[23];
void calc(int u,int v,pii *vec,int &N){
	N=NN=0;
	int w=0;
	for(;;){
		if(dfn[v]<dfn[u])swap(u,v),w^=1;
		int T=nxt[v];
		if(dfn[T]<=dfn[u]&&dfn[u]<=dfn[v]){
			if(u==v)break;
			if(w)vec[N++]={pos1[v],pos1[u]-1};
			else vv[NN++]={pos2[u]+1,pos2[v]};
			break;
		}
		if(w)vec[N++]={pos1[v],pos1[T]};
		else vv[NN++]={pos2[T],pos2[v]};
		v=fa[T];
	}
	vec[N++]={pos1[u],pos1[u]};
	for(int i=NN-1;i>=0;i--)
		vec[N++]=vv[i];
}
const int H=31,M=1e9+7;
int hh[600005],pw[600005];
int qry(int l,int r){
	return (hh[r]-(ll)hh[l-1]*pw[r-l+1]%M+M)%M;
}
int sevendawns(){
	int i1=0,i2=0,l,r,w=0,ans=0;
	for(;;){
		if(w==0){
			if(i1==N1||i2==N2)return ans;
			l=v1[i1].fi,r=v1[i1].se,i1++,w=1;
			continue;
		}
		int L,R;
		if((w==1&&i2==N2)||(w==2&&i1==N1))return ans;
		if(w==1)L=v2[i2].fi,R=v2[i2++].se;
		else L=v1[i1].fi,R=v1[i1++].se;
		if(s[l]!=s[L])return ans;
		int len=r-l+1,Len=R-L+1,tmp=min(len,Len);
		if(qry(l,l+tmp-1)!=qry(L,L+tmp-1)){
			int ld=-1,rd=tmp;
			while(rd>ld+1){
				int md=(ld+rd)>>1;
				if(md==0||qry(l,l+md-1)==qry(L,L+md-1))ld=md;
				else rd=md;
			}
			return (ans+=ld);
		}
		ans+=tmp;
		if(len==Len)w=0;
		else if(len>Len)l+=Len;
		else w^=3,l=L+len,r=R;
	}
	return ans;
}
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	read(n),reads(c+1);
	for(int i=1;i<n;i++){
		int u,v;read(u),read(v);
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs(1,0),dfs1(1);
	pw[0]=1;
	for(int i=1;i<=N;i++){
		pw[i]=(ll)pw[i-1]*H%M;
		hh[i]=((ll)hh[i-1]*H+s[i])%M;
	}
	read(q);
	while(q--){
		int s,t;
		read(s),read(t),calc(s,t,v1,N1);
		read(s),read(t),calc(s,t,v2,N2);
		write(sevendawns()),pchar('\n');
	}
	output();
}