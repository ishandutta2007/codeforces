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
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
inline void read(string &st)
{
	char c;while(!islower(c=getchar()));st=c;
	while(islower(c=getchar()))st+=c;
}
const int maxc=26;
int n,m,q,i,j,ans[100005];
string st[100005];
namespace sam2
{
	int ch[800005][maxc],fa[800005],l[800005],lst=1,cnt=1;
	void extend(int c)
	{
//		cerr<<c<<' ';
		if(ch[lst][c]&&l[ch[lst][c]]==l[lst]+1){lst=ch[lst][c];return;}
		int np=++cnt,p=lst;lst=np;l[np]=l[p]+1;
		for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
		if(!p){fa[np]=1;return;}int q=ch[p][c];if(l[q]==l[p]+1){fa[np]=q;return;}
		int nq=++cnt;l[nq]=l[p]+1;fa[nq]=fa[q];fa[np]=fa[q]=nq;
		memcpy(ch[nq],ch[q],sizeof(ch[nq]));
		for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
	}
	void init(){/*cerr<<endl;*/lst=1;}
	int dep[800005],dfn[800005],lg[800005],ti,f[21][800005];
	vector<int> bi[800005];
	void dfs(int x,int p)
	{
		f[0][dfn[x]=++ti]=l[p];
		ff(bi[x],it){dep[*it]=dep[x]+1;dfs(*it,x);}
	}
	void rebuild()
	{
		int i,j;fz(i,2,cnt) bi[fa[i]].push_back(i);dfs(1,0);
		fz(i,2,ti) lg[i]=lg[i>>1]+1;
		fz1(j,19)fz1(i,ti-(1<<j)+1) f[j][i]=min(f[j-1][i],f[j-1][i+(1<<(j-1))]);
	}
	int lcp(int x,int y)
	{
		if(x==y) return l[x];
		x=dfn[x];y=dfn[y];if(x>y)swap(x,y);x++;
		int t=lg[y-x+1];return min(f[t][x],f[t][y-(1<<t)+1]);
	}
}
namespace temptree
{
	vector<pair<int,char> > bi[100005];char fc[100005];
	int fa[100005],sz[100005],son[100005],tp[100005],dep[100005];
	int dfn[100005],mp[100005],ti;
	void dfs1(int x,int p)
	{
		fa[x]=p;sz[x]=1;ff(bi[x],it)if(it->first!=p){
			fc[it->first]=it->second;dep[it->first]=dep[x]+1;dfs1(it->first,x);
			sz[x]+=sz[it->first];if(!son[x]||sz[it->first]>sz[son[x]]) son[x]=it->first;
		}
	}
	void dfs2(int x,int t)
	{
		mp[dfn[x]=++ti]=x;tp[x]=t;
		if(son[x]) dfs2(son[x],t);
		ff(bi[x],it)if(it->first!=fa[x]&&it->first!=son[x]){
			dfs2(it->first,it->first);
		}
	}
	int posu[100005],posd[100005];
	void dfs3(int x,int p)
	{
		vector<int> v;int i;v.push_back(x);
		while(son[x]){x=son[x];v.push_back(x);}
		if(v.size()>1){
			sam2::init();
			fz1(i,v.size()-1){
				sam2::extend(fc[v[i]]-'a');
				posu[v[i]]=sam2::lst;
			}
			sam2::init();
			fd1(i,v.size()-1){
				sam2::extend(fc[v[i]]-'a');
				posd[v[i-1]]=sam2::lst;
			}
		}
		ff(v,it){
			ff(bi[*it],it2){
				if(it2->first!=son[*it]&&it2->first!=fa[*it]) dfs3(it2->first,x);
			}
		}
	}
	void build()
	{
		int i;fz1(i,n-1){int x,y;read(x);read(y);char c;while(!islower(c=getchar()));bi[x].push_back(make_pair(y,c));bi[y].push_back(make_pair(x,c));}
		dfs1(1,0);dfs2(1,1);dfs3(1,1);
	}
	int lca(int x,int y)
	{
		while(tp[x]!=tp[y]){
			if(dep[tp[x]]>dep[tp[y]]) x=fa[tp[x]]; else y=fa[tp[y]];
		}
		return dep[x]<dep[y]?x:y;
	}
	string getstr(int x,int y)
	{
		string sl,sr;
		while(x!=y){
			if(dep[x]>dep[y]){
				sl.push_back(fc[x]);
				x=fa[x];
			}
			else{
				sr.push_back(fc[y]);
				y=fa[y];
			}
		}
		reverse(sr.begin(),sr.end());
		return sl+sr;
	}
}
namespace sam1
{
	int ch[200005][maxc],fa[200005],l[200005],lst=1,cnt=1;
	vector<int> edi[200005],bi[200005];
	void extend(int c)
	{
		if(ch[lst][c]&&l[ch[lst][c]]==l[lst]+1){lst=ch[lst][c];return;}
		int np=++cnt,p=lst;lst=np;l[np]=l[p]+1;
		for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
		if(!p){fa[np]=1;return;}int q=ch[p][c];if(l[q]==l[p]+1){fa[np]=q;return;}
		int nq=++cnt;l[nq]=l[p]+1;fa[nq]=fa[q];fa[np]=fa[q]=nq;
		memcpy(ch[nq],ch[q],sizeof(ch[nq]));
		for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
	}
	void build(string st,int id){lst=1;int i;fz0k(i,st.size()) extend(st[i]-'a'),edi[lst].push_back(id);}
	int fi[200005],ed[200005],ti;
	struct upd{int y,z;};vector<upd> vu[200005];
	struct qry{int op,l,r;};vector<qry> vq[200005];
	void dfs(int x)
	{
		fi[x]=++ti;ff(bi[x],it)dfs(*it);ed[x]=ti;
//		cerr<<x<<": ";ff(edi[x],it) cerr<<*it<<' ';cerr<<endl;
		ff(edi[x],it)vu[fi[x]].push_back((upd){*it,1});
	}
	void rebuild()
	{
		int i;fz(i,2,cnt) bi[fa[i]].push_back(i);
		dfs(1);
	}
	int seq[200005];bool cmp(int x,int y){return l[x]<l[y];}
	long long f[200005],g[200005];int sc[200005],pos[200005];
	int vis[200005];
	int mp2[200005],ord[200005],cnt2;
	void poufen()
	{
		int i,j;fz1(i,cnt) seq[i]=i;sort(seq+1,seq+cnt+1,cmp);
		fd1(i,cnt){
			int x=seq[i];f[x]=1;
			fz0k(j,maxc)if(ch[x][j]) f[x]+=f[ch[x][j]];
		}
		fz1(i,cnt){
			int x=seq[i];g[x]++;
			fz0k(j,maxc)if(ch[x][j]) g[ch[x][j]]+=g[x];
		}
		fz1(i,cnt){
			int x=seq[i];sc[x]=-1;
			fz0k(j,maxc)if(ch[x][j]&&f[ch[x][j]]*2>=f[x]&&g[x]*2>=g[ch[x][j]]) sc[x]=j;
		}
		fz1(i,cnt){
			int x=seq[i];if(vis[x]) continue;vis[x]=1;
			mp2[ord[x]=++cnt2]=x;
			int y=x;vector<int> v;
			while(sc[y]!=-1){
				v.push_back(y);
				y=ch[y][sc[y]];vis[y]=1;
				mp2[ord[y]=++cnt2]=y;
			}
			if(v.empty()) continue;
			sam2::init();
			while(!v.empty()){
				sam2::extend(sc[v.back()]);
				pos[v.back()]=sam2::lst;
				v.pop_back();
			}
		}
	}
	int cc[200005];
	void shudian()
	{
		int i;fz1(i,ti){
			ff(vu[i],it) for(int x=it->y;x<=m;x+=(x&-x)) cc[x]+=it->z;
			ff(vq[i],it){
				if(it->op>0){
					for(int x=it->r;x;x&=(x-1)) ans[it->op]+=cc[x];
					for(int x=it->l-1;x;x&=(x-1)) ans[it->op]-=cc[x];
				}
				else{
					for(int x=it->r;x;x&=(x-1)) ans[-it->op]-=cc[x];
					for(int x=it->l-1;x;x&=(x-1)) ans[-it->op]+=cc[x];
				}
			}
		}
	}
}
int getpos(int x,int y)
{
	int t=1,i,z=temptree::lca(x,y);
	while(x!=z){
		if(temptree::tp[x]==x||sam1::sc[t]==-1){
			if(sam1::ch[t][temptree::fc[x]-'a']) t=sam1::ch[t][temptree::fc[x]-'a'],x=temptree::fa[x];
			else return 0;
			continue;
		}
		int len=min(sam2::lcp(temptree::posu[x],sam1::pos[t]),temptree::dep[x]-temptree::dep[z]);
		if(len==0){
			if(sam1::ch[t][temptree::fc[x]-'a']) t=sam1::ch[t][temptree::fc[x]-'a'],x=temptree::fa[x];
			else return 0;
			continue;
		}
		x=temptree::mp[temptree::dfn[x]-len];
		t=sam1::mp2[sam1::ord[t]+len];
	}
	vector<int> stk;int yy=y;
	while(temptree::tp[yy]!=temptree::tp[z]){stk.push_back(temptree::tp[yy]);yy=temptree::fa[temptree::tp[yy]];}
	while(z!=y){
		if(!stk.empty()&&z==temptree::fa[stk.back()]){
			int nz=stk.back();
			if(sam1::ch[t][temptree::fc[nz]-'a']) t=sam1::ch[t][temptree::fc[nz]-'a'],z=nz;
			else return 0;
			stk.pop_back();
			continue;
		}
		int len=sam2::lcp(temptree::posd[z],sam1::pos[t]);
		if(!stk.empty()) len=min(len,temptree::dep[stk.back()]-temptree::dep[z]-1);
		else len=min(len,temptree::dep[y]-temptree::dep[z]);
		if(len==0){
			int nz=temptree::mp[temptree::dfn[z]+1];
			if(sam1::ch[t][temptree::fc[nz]-'a']) t=sam1::ch[t][temptree::fc[nz]-'a'],z=nz;
			else return 0;
			continue;
		}
		z=temptree::mp[temptree::dfn[z]+len];
		t=sam1::mp2[sam1::ord[t]+len];
	}
	return t;
}
int main()
{
	read(n);read(m);read(q);temptree::build();
	fz1(i,m) read(st[i]),sam1::build(st[i],i);
	sam1::rebuild();sam1::poufen();
	sam2::rebuild();
	fz1(i,q){
		int x,y,l,r;read(x);read(y);read(l);read(r);
		int t=getpos(x,y);if(t){
			sam1::vq[sam1::ed[t]].push_back((sam1::qry){i,l,r});
			sam1::vq[sam1::fi[t]-1].push_back((sam1::qry){-i,l,r});
		}
	}
	sam1::shudian();
	fz1(i,q) printf("%d\n",ans[i]); 
	return 0;
}