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
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int t,n,q,c0,i,j,a[300005],b[300005],s[300005],lg[300005],qx[300005];
vector<int> all;
int pt[600005];
pair<int,int> f[19][300005];
pair<int,int> query(int l,int r)
{
	int t=lg[r-l+1];
	return max(f[t][l],f[t][r-(1<<t)+1]);
}
int lc[300005],rc[300005],fa[300005],vis[300005];
int build(int l,int r)
{
	int x=query(l,r).second;
	if(l<x) fa[lc[x]=build(l,x-1)]=x;
	if(x<r) fa[rc[x]=build(x+1,r)]=x;
	return x;
}
vector<pair<int,int > > rg;
bool flg;
int pl[300005],pr[300005];
int ordl[300005],ordr[300005],posr[300005],posr2[300005];
vector<int> vl[600005];
bool cmpl(int x,int y){return pl[x]<pl[y];}
bool cmpr(int x,int y){return pr[x]<pr[y];}
void dfs(int x,int lim)
{
	if(b[x]){
		if(b[x]>lim) flg=0;
		lim=min(lim,b[x]);
	}
	else{
		int l=vis[x]?lower_bound(all.begin(),all.end(),vis[x])-all.begin()+1:1;
		int r=upper_bound(all.begin(),all.end(),lim)-all.begin();
		if(l>r) flg=0;
		pl[x]=l;pr[x]=r;
	}
	if(lc[x]) dfs(lc[x],lim);
	if(rc[x]) dfs(rc[x],lim);
}
namespace seg
{
	struct nd{int mi,pos;}tr[2097155];
	nd merge(nd x,nd y){return make_pair(x.mi,x.pos)<make_pair(y.mi,y.pos)?x:y;}
	nd operator +(nd x,int y){x.mi+=y;return x;}
	int num,tag[2097155];
	void build(int n)
	{
		num=1;while(num<=n+1) num<<=1;int i;
		fz0k(i,num) tr[num+i].mi=0x3f3f3f3f;
		fd1(i,num-1) tag[i]=0,tr[i]=merge(tr[i+i],tr[i+i+1])+tag[i];
	}
	void insert(int x,int y,int z)
	{
		x+=num;tr[x].mi-=0x3f3f3f3f;
		tr[x].mi+=y;tr[x].pos=z;
		while(x>>=1) tr[x]=merge(tr[x+x],tr[x+x+1])+tag[x];
	}
	void update(int l,int r,int c)
	{
		l+=num-1;r+=num+1;
		while(l+1<r){
			if(!(l&1)) tr[l^1]=tr[l^1]+c,tag[l^1]+=c;
			if(r&1) tr[r^1]=tr[r^1]+c,tag[r^1]+=c;
			l>>=1;tr[l]=merge(tr[l+l],tr[l+l+1])+tag[l];
			r>>=1;tr[r]=merge(tr[r+r],tr[r+r+1])+tag[r];
		}
		while(l>>=1) tr[l]=merge(tr[l+l],tr[l+l+1])+tag[l];
		while(r>>=1) tr[r]=merge(tr[r+r],tr[r+r+1])+tag[r];
	}
	nd query(int l,int r)
	{
		l+=num-1;r+=num+1;
		nd sl=(nd){0x3fffffff,0},sr=(nd){0x3fffffff,0};
		while(l+1<r){
			if(!(l&1)) sl=merge(sl,tr[l^1]);
			if(r&1) sr=merge(sr,tr[r^1]);
			l>>=1;sl=sl+tag[l];
			r>>=1;sr=sr+tag[r];
		}
		while(l>>=1) sl=sl+tag[l];
		while(r>>=1) sr=sr+tag[r];
		sl=merge(sl,sr);
		return sl;
	}
}
void solve()
{
	read(n);read(q);fz1(i,n)read(a[i]),f[0][i]=make_pair(a[i],i);
	fz1(j,18)fz1(i,n-(1<<j)+1) f[j][i]=max(f[j-1][i],f[j-1][i+(1<<(j-1))]);
	all.clear();c0=0;
	fz1(i,n){read(b[i]);if(!b[i]) c0++;}
	fz1(i,c0-1) read(s[i]),all.push_back(s[i]);
	fz1(i,q){read(qx[i]);all.push_back(qx[i]);}
	sort(all.begin(),all.end());all.resize(unique(all.begin(),all.end())-all.begin());
	fz0g(i,all.size()+1){
		pt[i]=0;vl[i].clear();
	}
	fz1(i,n) lc[i]=rc[i]=fa[i]=vis[i]=0;
	int rt=build(1,n);
	vector<pair<int,int> > ord;
	fz1(i,n) if(b[i]) ord.push_back(make_pair(b[i],i));
	sort(ord.begin(),ord.end());reverse(ord.begin(),ord.end());
	int cur=0;
	ff(ord,it){
		int x=it->second;
		while(x&&!vis[x]){
			if(b[x]>it->first){
				fz1(i,q) puts("NO");
				return;
			}
			if(!b[x]) cur++;
			vis[x]=it->first;x=fa[x];
		}
	}
	flg=1;rg.clear();
	dfs(rt,0x3f3f3f3f);
	if(flg==0){
		fz1(i,q) puts("NO");
		return;
	}
	fz1(i,c0-1) pt[upper_bound(all.begin(),all.end(),s[i])-all.begin()]++;
	int sl=0,sr=all.size()+1;
	fz1(i,n) ordl[i]=ordr[i]=i;
	sort(ordl+1,ordl+n+1,cmpl);
	sort(ordr+1,ordr+n+1,cmpr);
	fz1(i,n) if(!b[i]) vl[pl[i]].push_back(i);
	fz1(i,n) posr[ordr[i]]=i;
	fz1(i,n){
		if(i>1&&pr[ordr[i-1]]==pr[ordr[i]]){
			posr2[ordr[i]]=posr2[ordr[i-1]];
		}
		else posr2[ordr[i]]=posr[ordr[i]];
	}
//	fz1(i,n) if(!b[i]) cerr<<i<<' '<<pl[i]<<' '<<pr[i]<<' '<<posr[i]<<' '<<posr2[i]<<endl;
	seg::build(n);
	fd1(i,all.size()){
		seg::update(1,n,pt[i]);
		pt[i]+=pt[i+1];
		ff(vl[i],it){
			seg::insert(posr[*it],-pt[pr[*it]+1],pr[*it]);
			seg::update(posr2[*it],n,-1);
		}
		seg::nd tmp=seg::query(1,n);
		if(tmp.mi<-1){
			fz1(i,q) puts("NO");
			return;
		}
		if(tmp.mi==-1){
			sl=max(sl,i);
			sr=min(sr,tmp.pos);
		}
	}
	fz1(i,q){
		int y=upper_bound(all.begin(),all.end(),qx[i])-all.begin();
		if(sl<=y&&y<=sr) puts("YES"); else puts("NO");
	}
}
int main()
{
	fz(i,2,300002) lg[i]=lg[i>>1]+1;
	read(t);
	while(t--){
		solve();
	}
	return 0;
}