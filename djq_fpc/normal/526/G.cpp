//My rating is 1064.
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
const int BUF_SIZ=1<<18;
char ibuf[BUF_SIZ],*iS=ibuf,*iT=ibuf;
#define getchar() (iS==iT&&(iT=(iS=ibuf)+fread(ibuf,1,BUF_SIZ,stdin)),iS==iT?EOF:*iS++)
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
int n,q,i,j,v;
long long d,mx;int mxd,sx,sy;
long long ans,lst;
int hd[500005],nxt[1000005],to[1000005],w[1000005];
vector<pair<int,int> > bi[500005];
void dfs(int x,int fa,long long dis){if(dis>mx){mx=dis;mxd=x;}ff(bi[x],it)if(it->first!=fa)dfs(it->first,x,dis+it->second);}
struct tree
{
	int rt,fa2[500005],dep[500005],son[500005],ord[500005],rk[500005],lf[500005];
	int tp[500005];int 
	long long dis[500005],len[500005],f[500005],sum[500005];
	int seq[500005],ti;
	int mi[19][500005],fa[19][500005];
	void dfs(int x,int faa)
	{
		seq[++ti]=x;
		int i;fa2[x]=faa;
		ff(bi[x],it)if(it->first!=faa){
			dfs(it->first,x);
		}
	}
/*	void dfs1(int x,int faa)
	{
		fa[x][0]=faa;lf[x]=x;
		for(int i=hd[x];i;i=nxt[i])if(it->first!=faa){
			dep[it->first]=dep[x]+1;dis[it->first]=dis[x]+it->second;dfs1(it->first,x);
			if(!son[x]||len[it->first]+it->second>len[x]) len[x]=len[it->first]+it->second,son[x]=it->first,lf[x]=lf[it->first];
		}
	}
	void dfs2(int x,int fa,int t)
	{
		tp[x]=t;
		for(int i=hd[x];i;i=nxt[i])if(it->first!=fa){
			if(it->first==son[x]){
				f[son[x]]=dis[son[x]]-dis[x]+f[x],f[x]=0,dfs2(it->first,x,t);
			}
			else{
				f[it->first]=it->second;dfs2(it->first,x,it->first);
			}
		}
	}*/
	pair<long long,int> tmp[500005];
	void build()
	{
		int i,j;
/*		dfs1(rt,0);
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
		dfs2(rt,0,rt);*/
		dfs(rt,0);
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
		fz1(i,n)fa[0][i]=fa2[i];
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
		
		fz1(i,ti){
			int x=seq[i];
			ff(bi[x],it)if(it->first!=fa2[x]){
				dep[it->first]=dep[x]+1;dis[it->first]=dis[x]+it->second;
			}
		}
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
		
		fd1(i,ti){
			int x=seq[i];
			lf[x]=x;
			ff(bi[x],it)if(it->first!=fa2[x]){
				if(!son[x]||len[it->first]+it->second>len[x]) len[x]=len[it->first]+it->second,son[x]=it->first,lf[x]=lf[it->first];
			}
		}
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
		
		tp[1]=1;
		fz1(i,ti){
			int x=seq[i];
			ff(bi[x],it)if(it->first!=fa2[x]){
				if(it->first==son[x]){
					f[son[x]]=dis[son[x]]-dis[x]+f[x],f[x]=0,tp[it->first]=tp[x];
				}
				else{
					f[it->first]=it->second;tp[it->first]=it->first;
				}
			}
		}
		
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
		fz1(i,n)tmp[i]=make_pair(-f[i],i);sort(tmp+1,tmp+n+1);
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
		fz1(i,n)ord[i]=tmp[i].second;fz1(i,n)rk[ord[i]]=i;
		fz1(i,n)sum[i]=sum[i-1]+f[ord[i]];
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
		fz1(i,n)mi[0][i]=rk[lf[i]];
		fz1(j,18)fz1(i,n){
			fa[j][i]=fa[j-1][fa[j-1][i]];
			mi[j][i]=min(mi[j-1][i],mi[j-1][fa[j-1][i]]);
		}
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	}
	long long query(int x,int k)
	{
		k=k*2-1;k=min(k,n);if(rk[lf[x]]<=k) return sum[k];
		int i;long long cur=dis[lf[x]];
		fd0g(i,18){
			if(fa[i][x]&&mi[i][x]>k) x=fa[i][x];
		}
		cur-=dis[x];
		return cur+max(sum[k-1],sum[k]-(dis[lf[x]]-dis[x]));
	}
}tx,ty;
int main()
{
//	freopen("bomb.in","r",stdin);
//	freopen("bomb.out","w",stdout);
	read(n);read(q);
	if(n==1){while(q--){puts("0");}return 0;}
	fz1(i,n-1){int x,y,z;read(x);read(y);read(z);bi[x].push_back(make_pair(y,z)),bi[y].push_back(make_pair(x,z));}
	mx=mxd=-1;dfs(1,0,0);sx=mxd;mx=-1;dfs(sx,0,0);sy=mxd;
	tx.rt=sx;ty.rt=sy;tx.build();ty.build();
	while(q--){
		int k;read(v);read(k);
		v=(v+lst-1+n)%n+1;
		k=(k+lst-1+n)%n+1;
		printf("%lld\n",lst=max(tx.query(v,k),ty.query(v,k)));
	}
	return 0;
}