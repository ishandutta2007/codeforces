#include<cstdio>
#include<utility>
#include<vector>
#include<cstring>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=1e5+10;
int n,m,q,a[o],v[o],cnt,h[o],tp[o],d[o],s[o],hs[o],dfn[o],fa[o];
vector<pair<int,int> >  p[o];long long s1,s2,C,ans[o],b1[o],b2[o];
struct Edge{int v,p;}e[o*2];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void Dfs(int nw){
	s[nw]=1;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa[nw])
		d[e[i].v]=d[fa[e[i].v]=nw]+1,Dfs(e[i].v),s[nw]+=s[e[i].v],hs[nw]=(s[hs[nw]]>s[e[i].v]?hs[nw]:e[i].v);
}
void dfs(int nw,int ld){
	dfn[nw]=++cnt;tp[nw]=ld;
	if(hs[nw]) dfs(hs[nw],ld);
	for(int i=h[nw];i;i=e[i].p) if(e[i].v-fa[nw]&&e[i].v-hs[nw]) dfs(e[i].v,e[i].v);
}
inline int lowbit(int x){return x&-x;}
inline void modify(int l,int r,int val){
	for(int i=l;i<=n;i+=lowbit(i)) b1[i]+=val,b2[i]+=l*1ll*val;
	for(int i=r+1;i<=n;i+=lowbit(i)) b1[i]-=val,b2[i]-=(r+1)*1ll*val;
}
inline long long query(int l,int r){
	long long res=0;
	for(int i=r;i;i-=lowbit(i)) res+=(r+1)*b1[i]-b2[i];
	for(int i=l-1;i;i-=lowbit(i)) res-=l*b1[i]-b2[i];
	return res;
}
long long ins(int x){
	long long res=0;
	for(;x;x=fa[tp[x]]) res+=query(dfn[tp[x]],dfn[x]),modify(dfn[tp[x]],dfn[x],1);
	return res;
}
long long del(int x){
	long long res=0;
	for(;x;x=fa[tp[x]]) modify(dfn[tp[x]],dfn[x],-1),res+=query(dfn[tp[x]],dfn[x]);
	return res;
}
int main(){
	read(n);read(m);read(q);read(C);
	for(int i=1;i<=n;++i) read(a[i]),p[a[i]].push_back(make_pair(i,0));
	for(int i=2,j;i<=n;++i) read(j),ad(j,i),ad(i,j);
	for(int i=1;i<=m;++i) read(v[i]);
//	for(int i=1,j,k;i<n;++i) read(j),read(k),ad(j,k),ad(k,j);
	Dfs(d[1]=1);cnt=0;dfs(1,1);cnt=0;
	for(int i=1,opt,j,k;i<=q;++i){
		read(opt);read(j);
		if(opt==1) read(k),p[a[j]].push_back(make_pair(-j,0)),p[a[j]=k].push_back(make_pair(j,0));
		else p[j].push_back(make_pair(0,++cnt));
	}
	for(int i=1;i<=m;++i,s1=s2=0,memset(b1,0,sizeof b1),memset(b2,0,sizeof b2)) for(int j=0,k=p[i].size();j<k;++j)
		if(p[i][j].second) ans[p[i][j].second]=s2*v[i]*v[i]-2*s1*v[i]*C+C*C*n;
		else if(p[i][j].first>0) s1+=d[p[i][j].first],s2+=ins(p[i][j].first)*2+d[p[i][j].first];
		else s1-=d[-p[i][j].first],s2-=del(-p[i][j].first)*2+d[-p[i][j].first];
	for(int i=1;i<=cnt;++i) printf("%.6lf\n",ans[i]*1.0/n);
	return 0;
}