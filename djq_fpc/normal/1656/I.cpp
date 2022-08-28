#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
#ifndef ONLINE_JUDGE
	FILE *___=freopen("1.in","r",stdin);
#endif
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int t,n,m,i,j,dfn[300005],low[300005],col[300005],ti,cnt;
vector<int> adj[300005];
int fa[300005],fl[300005],fr[300005];
int fnd(int x){if(fa[x]==x)return x;return fa[x]=fnd(fa[x]);}
void merge(int x,int y)
{
//	cerr<<x<<' '<<y<<endl;
	if(fnd(x)==fnd(y)){
		adj[x].push_back(y);
		adj[y].push_back(x);
		return;
	}
	adj[x].push_back(y);adj[y].push_back(x);
	int fx=fnd(x),fy=fnd(y);fa[fx]=fy;
	fr[fy]=(fl[fy]^fr[fy]^y);
	fl[fy]=(fl[fx]^fr[fx]^x);
}
map<int,int> cbi[300005];
int hd[300005],nxt[600005],to[600005],px[300005],py[300005];
void link(int x,int y,int id){nxt[id]=hd[x];hd[x]=id;to[id]=y;}
int stv[300005],tpv,ste[300005],tpe;
vector<int> res[300005];
vector<vector<int> > ans[300005];
int id[300005],vis[300005];
bool flg;
void dfs2(int x,int fa,int c)
{
	id[x]=c;ff(adj[x],it)if(*it!=fa&&id[*it]==-1)dfs2(*it,x,c+1);
}
int clen,ci;
bool cmp(int x,int y){return (id[x]-ci+clen)%clen<(id[y]-ci+clen)%clen;}
void solve(vector<int> vv,vector<int> ve)
{
	if(!flg||ve.empty())return;
	if(ve.size()==1){assert(vv.size()==2);ans[vv[0]].push_back((vector<int>){vv[1]});ans[vv[1]].push_back((vector<int>){vv[0]});return;}
	int i,j;ff(vv,it) cbi[*it].clear(),res[*it].clear(),fa[*it]=fl[*it]=fr[*it]=*it,vis[*it]=0;
	ff(ve,it) cbi[px[*it]][py[*it]]=cbi[py[*it]][px[*it]]=0;
	queue<int> qx;ff(vv,it) if(cbi[*it].size()==2) qx.push(*it);
	fz1(i,vv.size()-2){
		if(qx.empty()){flg=0;return;}int x=qx.front();qx.pop();
		if(vis[x]){i--;continue;}vis[x]=1;
		pair<int,int> t1=*cbi[x].begin(),t2=*cbi[x].rbegin();
		if(t1.second) merge(t1.second,x);
		if(t2.second) merge(x,t2.second);
		cbi[t1.first].erase(cbi[t1.first].find(x));
		cbi[t2.first].erase(cbi[t2.first].find(x));
		if(i==vv.size()-2){
			assert(cbi[t1.first].count(t2.first));
			if(cbi[t1.first][t2.first]) merge(t1.first,cbi[t1.first][t2.first]),merge(cbi[t2.first][t1.first],t2.first);
			else merge(t1.first,t2.first);
			merge(t1.first,fl[fnd(x)]);merge(fr[fnd(x)],t2.first);break;
		}
		else{
			if(cbi[t1.first][t2.first]||cbi[t2.first][t1.first]){flg=0;return;}
			cbi[t1.first][t2.first]=fl[fnd(x)];
			cbi[t2.first][t1.first]=fr[fnd(x)];
			if(cbi[t1.first].size()==2) qx.push(t1.first);
			if(cbi[t2.first].size()==2) qx.push(t2.first);
		}
	}
	ff(vv,it)if(fnd(*it)!=fnd(vv[0])){flg=0;return;}
	ff(vv,it) id[*it]=-1;dfs2(vv[0],-1,0);
	ff(ve,it) res[px[*it]].push_back(py[*it]),res[py[*it]].push_back(px[*it]);
	clen=vv.size();ff(vv,it) ci=id[*it],sort(res[*it].begin(),res[*it].end(),cmp);
	int mi=0x1064822E;ff(vv,it) mi=min(mi,*it);
	vector<int> tmp=res[mi];reverse(tmp.begin(),tmp.end());if(tmp<res[mi]){
		ff(vv,it) reverse(res[*it].begin(),res[*it].end());
	}
	ff(vv,it) ans[*it].push_back(res[*it]);
}
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++ti;stv[++tpv]=x;int i;
	for(i=hd[x];i;i=nxt[i])if(to[i]!=fa){
		if(!dfn[to[i]]){
			ste[++tpe]=(i>>1);tarjan(to[i],x);
			low[x]=min(low[x],low[to[i]]);
			if(low[to[i]]>=dfn[x]){
				vector<int> vv,ve;
				while(stv[tpv]!=to[i]) vv.push_back(stv[tpv--]);
				vv.push_back(stv[tpv--]);vv.push_back(x);
				while(ste[tpe]!=(i>>1)) ve.push_back(ste[tpe--]);
				ve.push_back(ste[tpe--]);
				solve(vv,ve);
			}
		}
		else if(dfn[to[i]]<dfn[x]){
			ste[++tpe]=(i>>1);
			low[x]=min(low[x],dfn[to[i]]);
		}
	}
}
vector<int> merge(vector<int> a,vector<int> b)
{
	vector<int> c;int i=0,j=0;
	while(i<a.size()||j<b.size()){
		if(i<a.size()&&(j>=b.size()||a[i]<b[j])) c.push_back(a[i++]);
		else c.push_back(b[j++]);
	}
	return c;
}
vector<int> merge(int id,int l,int r)
{
	if(l==r)return ans[id][l];int mid=(l+r)/2;
	return merge(merge(id,l,mid),merge(id,mid+1,r));
}
void solve()
{
	read(n);read(m);ti=cnt=0;flg=1;
	fz1(i,n)hd[i]=0,adj[i].clear(),cbi[i].clear(),ans[i].clear(),dfn[i]=low[i]=col[i]=0;
	fz1(i,m){int x,y;read(x);read(y);x++;y++;link(x,y,i<<1);link(y,x,(i<<1)|1);px[i]=x;py[i]=y;}
	fz1(i,n)if(!dfn[i])tarjan(i,0);if(!flg){puts("NO");return;}
	puts("YES");fz1(i,n) res[i]=merge(i,0,ans[i].size()-1);
	fz1(i,n){
		ff(res[i],it) printf("%d ",*it-1);
		puts("");
	}
}
int main()
{
//	freopen("granddesign.in","r",stdin);freopen("granddesign.out","w",stdout);
	read(t);while(t--)solve();return 0;
}