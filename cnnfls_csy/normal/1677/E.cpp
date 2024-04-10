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
int n,m,i,j,a[250005],pos[250005];
long long ans[1000005];
int lg[250005],f[19][250005];
vector<int> d[250005];
int gmx(int x,int y){return a[x]<a[y]?y:x;}
int qry(int l,int r)
{
	int t=lg[r-l+1];
	return gmx(f[t][l],f[t][r-(1<<t)+1]);
}
struct evt
{
	int l,r,v,op;
}b[20000005];int cnt;
vector<int> ve[250005];
vector<int> vq[250005];
void solve(int l,int r)
{
	if(l>r) return;
	int p=qry(l,r);
	ff(d[a[p]],it){
		int p1=pos[*it],p2=pos[a[p]/(*it)];
		int sl=min(min(p1,p2),p),sr=max(max(p1,p2),p);
		if(sl<l||sr>r) continue;
//		cerr<<l<<' '<<sl<<' '<<sr<<' '<<r<<endl;
		b[++cnt]=(evt){sr,r,1,0};ve[l].push_back(cnt);
		b[++cnt]=(evt){sr,r,-1,0};ve[sl+1].push_back(cnt);
	}
	solve(l,p-1);solve(p+1,r);
}
int mi[1000005],num[1000005];
long long res[1000005];
int len[1000005],tag1[1000005],tag2[1000005];
void build(int x,int l,int r)
{
	mi[x]=0;num[x]=len[x]=r-l+1;if(l==r)return;int mid=(l+r)/2;
	build(x+x,l,mid);build(x+x+1,mid+1,r);
}
void upd1(int x,int c)
{
	mi[x]+=c;;tag1[x]+=c;
}
void upd2(int x,int c)
{
	tag2[x]+=c;res[x]+=1ll*c*num[x];
}
void pushdo(int x)
{
	if(tag1[x]){upd1(x+x,tag1[x]);upd1(x+x+1,tag1[x]);tag1[x]=0;}
	if(tag2[x]){if(mi[x+x]==mi[x]) upd2(x+x,tag2[x]);if(mi[x+x+1]==mi[x]) upd2(x+x+1,tag2[x]);tag2[x]=0;}
}
void pushup(int x)
{
	mi[x]=min(mi[x+x],mi[x+x+1]);
	num[x]=(mi[x]==mi[x+x]?num[x+x]:0)+(mi[x]==mi[x+x+1]?num[x+x+1]:0);
}
void update(int x,int l,int r,int ql,int qr,int c)
{
	if(ql<=l&&r<=qr){upd1(x,c);return;}int mid=(l+r)/2;pushdo(x);
	if(ql<=mid) update(x+x,l,mid,ql,qr,c);if(qr>mid) update(x+x+1,mid+1,r,ql,qr,c);
	pushup(x);
}
long long query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr) return res[x];int mid=(l+r)/2;pushdo(x);
	if(qr<=mid) return query(x+x,l,mid,ql,qr);
	if(ql>mid) return query(x+x+1,mid+1,r,ql,qr);
	return query(x+x,l,mid,ql,qr)+query(x+x+1,mid+1,r,ql,qr);
}
int main()
{
//	cerr<<sizeof(b)/1048576<<endl;
	fz(i,2,250002) lg[i]=lg[i/2]+1;
	read(n);read(m);fz1(i,n) read(a[i]),pos[a[i]]=i,f[0][i]=i;
	fz1(i,n) fz(j,i+1,n/i) d[i*j].push_back(i);
	fz1(j,18)fz1(i,n-(1<<j)+1) f[j][i]=gmx(f[j-1][i],f[j-1][i+(1<<(j-1))]);
	solve(1,n);
	fz1(i,m){
		int l,r;read(l);read(r);
		b[++cnt]=(evt){l,r,-1,i};vq[l-1].push_back(cnt);
		b[++cnt]=(evt){l,r,1,i};vq[r].push_back(cnt);
	}
	build(1,1,n);
	fz1(i,n){
		ff(ve[i],it) update(1,1,n,b[*it].l,b[*it].r,b[*it].v);
		if(!mi[1]) upd2(1,1);
		ff(vq[i],it) ans[b[*it].op]+=b[*it].v*(1ll*(b[*it].r-b[*it].l+1)*i-query(1,1,n,b[*it].l,b[*it].r));
	}
	fz1(i,m) printf("%lld\n",ans[i]);
	return 0;
}