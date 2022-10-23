// The first ac is O(n^2), but data is weak
// O(n log^2)
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
/*#ifndef ONLINE_JUDGE
	FILE *___=freopen("1.in","r",stdin);
#endif*/
/*inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}*/
const int mod=1004535809,e1=189,e2=190;
int n,m,q,i,j,k;
int pw1[200005],pw2[200005];
void init_pow()
{
	int i;pw1[0]=pw2[0]=1;
	fz1(i,200002) pw1[i]=1ll*e1*pw1[i-1]%mod,pw2[i]=1ll*e2*pw2[i-1]%mod;
}
struct strhsh
{
	int h1[200005],h2[200005];
	string st;int len;
	void init(string _)
	{
		st=_;len=st.size()-1;int i;
		fz1(i,len){
			h1[i]=(1ll*h1[i-1]*e1+st[i])%mod;
			h2[i]=(1ll*h2[i-1]*e2+st[i])%mod;
		}
	}
	pair<int,int> calc(int l,int r)
	{
		return make_pair((h1[r]+1ll*(mod-h1[l-1])*pw1[r-l+1])%mod,(h2[r]+1ll*(mod-h2[l-1])*pw2[r-l+1])%mod);
	}
};
int fa[100005],tp[100005],dep[100005],sz[100005],dfn[100005],mp[100005],ti,son[100005];
char fv[100005];
vector<pair<int,char> > bi1[100005];
int px[100005],py[100005],pz[100005],ans[100005];
string st[100005];
void dfs1(int x,int fa)
{
	::fa[x]=fa;sz[x]=1;
	ff(bi1[x],it)if(it->first!=fa){
		dep[it->first]=dep[x]+1;
		fv[it->first]=it->second;
		dfs1(it->first,x);
		sz[x]+=sz[it->first];
		if(sz[it->first]>sz[son[x]]) son[x]=it->first;
	}
}
void dfs2(int x,int t)
{
	mp[dfn[x]=++ti]=x;
	tp[x]=t;if(son[x]) dfs2(son[x],t);
	ff(bi1[x],it)if(it->first!=fa[x]&&it->first!=son[x]){
		dfs2(it->first,it->first);
	}
}
int lca(int x,int y)
{
	while(tp[x]!=tp[y]){
		if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
		x=fa[tp[x]];
	}
	return mp[min(dfn[x],dfn[y])];
}
int gtf(int x,int y)
{
	int d=dep[x]-y;
	while(dep[tp[x]]>d) x=fa[tp[x]];
	return mp[dfn[x]-(dep[x]-d)];
}

// chu'li zhi'shang'zhi'xia de lian
vector<pair<int,int> > vz[100005],vf[100005];
struct acam
{
	int pos[100005],fi[100005],ed[100005],ti;
	int ch[100005][26],fail[100005],cnt=1;
	int c[100005];
	vector<int> bi2[100005];
	void add(int x,int y){while(x<=ti)c[x]+=y,x+=(x&-x);}
	int query(int x){int s=0;while(x)s+=c[x],x-=(x&-x);return s;}
	int query(int l,int r){return query(r)-query(l-1);}
	void ins(string st)
	{
		int x=1,i;
		fz0k(i,st.size()){
			if(!ch[x][st[i]-'a']) ch[x][st[i]-'a']=++cnt;
			x=ch[x][st[i]-'a'];
		}
		pos[::i]=x;
	}
	void dfs2(int x){fi[x]=++ti;ff(bi2[x],it)dfs2(*it);ed[x]=ti;}
	void rebuild()
	{
		queue<int> qx;int i;qx.push(1);
		while(!qx.empty()){
			int x=qx.front();qx.pop();
			fz0k(i,26)if(ch[x][i]){
				fail[ch[x][i]]=(x==1?1:ch[fail[x]][i]);
				qx.push(ch[x][i]);
			}
			else ch[x][i]=(x==1?1:ch[fail[x]][i]);
		}
		fz(i,2,cnt) bi2[fail[i]].push_back(i);
		dfs2(1); 
	}
}az,af;
void dfs3(int x,int fa,int pz,int pf)
{
	az.add(az.fi[pz],1);af.add(af.fi[pf],1);
	ff(vz[x],it) ans[it->first]+=it->second*az.query(az.fi[az.pos[::pz[it->first]]],az.ed[az.pos[::pz[it->first]]]);
	ff(vf[x],it) ans[it->first]+=it->second*af.query(af.fi[af.pos[::pz[it->first]]],af.ed[af.pos[::pz[it->first]]]);
	ff(bi1[x],it)if(it->first!=fa) dfs3(it->first,x,az.ch[pz][it->second-'a'],af.ch[pf][it->second-'a']);
	az.add(az.fi[pz],-1);af.add(af.fi[pf],-1);
}

// ji'suan zui'chang pi'pei de qian'zhui/hou'zhui
vector<int> vq[100005];
int znxt[100005],fnxt[100005];
struct sam
{
	int fa[200005],l[200005],ch[200005][26],ed[200005],cnt,lst;
	char fr[200005];
	vector<int> bi1[200005];
	void init(){while(cnt){bi1[cnt].clear();memset(ch[cnt],0,sizeof(ch[cnt]));cnt--;}cnt=lst=1;fr[1]='%';ed[1]=0;}
	void extend(char c,int id)
	{
		int np=++cnt,p=lst;lst=np;l[np]=l[p]+1;ed[np]=id;fr[np]=c;
		for(;p&&!ch[p][c-'a'];p=fa[p]) ch[p][c-'a']=np;
		if(!p){fa[np]=1;return;}int q=ch[p][c-'a'];
		if(l[p]+1==l[q]){fa[np]=q;return;}int nq=++cnt;ed[nq]=0;fr[nq]=fr[q];
		fa[nq]=fa[q];fa[q]=fa[np]=nq;l[nq]=l[p]+1;
		memcpy(ch[nq],ch[q],sizeof(ch[q]));
		for(;p&&ch[p][c-'a']==q;p=fa[p]) ch[p][c-'a']=nq;
	}
	void dfs0(int x)
	{
		ff(bi1[x],it){
			dfs0(*it);
			if(!ed[x]) ed[x]=ed[*it];
		}
	}
	vector<int> bi2[200005];
	int ord[200005];
	int son[200005],bel[200005],mp[200005],dfn[200005],dfe[200005],ti;
	long long f[200005],g[200005];
	void decomposs()
	{
		int i,j;fz1(i,cnt)ord[i]=i,bi2[i].clear();
		sort(ord+1,ord+cnt+1,[&](int x,int y){return l[x]<l[y];});
		fz1(i,cnt)fz0k(j,26)if(ch[i][j]) bi2[i].push_back(ch[i][j]);
		ti=0;fz1(i,cnt) f[i]=g[i]=son[i]=bel[i]=mp[i]=dfn[i]=dfe[i]=0;
		fz1(i,cnt){
			int x=ord[i];f[x]++;
			ff(bi2[x],it) f[*it]+=f[x];
		}
		fd1(i,cnt){
			int x=ord[i];g[x]=1;
			ff(bi2[x],it) g[x]+=g[*it];
			ff(bi2[x],it) if(f[x]*2>f[*it]&&g[*it]*2>g[x]) son[x]=*it;
		}
		fz1(i,cnt){
			int x=ord[i];if(bel[x])continue;
			for(j=x;j;j=son[j]) bel[mp[dfn[j]=++ti]=j]=x;
			dfe[x]=ti;
		}
	}
	strhsh h;
	void build(string st)
	{
		init();int i;fz1(i,st.size()-1) extend(st[i],i);
		fz(i,2,cnt) bi1[fa[i]].push_back(i);
		dfs0(1);
		decomposs();
		string tmp=" ";
		fz1(i,ti) tmp+=fr[mp[i]];
		h.init(tmp);
	}
}dz,df;
strhsh hz,hf;
int len;
struct border_tree
{
	int len,fa[100005];
	vector<int> bi[100005];
	int tp[100005],dep[100005],sz[100005],dfn[100005],dfe[100005],mp[100005],ti,son[100005];
	void dfs1(int x)
	{
		sz[x]=1;son[x]=0;
		ff(bi[x],it){
			dep[*it]=dep[x]+1;dfs1(*it);
			sz[x]+=sz[*it];
			if(sz[*it]>sz[son[x]]) son[x]=*it;
		}
	}
	void dfs2(int x,int t)
	{
		mp[dfn[x]=++ti]=x;tp[x]=t;if(son[x]) dfs2(son[x],t);
		ff(bi[x],it)if(*it!=son[x]) dfs2(*it,*it);
		dfe[x]=ti;
	}
	void build(int _,int *a)
	{
		len=_;int i;fz1(i,len) fa[i]=a[i];
		fz0g(i,len) bi[i].clear();fz1(i,len) bi[fa[i]].push_back(i);
		ti=0;dfs1(0);dfs2(0,0);
	}
	int query(int x,int lim)
	{
		while(tp[x]>lim) x=fa[tp[x]];
		int l=dfn[tp[x]]+1,r=dfn[x]+1,res=tp[x],mid;
		while(l<r){
			mid=(l+r)/2;
			if(mp[mid]<=lim) l=mid+1,res=mp[mid];
			else r=mid;
		}
		return res;
	}
}tz,tf;
int calc(strhsh &a,strhsh &b,int x,int y,int len)
{
	int i;for(i=0;i<10&&i<len;i++) if(a.st[x+i]!=b.st[y+i])break;
	if(i<10) return i;
	int ans=i,l=i+1,r=len+1,mid;
	while(l<r){
		mid=(l+r)/2;
		if(a.calc(x,x+mid-1)==b.calc(y,y+mid-1)) l=mid+1,ans=mid;
		else r=mid;
	}
	return ans;
}
int transform_left(int x,int lim)
{
/*	// bf:
	vector<char> v;
	int p=1,ml=0;
	while(x!=lim) v.push_back(fv[x]),x=fa[x];
	reverse(v.begin(),v.end());
	ff(v,it){
		if(df.ch[p][*it-'a']) p=df.ch[p][*it-'a'],ml++;
		else break;
	}*/
	
	int p=1,ml=0;
	vector<int> vtp;
	int y=x;while(tp[y]!=tp[lim]) vtp.push_back(tp[y]),y=fa[tp[y]];
	for(y=lim;y!=x;){
		if(!vtp.empty()&&fa[vtp.back()]==y){
			int ny=vtp.back();vtp.pop_back();
			if(df.ch[p][fv[ny]-'a']) p=df.ch[p][fv[ny]-'a'],ml++; else break;
			y=ny;continue;
		}
		int lcp=df.dfe[df.bel[p]]-df.dfn[p];
		lcp=min(lcp,vtp.empty()?dep[x]-dep[y]:dep[fa[vtp.back()]]-dep[y]);
		lcp=calc(hz,df.h,dfn[y]+1,df.dfn[p]+1,lcp);
		if(lcp==0){
			int ny=mp[dfn[y]+1];
			if(df.ch[p][fv[ny]-'a']) p=df.ch[p][fv[ny]-'a'],ml++; else break;
			y=ny;continue;
		}
		y=mp[dfn[y]+lcp];p=df.mp[df.dfn[p]+lcp];ml+=lcp;
	}

	int l=len-df.ed[p]+1,r=l+ml-1;
	return tz.query(r,ml);
}
int transform_right(int x,int lim)
{
/*	// bf:
	vector<char> v;
	int p=1,ml=0;
	while(x!=lim) v.push_back(fv[x]),x=fa[x];
	reverse(v.begin(),v.end());
	ff(v,it){
		if(dz.ch[p][*it-'a']) p=dz.ch[p][*it-'a'],ml++;
		else break;
	}*/

	int p=1,ml=0;
	vector<int> vtp;
	int y=x;while(tp[y]!=tp[lim]) vtp.push_back(tp[y]),y=fa[tp[y]];
	for(y=lim;y!=x;){
		if(!vtp.empty()&&fa[vtp.back()]==y){
			int ny=vtp.back();vtp.pop_back();
			if(dz.ch[p][fv[ny]-'a']) p=dz.ch[p][fv[ny]-'a'],ml++; else break;
			y=ny;continue;
		}
		int lcp=dz.dfe[dz.bel[p]]-dz.dfn[p];
		lcp=min(lcp,vtp.empty()?dep[x]-dep[y]:dep[fa[vtp.back()]]-dep[y]);
		lcp=calc(hz,dz.h,dfn[y]+1,dz.dfn[p]+1,lcp);
		if(lcp==0){
			int ny=mp[dfn[y]+1];
			if(dz.ch[p][fv[ny]-'a']) p=dz.ch[p][fv[ny]-'a'],ml++; else break;
			y=ny;continue;
		}
		y=mp[dfn[y]+lcp];p=dz.mp[dz.dfn[p]+lcp];ml+=lcp;
	}

	int r=dz.ed[p],l=r-ml+1;
	return tf.query(len-l+1,ml);
}

// er'wei shu'dian he'bing border lian
vector<pair<int,int> > tq[100005];
struct bit
{
	int len,a[100005];
	void init(int _){len=_+1;int i;fz1(i,len)a[i]=0;}
	void add(int x,int c){while(x<=len) a[x]+=c,x+=(x&-x);}
	void add(int l,int r,int c){add(l,c);add(r+1,-c);}
	int query(int x){int s=0;while(x) s+=a[x],x-=(x&-x);return s;}
}bt;
void dfs4(int x)
{
	bt.add(tf.dfn[len-x],tf.dfe[len-x],1);
	ff(tq[x],it) ans[it->first]+=bt.query(tf.dfn[it->second]);
	ff(tz.bi[x],it) dfs4(*it);
	bt.add(tf.dfn[len-x],tf.dfe[len-x],-1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	init_pow();
	cin>>n>>m>>q;
	fz1(i,n-1){
		int x,y;char c;cin>>x>>y>>c;
		bi1[x].push_back(make_pair(y,c));
		bi1[y].push_back(make_pair(x,c));
	}
	fz1(i,m){
		cin>>st[i];
		az.ins(st[i]);reverse(st[i].begin(),st[i].end());
		af.ins(st[i]);reverse(st[i].begin(),st[i].end());
	}
	az.rebuild();af.rebuild();
	dfs1(1,0);dfs2(1,1);
	string tmp=" ";fv[1]='^';
	fz1(i,ti) tmp.push_back(fv[mp[i]]);
	hz.init(tmp);reverse(tmp.begin()+1,tmp.end());hf.init(tmp);
	fz1(i,q){
		cin>>px[i]>>py[i]>>pz[i];
		int z=lca(px[i],py[i]);
		if(dep[px[i]]-dep[z]>=st[pz[i]].size()){
			vf[px[i]].push_back(make_pair(i,1));
			vf[px[i]=gtf(px[i],dep[px[i]]-dep[z]-st[pz[i]].size()+1)].push_back(make_pair(i,-1));
		}
		if(dep[py[i]]-dep[z]>=st[pz[i]].size()){
			vz[py[i]].push_back(make_pair(i,1));
			vz[py[i]=gtf(py[i],dep[py[i]]-dep[z]-st[pz[i]].size()+1)].push_back(make_pair(i,-1));
		}
		vq[pz[i]].push_back(i);
	}
	dfs3(1,0,1,1);

	fz1(i,m)if(!vq[i].empty()){
		len=st[i].size();st[i]=" "+st[i];
		dz.build(st[i]);
		znxt[1]=k=0;
		fz(j,2,len){
			while(k&&st[i][j]!=st[i][k+1]) k=znxt[k];
			if(st[i][j]==st[i][k+1])k++;znxt[j]=k;
		}
		tz.build(len,znxt);
		reverse(st[i].begin()+1,st[i].end());

		df.build(st[i]);
		fnxt[1]=k=0;
		fz(j,2,len){
			while(k&&st[i][j]!=st[i][k+1]) k=fnxt[k];
			if(st[i][j]==st[i][k+1])k++;fnxt[j]=k;
		}
		tf.build(len,fnxt);
		reverse(st[i].begin()+1,st[i].end());

		fz0g(j,len) tq[j].clear();bt.init(len);
		ff(vq[i],it){
			int z=lca(px[*it],py[*it]);
			int sl=transform_left(px[*it],z);
			int sr=transform_right(py[*it],z);
			tq[sl].push_back(make_pair(*it,sr));
		}
		dfs4(0);
	}

	fz1(i,q) printf("%d\n",ans[i]);
	return 0;
}