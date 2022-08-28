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
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,q,i,j,cur;
vector<unsigned long long> all;
unsigned long long a[200005],op[200005],b[200005];
struct bit
{
	int b[400005];
	unsigned long long a[400005];
	void add(int x,int y)
	{
		unsigned long long t=y*all[x-1];
		while(x<=m){
			a[x]+=t;
			b[x]+=y;
			x+=(x&-x);
		}
	}
	unsigned long long query1(int x)
	{
		unsigned long long s=0;
		while(x){
			s+=a[x];
			x-=(x&-x);
		}
		return s;
	}
	int query0(int x)
	{
		int s=0;
		while(x){
			s+=b[x];
			x-=(x&-x);
		}
		return s;
	}
	int kth(int x)
	{
		int s=0,i;
		for(i=18;i>=0;i--){
			if(s+(1<<i)>m) continue;
			if(b[s+(1<<i)]<x){
				x-=b[s+(1<<i)];
				s+=(1<<i);
			}
		}
		return s+1;
	}
}tr1;
struct nd
{
	unsigned long long s1,s2;
	int sz;
};
struct seg
{
	nd s[1600005];
	nd merge(nd x,nd y)
	{
		nd z;
		z.sz=x.sz+y.sz;
		z.s1=x.s1+y.s1;
		z.s2=x.s2+y.s2+y.s1*(unsigned long long)x.sz;
		return z;
	}
	void pushup(int x)
	{
		s[x]=merge(s[x+x],s[x+x+1]);
	}
	void update(int x,int l,int r,int y,int c)
	{
		if(l==r){
			s[x].s1+=((unsigned long long)c)*all[l-1];
			s[x].s2+=((unsigned long long)c)*all[l-1];
			s[x].sz+=c;
			return;
		}
		int mid=(l+r)/2;
		if(y<=mid)update(x+x,l,mid,y,c);
		else update(x+x+1,mid+1,r,y,c);
		pushup(x);
	}
	nd query(int x,int l,int r,int ql,int qr)
	{
		if(ql<=l&&r<=qr) return s[x];
		int mid=(l+r)/2;
		if(qr<=mid) return query(x+x,l,mid,ql,qr);
		if(ql>mid) return query(x+x+1,mid+1,r,ql,qr);
		return merge(query(x+x,l,mid,ql,qr),query(x+x+1,mid+1,r,ql,qr));
	}
}tr2;
void ins(int x)
{
	cur++;
	tr1.add(x,1);
	tr2.update(1,1,m,x,1);
}
void del(int x)
{
	cur--;
	tr1.add(x,-1);
	tr2.update(1,1,m,x,-1);
}
unsigned long long gsum1(int r)
{
	if(r==0) return 0;
	if(r==cur) return tr1.query1(m);
	int t=tr1.kth(r);
	unsigned long long s1=tr1.query1(t),s0=tr1.query0(t);
	return s1-(s0-r)*all[t-1];
}
unsigned long long gsum1(int l,int r)
{
	return gsum1(r)-gsum1(l-1);
}
unsigned long long c2(unsigned long long x)
{
	unsigned long long y=x+1;
	if(x%2==0)x/=2;else y/=2;
	return x*y;
}
unsigned long long gsuml(int len)
{
	if(len==0) return 0;
	int t=tr1.kth(len);
	nd s=tr2.query(1,1,m,1,t);
	return s.s2-(c2(s.sz)-c2(len))*all[t-1]-(s.s1-(s.sz-len)*all[t-1])*(len+1);
}
unsigned long long gsumr(int len)
{
	if(len==0) return 0;
	int t=tr1.kth(cur-len);
	nd s=tr2.query(1,1,m,t,m);
	unsigned long long res=s.s2-(c2(s.sz-len))*all[t-1]-(s.s1-(s.sz-len)*all[t-1])*(s.sz-len);
	return res;
}
void query()
{
	if(cur<=1){
		puts("0");
		return;
	}
	unsigned long long ans=tr2.s[1].s2*2;
	int s=0,l=0,r=cur/2+1,mid;
	while(l<r){
		mid=(l+r)/2;
		unsigned long long sl=gsum1(1,mid+1);
		unsigned long long sr=gsum1(cur-mid+1,cur);
		if(sl>=sr){
			s=mid;
			l=mid+1;
		}
		else r=mid;
	}
	ans+=gsuml(s+1);
	ans+=gsumr(s);
	s=cur,l=cur/2,r=cur-1,mid;
	while(l<r){
		mid=(l+r+1)/2;
		unsigned long long sl=gsum1(1,mid+1);
		unsigned long long sr=gsum1(cur-mid+1,cur);
		if(sl>=sr){
			s=mid;
			r=mid-1;
		}
		else l=mid;
	}
	ans-=gsuml(s);
	ans-=gsumr(s-1);
	ans-=tr2.s[1].s1*(cur+1);
	printf("%I64u\n",ans);
}
int main()
{
	scanf("%d%d",&n,&q);
	fz1(i,n){
		scanf("%I64u",&a[i]);
		all.push_back(a[i]);
	}
	fz1(i,q){
		scanf("%d%I64u",&op[i],&b[i]);
		all.push_back(b[i]);
	}
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	m=all.size();
	fz1(i,n){
		ins(upper_bound(all.begin(),all.end(),a[i])-all.begin());
	}
	query();
	fz1(i,q){ 
		if(op[i]==1) ins(upper_bound(all.begin(),all.end(),b[i])-all.begin()); else del(upper_bound(all.begin(),all.end(),b[i])-all.begin());
		query();
	}
	return 0;
}