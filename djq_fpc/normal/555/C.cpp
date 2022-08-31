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
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
#define incm(x,y) {x=((x)+(y))%mod;}
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
inline void read(char &c)
{
	while(!isupper(c=getchar()));
}
int n,m,i,j,px[200005],py[200005],op[200005];
vector<int> allx,ally;
struct segt
{
	int mx[800005],tag[800005];
	void pushup(int x)
	{
		mx[x]=max(mx[x+x],mx[x+x+1]);
	}
	void upd(int x,int y)
	{
		mx[x]=max(mx[x],y);
		tag[x]=max(tag[x],y);
	}
	void pushdo(int x)
	{
		if(tag[x]){
			upd(x+x,tag[x]);upd(x+x+1,tag[x]);
			tag[x]=0;
		}
	}
	void update(int x,int l,int r,int ql,int qr,int c)
	{
		if(ql<=l&&r<=qr){
			upd(x,c);return;
		}
		pushdo(x);int mid=(l+r)/2;
		if(ql<=mid)update(x+x,l,mid,ql,qr,c);
		if(qr>mid)update(x+x+1,mid+1,r,ql,qr,c);
		pushup(x);
	}
	int query(int x,int l,int r,int ql,int qr)
	{
		if(ql<=l&&r<=qr){
			return mx[x];
		}
		int mid=(l+r)/2;pushdo(x);
		if(qr<=mid)return query(x+x,l,mid,ql,qr);
		if(ql>mid)return query(x+x+1,mid+1,r,ql,qr);
		return max(query(x+x,l,mid,ql,qr),query(x+x+1,mid+1,r,ql,qr));
	}
}tr1,tr2;
int main()
{
	read(n);read(m);
	fz1(i,m){
		read(px[i]);read(py[i]);char c;read(c);
		op[i]=(c=='L');
		allx.push_back(px[i]);ally.push_back(py[i]);
	}
	sort(allx.begin(),allx.end());allx.resize(unique(allx.begin(),allx.end())-allx.begin());
	sort(ally.begin(),ally.end());ally.resize(unique(ally.begin(),ally.end())-ally.begin());
	fz1(i,m){
		int x=upper_bound(allx.begin(),allx.end(),px[i])-allx.begin();
		int y=upper_bound(ally.begin(),ally.end(),py[i])-ally.begin();
		if(op[i]){
			int t=tr2.query(1,1,m,y,y)+1;
			printf("%d\n",allx[x-1]-(t==1?0:allx[t-2]));
			tr2.update(1,1,m,y,y,x);
			if(t<=x) tr1.update(1,1,m,t,x,y);
		}
		else{
			int t=tr1.query(1,1,m,x,x)+1;
			printf("%d\n",ally[y-1]-(t==1?0:ally[t-2]));
			tr1.update(1,1,m,x,x,y);
			if(t<=y) tr2.update(1,1,m,t,y,x);
		}
	}
	return 0;
}